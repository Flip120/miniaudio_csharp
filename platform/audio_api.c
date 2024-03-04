#include <stdio.h>
#include "audio_api.h"
#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio.h"

ma_engine engine;

AudioState fsState;

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

AUDIO_API SoundHandle LoadSound(const char *audioFilePath)
{
  SoundHandle soundHandle;

  ma_result init_result = ma_sound_init_from_file(&engine, audioFilePath, 0, NULL, NULL, soundHandle.pSound);
  printf("Size of ma_sound %lu\n", sizeof(ma_sound));

  if (init_result != MA_SUCCESS)
  {
    printf("Unable to load %s\n", audioFilePath);
    soundHandle.pSound = NULL;
  }

  return soundHandle;
}

AUDIO_API void UnloadSound(SoundHandle* handle)
{
  if(handle->pSound != NULL)
  {
    ma_sound_uninit(handle->pSound);
    handle->pSound = NULL;
  }
}

AUDIO_API int Play(SoundHandle soundHandle)
{
  ma_result play_result = ma_sound_start(soundHandle.pSound);
  if (play_result != MA_SUCCESS)
  {
    printf("Failed to play\n");
    return false;
  }

  return true;
}

AUDIO_API void Dispose()
{
  ma_engine_uninit(&engine);
}
