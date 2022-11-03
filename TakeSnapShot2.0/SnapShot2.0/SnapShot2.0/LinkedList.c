#include <stdio.h>
#pragma warning(disable : 4996)

#include "LinkedList.h"
#include "LogFile.h"
#include "Structs.h"


void AddNewDllLinkedList(struct Dll* currentDLL)
{
	if (HeadDll == NULL)
	{
		HeadDll = currentDLL;
		TailDll = currentDLL;
		currentDLL->next = NULL;
		currentDLL->prev = NULL;
	}
	else
	{
		TailDll->next = currentDLL;
		currentDLL->prev = TailDll;
		currentDLL->next = NULL;
		TailDll = currentDLL;
	}
}

void AddNewProcessLinkedList(struct Process* currentProcess)
{
	if (HeadProc == NULL)
	{
		HeadProc = currentProcess;
		TailProc = currentProcess;
		currentProcess->next = NULL;
		currentProcess->prev = NULL;
	}
	else
	{
		TailProc->next = currentProcess;
		currentProcess->prev = TailProc;
		currentProcess->next = NULL;
		TailProc = currentProcess;
	}
}

void AddNewDllToLinkedList(struct Dll* prevDLL, struct Dll* currentDLL)
{
	prevDLL->next = currentDLL;
	currentDLL->prev = prevDLL;
	currentDLL->next = NULL;
	TailDll = currentDLL;
}

void AddNewProcessToLinkedList(struct Process* prevProcess, struct Process* currentProcess)
{
	prevProcess->next = currentProcess;
	currentProcess->prev = prevProcess;
	currentProcess->next = NULL;
	TailProc = currentProcess;
}

//Initializing global variables
int snapShotIDCounter = 1;
struct SnapShot* HeadSnap = NULL;
struct SnapShot* TailSnap = NULL;
struct SnapShot* SnapShotLinkedList(struct SnapShot* currentSnapShot)
{
	if (HeadSnap == NULL)
	{
		HeadSnap = currentSnapShot;
		TailSnap = currentSnapShot;
		currentSnapShot->next = NULL;
		currentSnapShot->prev = NULL;
	}
	else
	{
		TailSnap->next = currentSnapShot;
		currentSnapShot->prev = TailSnap;
		currentSnapShot->next = NULL;
		TailSnap = currentSnapShot;
	}

	snapShotIDCounter++;
	HeadSnap = HeadSnap;
	TailSnap = TailSnap;
	return HeadSnap;
}