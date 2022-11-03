#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

#include "GetProcessInfo.h"
#include "LogFile.h"
#include "Structs.h"


//Swaps between two Processes
void Replace(struct Process* dllCount)
{
	if (dllCount == NULL) //No Processes in the list
	{
		LogEvent("There are no Processes in the list.");
		return;
	}
	else if (dllCount->next == NULL) //One Process in the list
	{
		LogEvent("There is only 1 Process in the list.");
		return;
	}
	else if (dllCount == HeadProc && dllCount->next == TailProc) //2 Processes in the list: HeadP and TailP
	{
		dllCount->prev = TailProc;
		dllCount->next = NULL;
		TailProc->prev = NULL;
		TailProc->next = dllCount;
		TailProc = dllCount;
		HeadProc = dllCount->prev;
	}
	else if (dllCount == HeadProc && dllCount->next != NULL) //The 2 first Processes in the list
	{
		dllCount->next = dllCount->next->next;
		dllCount->next->prev->next = dllCount;
		dllCount->next->prev->prev = NULL;
		dllCount->prev = dllCount->next->prev;
		dllCount->next->prev = dllCount;
		HeadProc = dllCount->prev;
	}
	else if (dllCount->next == TailProc && dllCount->prev != NULL) //The 2 last Processes in the list
	{
		dllCount->prev->next = dllCount->next;
		dllCount->next->prev = dllCount->prev;
		dllCount->next->next = dllCount;
		dllCount->prev = dllCount->next;
		dllCount->next = NULL;
		TailProc = dllCount;
	}
	else //2 middle Processes
	{
		dllCount->prev->next = dllCount->next;
		dllCount->next = dllCount->next->next;
		dllCount->next->prev->prev = dllCount->prev;
		dllCount->prev = dllCount->next->prev;
		dllCount->next->prev->next = dllCount;
		dllCount->next->prev = dllCount;
	}
}

//Sorts the list
void BubbleSort()
{
	//Starting to sort the list
	struct Process* currentItem = HeadProc;
	if (currentItem == NULL)
	{
		LogError("The List is Empty");
		return;
	}

	LogEvent("Swap Process");
	int counter = 1;
	while (counter != 0)
	{
		counter = 0;
		currentItem = HeadProc;

		while (currentItem != NULL)
		{
			if (currentItem->next != NULL && currentItem->DLLCount > currentItem->next->DLLCount)
			{
				Replace(currentItem);
				counter++;
				currentItem = currentItem->prev;
			}

			currentItem = currentItem->next;
		}
	}


	LogEvent("Sorting Has Concluded ");
}
