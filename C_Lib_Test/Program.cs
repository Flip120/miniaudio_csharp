class Program
{
  public static void Main()
  {
    AudioPlatform.Startup();

    var sfxGroup = AudioPlatform.SoundGroupCreate(0);
    var handle = AudioPlatform.SoundCreate("assets/audio/door_open.wav", 0, sfxGroup);
    var t = new Thread(() =>
    {
      AudioPlatform.SoundPlay(handle);
      AudioPlatform.SoundSetLooping(handle, true);
    });
    t.Start();
    Console.WriteLine("CACA1");

    Thread.Sleep(5000);

    AudioPlatform.SoundDestroy(ref handle);
    Console.WriteLine("CACA");
    AudioPlatform.Dispose();
  }
}