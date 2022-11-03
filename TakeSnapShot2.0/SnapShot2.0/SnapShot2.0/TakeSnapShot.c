#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <Psapi.h>
#pragma warning(disable : 4996)

#include "TakeSnapShot.h"
#include "LogFile.h"
#include "GetProcessInfo.h"
#include "Structs.h"
#include "LinkedList.h"


struct SnapShot* TakeOneSnapShot(struct SnapShot* prevSnapShot)
{
	LogEvent("Start taking One SnapShot");

	struct SnapShot* singleSnapShot = GetProcessesInfo(prevSnapShot);

	LogEvent("Taking One SnapShot has finished");

	return singleSnapShot;
}

struct SnapShot* Take20SnapShotsIn20Seconds()
{
	LogEvent("Start taking Twenty SnapShots");

	struct SnapShot* singleSnapShot = NULL;

	for (int i = 0; i < 20; i++)
	{
		singleSnapShot = TakeOneSnapShot(singleSnapShot);
		Sleep(1000);
	}

	LogEvent("Taking Twenty SnapShots has finished");

	return singleSnapShot;
}

struct SnapShot* TakeLongSnapShot()
{
	LogEvent("Start taking Long SnapShot");
	struct SnapShot* singleSnapShot = NULL;

	char stop = 0;
	while (stop != '4')
	{
		singleSnapShot = TakeOneSnapShot(singleSnapShot);
		Sleep(1000);

		if (kbhit())
		{
			stop = getch();
		}
	}

	LogEvent("End taking Long SnapShot");

	return singleSnapShot;
}


