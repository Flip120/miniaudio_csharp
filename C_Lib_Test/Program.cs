class Program
{
  public static void Main()
  {
    AudioPlatform.Startup();

    var sfxGroup = AudioPlatform.SoundGroupCreate(0);
    var handle = AudioPlatform.SoundCreate("assets/audio/door_open.wav", 0, sfxGroup);
    var t = new Thread(() =>
    {
      Console.WriteLine("BEFORE REWIND");
      AudioPlatform.SoundRewind(handle);
      Console.WriteLine("AFTER REWIND");
      AudioPlatform.SoundPlay(handle);
      AudioPlatform.SoundSetLooping(handle, true);
    });
    t.Start();
    Console.WriteLine("START THREAD");

    Thread.Sleep(5000);

    Console.WriteLine($"HANDLE {handle}");
    AudioPlatform.SoundStop(handle);
    Console.WriteLine("FINISHED STOPPED");
    AudioPlatform.Dispose();
  }
}