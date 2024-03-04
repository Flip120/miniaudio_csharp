# miniaudio_csharp
A miniaudio wrapper for c#

## Basic Usage

Init the audio engine

```(csharp)
AudioPlatform.Startup();
```

Load a sound and get the handle

```(charp)
var handle = AudioPlatform.LoadSound("my-sound-file.wav");
```

Play a sound

```(charp)
AudioPlatform.Play(handle);
```

Unload a sound

```(charp)
AudioPlatform.UnloadSound(ref handle);
```

Unitialize the audio engine

```(charp)
 AudioPlatform.Dispose();
```
