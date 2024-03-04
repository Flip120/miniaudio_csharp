class Program
{
  public static void Main()
  {
    AudioPlatform.Startup();

    var handle = AudioPlatform.LoadSound("assets/audio/test.wav");
    var t = new Thread(() =>
    {
      AudioPlatform.Play(handle);
    });
    t.Start();

    Thread.Sleep(5000);

    AudioPlatform.UnloadSound(ref handle);
    Console.WriteLine("CACA");
    AudioPlatform.Dispose();
  }
}