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

typedef void (AUDIO_API_CALL * AudioApiLogFn)(const char *msg);

typedef enum AudioLogging
{
	AUDIO_LOGGING_DEFAULT,
	AUDIO_LOGGING_ALL,
	AUDIO_LOGGING_NONE
} AudioLogging;

typedef struct
{
  AudioApiLogFn logInfo;
  AudioApiLogFn logWarn;
  AudioApiLogFn logError;
  AudioLogging level;
} AudioState;

typedef struct {
  ma_sound* pSound;
} SoundHandle;

AUDIO_API int Startup();

AUDIO_API SoundHandle LoadSound(const char *audioFilePath);
AUDIO_API void UnloadSound(SoundHandle* handle);
AUDIO_API int Play(SoundHandle handle);

AUDIO_API void Dispose();
