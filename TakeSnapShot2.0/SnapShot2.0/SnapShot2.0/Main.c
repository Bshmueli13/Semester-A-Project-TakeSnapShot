#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#pragma warning(disable : 4996)

#include "LogFile.h"
#include "Structs.h"
#include "LinkedList.h"
#include "ResetCollections.h"
#include "SaveOrLoadFile.h"
#include "TakeSnapShot.h"
#include "BubbleSort.h"
#include "GetProcessInfo.h"



struct SnapShot_Header snapShotFileHeader;

int main()
{
	time_t t;
	time(&t);
	struct tm* timeinfo;
	struct SnapShot* SnapShot = NULL;
	struct SnapShot* SnapShotList = NULL;
	char str[1000];


	//initialization of struct SnapShot_Header 
	snapShotFileHeader.version = 1;
	snapShotFileHeader.SnapShotCount = 0;

	char userResponse = NULL;
	while (userResponse != 'E')
	{
		printf("\nPlease pick from one of the available options:\n1-Take A Single SnapShot\n2-Take 20 SnapShots for 20 seconds (Will result in culminating data)\n3-Start Long SnapShot\n4-End Long SnapShot\n5-Generate HTML Report(unavailable)\n6-Reset Collections\n7-Save to File\n8-Load from File\n'E'-Exit the Program\n");
		userResponse = getch();
		switch (userResponse)
		{
		case '1': //Take One Process SnapShot
			timeinfo = localtime(&t);
			sprintf(str, "%d.%02d.%02d: %02d:%02d:%02d", timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
			SnapShot = TakeOneSnapShot(NULL);
			strcpy(SnapShot->sampleTime, str);
			SnapShot->sampleID = snapShotIDCounter;
			LogEvent("Start Bubble Sorting the linked list");
			BubbleSort();
			SnapShot->process = HeadProc;
			SnapShotList = SnapShotLinkedList(SnapShot);
			break;
		case '2': //Take 20 Process SnapShots for 20 seconds (accumulating the data) -> Gives 1 List 
			timeinfo = localtime(&t);
			sprintf(str, "%d.%02d.%02d: %02d:%02d:%02d", timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
			SnapShot = Take20SnapShotsIn20Seconds();
			strcpy(SnapShot->sampleTime, str);
			SnapShot->sampleID = snapShotIDCounter;
			LogEvent("Start Bubble Sorting the linked list");
			BubbleSort();
			SnapShot->process = HeadProc;
			SnapShotList = SnapShotLinkedList(SnapShot);
			break;
		case '3': //Start Long SnapShot (ends when the user presses '4')
			timeinfo = localtime(&t);
			sprintf(str, "%d.%02d.%02d: %02d:%02d:%02d", timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
			SnapShot = TakeLongSnapShot();
			strcpy(SnapShot->sampleTime, str);
			SnapShot->sampleID = snapShotIDCounter;
			LogEvent("Start Bubble Sorting the linked list");
			BubbleSort();
			SnapShot->process = HeadProc;
			SnapShotList = SnapShotLinkedList(SnapShot);
			break;
		case '5': //Generate HTML Report
			
			break;
		case '6': //Reset Collections - Deleting all SanpShots from the memory
			LogEvent("Start Reset Collections");
			ResetCollections();
			SnapShotList = NULL;
			LogEvent("Reset Collections has finished");
			break;
		case '7': //Save to File
			SaveIntoFile();
			break;
		case '8': //Load from File
			SnapShotList = LoadFromFile();

			break;
		case 'E': //Exit the program
			LogEvent("Exit the program");
			ResetCollections();
			printf("Thank you Have a Great day.\n");
			break;

		default:
			printf("Invalid Key Please try again\n");
			break;
		}
	}

	return 0;
}