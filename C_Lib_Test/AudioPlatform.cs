using System.Runtime.InteropServices;

internal static class AudioPlatform
{
	public const string DLL = "audio_api";

	[UnmanagedFunctionPointer(CallingConvention.Cdecl)]
	public delegate void AudioApiLogFn(IntPtr msg);

	// need to store static references otherwise the delegates will get collected
	private static readonly AudioApiLogFn logInfo = Log.Info;
	private static readonly AudioApiLogFn logWarn = Log.Warning;
	private static readonly AudioApiLogFn logErr = Log.Error;

	[Flags]
	public enum SoundFlags
	{
		STREAM = 0x00000001,
		DECODE = 0x00000002,
		NO_SPATIALIZATION = 0x00004000
	}

	[DllImport(DLL)]
	public static extern bool Startup();

	[DllImport(DLL)]
	public static extern void SetGlobalVolume(float value);

	[DllImport(DLL)]
	public static extern IntPtr SoundGroupCreate(IntPtr parent);

	[DllImport(DLL)]
	public static extern float SoundGroupGetVolume(IntPtr soundGroup);

	[DllImport(DLL)]
	public static extern void SoundGroupSetVolume(IntPtr soundGroup, float value);

	[DllImport(DLL)]
	public static extern void SoundGroupDestroy(IntPtr soundGroup);

	[DllImport(DLL)]
	public static extern IntPtr SoundCreate(string soundFilePath, SoundFlags flags, IntPtr soundGroup);

	[DllImport(DLL)]
	public static extern float SoundGetVolume(IntPtr soundGroup);

	[DllImport(DLL)]
	public static extern void SoundSetVolume(IntPtr soundGroup, float value);

	[DllImport(DLL)]
	public static extern IntPtr SoundDestroy(ref IntPtr handle);

	[DllImport(DLL)]
	public static extern bool SoundPlay(IntPtr handle);

	[DllImport(DLL)]
	public static extern void Dispose();
}
