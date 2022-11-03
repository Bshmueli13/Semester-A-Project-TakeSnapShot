#include <Windows.h>
#include <Psapi.h>

struct Dll
{
	char DLLName[MAX_PATH];
	struct Dll* next;
	struct Dll* prev;
};
 struct Dll* HeadDll;
 struct Dll* TailDll;

struct Process
{
	unsigned long processID;
	char processName[MAX_PATH];
	PROCESS_MEMORY_COUNTERS memoryInfo;
	struct Dll* dll;
	int DLLCount;
	struct Process* next;
	struct Process* prev;
};
 struct Process* HeadProc;
 struct Process* TailProc;


struct SnapShot
{
	struct Process* process;
	int processCount;
	int DllCountInSnap;
	int sampleID;
	char sampleTime[100];
	struct SnapShot* next;
	struct SnapShot* prev;
};
 struct SnapShot* HeadSnap;
 struct SnapShot* TailSnap;


struct SnapShot_Header
{
	int version;
	int SnapShotCount;
	char reserved[100];
};
extern struct SnapShot_Header snapShotFileHeader;
