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

typedef struct {
  ma_sound* pSound;
} SoundHandle;

AUDIO_API int Startup();

AUDIO_API SoundHandle LoadSound(const char *audioFilePath);
AUDIO_API void UnloadSound(SoundHandle* handle);
AUDIO_API int Play(SoundHandle handle);

AUDIO_API void Dispose();
