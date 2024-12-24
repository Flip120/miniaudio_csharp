using System.Runtime.InteropServices;

public static class AudioPlatform
{
	public const string DLL = "audio_api";

	[Flags]
	public enum SoundFlags
	{
		STREAM = 0x00000001,
		DECODE = 0x00000002,
		NO_SPATIALIZATION = 0x00004000
	}

	[UnmanagedFunctionPointer(CallingConvention.Cdecl)]
	public delegate void EndCallback(IntPtr userData, IntPtr sound);


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
	public static extern IntPtr SoundDestroy(IntPtr handle);

	[DllImport(DLL)]
	public static extern void SoundStop(IntPtr handle);

	[DllImport(DLL)]
	public static extern bool SoundPlay(IntPtr handle);

	[DllImport(DLL)]
	public static extern void SoundRewind(IntPtr handle);

	[DllImport(DLL)]
	public static extern void SoundSetLooping(IntPtr handle, bool looping);

	[DllImport(DLL)]
	public static extern void SoundSetEndCallback(IntPtr sound, EndCallback endCallback, IntPtr userData);

	[DllImport(DLL)]
	public static extern void SetListenerDirection(int listenerIndex, float forwardX, float forwardY, float forwardZ);

	[DllImport(DLL)]
	public static extern void SetListenerPosition(int listenerIndex, float positionX, float positionY, float positionZ);


	[DllImport(DLL)]
	public static extern void Dispose();
}
