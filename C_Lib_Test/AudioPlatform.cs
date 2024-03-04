using System.Runtime.InteropServices;

internal static class AudioPlatform
{
	public const string DLL = "audio_api";

	[UnmanagedFunctionPointer(CallingConvention.Cdecl)]
	public delegate void AudioApiLogFn(IntPtr msg);

	public struct SoundHandle
	{
		public IntPtr pSound;
	}

	// need to store static references otherwise the delegates will get collected
	private static readonly AudioApiLogFn logInfo = Log.Info;
	private static readonly AudioApiLogFn logWarn = Log.Warning;
	private static readonly AudioApiLogFn logErr = Log.Error;

	[DllImport(DLL)]
	public static extern bool Startup();

	[DllImport(DLL)]
	public static extern SoundHandle LoadSound(string soundFilePath);

	[DllImport(DLL)]
	public static extern SoundHandle UnloadSound(ref SoundHandle handle);

	[DllImport(DLL)]
	public static extern bool Play(SoundHandle handle);

	[DllImport(DLL)]
	public static extern void Dispose();
}
