#include <stdbool.h>
#include <stdio.h>
#include "include/audio_api.h"
#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio.h"

ma_engine engine;

ma_sound sound;

AUDIO_API int Startup()
{
  ma_result result = ma_engine_init(NULL, &engine);

  if (result != MA_SUCCESS)
  {
    printf("Failed to initialize audio engine.\n");
    return false;
  }

  return true;
}

AUDIO_API void SetGlobalVolume(float value)
{
  ma_engine_set_volume(&engine, value);
}

AUDIO_API SoundGroup *SoundGroupCreate(SoundGroup *parent)
{
  ma_sound_group *soundGroup = ma_malloc(sizeof(ma_sound_group), NULL);

  if (ma_sound_group_init(&engine, 0, (ma_sound_group *)parent, soundGroup))
  {
    ma_free(soundGroup, NULL);
    return NULL;
  }

  return (SoundGroup *)soundGroup;
}

AUDIO_API void SoundGroupSetVolume(SoundGroup *soundGroup, float value)
{
  ma_sound_group_set_volume((ma_sound_group *)soundGroup, value);
}

AUDIO_API float SoundGroupGetVolume(SoundGroup *soundGroup)
{
  return ma_sound_group_get_volume((ma_sound_group *)soundGroup);
}

AUDIO_API void SoundGroupDestroy(SoundGroup *soundGroup)
{
  ma_sound_group_uninit((ma_sound_group *)soundGroup);
  ma_free((ma_sound_group *)soundGroup, NULL);
}

AUDIO_API Sound *SoundCreate(const char *audioFilePath, SoundFlags flags, SoundGroup *soundGroup)
{
  ma_sound *sound = ma_malloc(sizeof(ma_sound), NULL);

  ma_result init_result = ma_sound_init_from_file(&engine, audioFilePath, flags, (ma_sound_group *)soundGroup, NULL, sound);
  printf("Size of ma_sound %zu\n", sizeof(ma_sound));

  if (init_result != MA_SUCCESS)
  {
    printf("Unable to load %s\n", audioFilePath);
  }

  return (Sound *)sound;
}

AUDIO_API float SoundGetVolume(Sound *sound)
{
  return ma_sound_get_volume((ma_sound *)sound);
}

AUDIO_API void SoundSetVolume(Sound *sound, float value)
{
  ma_sound_set_volume((ma_sound *)sound, value);
}

AUDIO_API int SoundPlay(Sound *sound)
{
  ma_result play_result = ma_sound_start((ma_sound *)sound);
  if (play_result != MA_SUCCESS)
  {
    printf("Failed to play\n");
    return false;
  }

  return true;
}

AUDIO_API void SoundDestroy(Sound *sound)
{
  if (sound != NULL)
  {
    ma_sound_uninit((ma_sound *)sound);
    ma_free(sound, NULL);
  }
}

AUDIO_API void Dispose()
{
  ma_engine_uninit(&engine);
}
