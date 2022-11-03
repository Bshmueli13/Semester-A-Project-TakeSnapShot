#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

#include "ResetCollections.h"
#include "LogFile.h"
#include "Structs.h"
#include "LinkedList.h"


void ResetCollections()
{
	struct SnapShot* currentSnapShot = HeadSnap;
	struct SnapShot* releaseSnapShot;
	struct Process* currentProcess;
	struct Process* releaseProcess;
	struct Dll* currentDLL;
	struct Dll* releaseDLL;

	while (currentSnapShot != NULL)
	{
		currentProcess = currentSnapShot->process;

		while (currentProcess != NULL)
		{
			currentDLL = currentProcess->dll;

			while (currentDLL != NULL)
			{
				releaseDLL = currentDLL;
				currentDLL = currentDLL->next;
				free(releaseDLL);
			}

			releaseProcess = currentProcess;
			currentProcess = currentProcess->next;
			free(releaseProcess);
		}

		releaseSnapShot = currentSnapShot;
		currentSnapShot = currentSnapShot->next;
		free(releaseSnapShot);
	}

	HeadSnap = NULL;
	TailSnap = NULL;
	HeadProc = NULL;
	TailProc = NULL;
	HeadDll = NULL;
	TailDll = NULL;
	snapShotIDCounter = 1;
}
