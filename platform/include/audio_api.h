#if defined _WIN32 || defined __CYGWIN__
#define AUDIO_API __declspec(dllexport)
#define AUDIO_API_CALL __cdecl
#elif __GNUC__
#define AUDIO_API __attribute__((__visibility__("default")))
#define AUDIO_API_CALL
#else
#define AUDIO_API
#define AUDIO_API_CALL
#endif

#include "miniaudio.h"

// typedef struct
// {
// 	ma_sound *pSound;
// } SoundHandle;
typedef struct Sound Sound;
typedef struct SoundGroup SoundGroup;

typedef enum SoundFlags
{
	SOUND_FLAG_STREAM = 0x00000001,
	SOUND_FLAG_DECODE = 0x00000002,
	SOUND_FLAG_NO_SPATIALIZATION = 0x00004000
} SoundFlags;

AUDIO_API int Startup();
AUDIO_API void SetGlobalVolume(float value);

AUDIO_API SoundGroup *SoundGroupCreate(SoundGroup *parent);
AUDIO_API float SoundGroupGetVolume(SoundGroup *soundGroup);
AUDIO_API void SoundGroupSetVolume(SoundGroup *soundGroup, float value);
AUDIO_API void SoundGroupDestroy(SoundGroup *soundGroup);

AUDIO_API Sound *SoundCreate(const char *audioFilePath, SoundFlags flags, SoundGroup *soundGroup);
AUDIO_API float SoundGetVolume(Sound *sound);
AUDIO_API void SoundSetVolume(Sound *sound, float value);
AUDIO_API int SoundPlay(Sound *sound);
AUDIO_API void SoundSetEndCallback(Sound *sound, ma_sound_end_proc endCallback, void *userData);
AUDIO_API void SoundDestroy(Sound *handle);

AUDIO_API void SetListenerDirection (ma_uint32 listenerIndex, float forwardX, float forwardY, float forwardZ);
AUDIO_API void SetListenerPosition(ma_uint32 listenerIndex, float x, float y, float z);

AUDIO_API void Dispose();
