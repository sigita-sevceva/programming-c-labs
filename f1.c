/**
 * File: 		f1.c
 * Author:		Sigita Sevceva
 * E-mail:		sisevc@ttu.ee
 * Created:		7.12.2020
 * Last edit:	
 * 
 * Description:	Formula 1 pilots and their lap times
 * 
 **/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define F1 10 //max elements of the arrays as stated in the task
#define NAME_LEN 20 // chosen randomly
#define MIN 75 // minimum amount of random lap time value
#define MAX 110 // maximum amount of random lap time value

void PrintPilots(int num, char names[F1][NAME_LEN]);
void SingleLap(int num, int times[F1]);
int LapTime(int min, int max);
void PrintPilotTimes(int num, char names[F1][NAME_LEN], int times[F1]);
int FastestPilot(int num, int times[F1]); 
int SlowestPilot(int num, int times[F1]);
void PrintPilot(int index, float avg, char names[F1][NAME_LEN], int times[F1]);
float FastAndFurious(int num, char names[F1][NAME_LEN], int times[F1]);
void FastAndFurious2(float avg, int num, char names[F1][NAME_LEN], 
		char fastestNames[F1][NAME_LEN], char slowestNames[F1][NAME_LEN],
															int times[F1]);

int main(void)
{
	char pilots[F1][NAME_LEN] = {	
									"F.Alonso",
									"M.Webber",
									"L.Hamilton",
									"S.Vettel",
									"J.Button",
									"F.Massa",
									"T.Glock",
									"N.Rosberg",
									"M.Schumacher",
									"P. de la Rosa"
								};
	int lapTimes[F1] = {};
	char fasterThanAvgPilots[F1][NAME_LEN] = {};
	char slowerThanAvgPilots[F1][NAME_LEN] = {};
	int nPilots = F1;
	int fast = 0;
	int slow = 0;
	float avg = 0.0;
	
	printf("Pilots in the race:\n");
	PrintPilots(nPilots, pilots);
	SingleLap(nPilots, lapTimes);
	PrintPilotTimes(nPilots, pilots, lapTimes);
	fast = FastestPilot(nPilots, lapTimes);
	slow = SlowestPilot(nPilots, lapTimes);
	avg = FastAndFurious(nPilots, pilots, lapTimes);
	PrintPilot(fast, avg, pilots, lapTimes);
	PrintPilot(slow, avg, pilots, lapTimes);
	FastAndFurious2(avg, nPilots, pilots, fasterThanAvgPilots, 
								slowerThanAvgPilots, lapTimes);
	printf("\nFastest pilots in the race:\n");
	PrintPilots(nPilots, fasterThanAvgPilots);
	printf("Slowest pilots in the race:\n");
	PrintPilots(nPilots, slowerThanAvgPilots);
	
	return 0;
}
/**
 * takes the count of items in array and the members of the array, prints the names
 */
void PrintPilots(int num, char names[F1][NAME_LEN])
{
	int i;
	for (i = 0; i < num; i++)
	{
		printf("%s ", names[i]);
	}
	puts("\n");
}
/**
 * takes the count of items in array and an empty array of lap times,
 * generates random lap time using the next function LapTime
 */
void SingleLap(int num, int times[F1])
{
	int i;
	for (i = 0; i < num; i++)
	{
		times[i] = LapTime(MIN, MAX);
	}
}
/**
 * takes the minimum and maximum integer values, generates random lap tames
 */
int LapTime(int min, int max)
{
	int num;
	num = ( rand() % (max - min + 1)) + min;
	return num;
}
/**
 * takes the count of items in array, elements of two arrays (string and 
 * int) and prints them in a table
 */
void PrintPilotTimes(int num, char names[F1][NAME_LEN], int times[F1])
{
	printf("\n");
	int i;
	for (i = 0; i < num; i++)
	{
		printf("%*s %*d\n", NAME_LEN, names[i], NAME_LEN, times[i]);
	}
	puts("\n");
}
/**
 * takes the count of items in array, the elements of the numeric array
 * and calculates the fastest pilot time, returns the index of it
 */
int FastestPilot(int num, int times[F1])
{
	int i;
	int index = 0;
	for (i = 1; i < num; i++)
	{
		if (times[i] < times[index])
		{
			index = i;
		}
	}
	return index;
}
/**
 * takes the count of items in array, the elements of the numeric array
 * and calculates the slowest pilot time, returns the index of it
 */
int SlowestPilot(int num, int times[F1])
{
		int i;
	int index = 0;
	for (i = 1; i < num; i++)
	{
		if (times[i] > times[index])
		{
			index = i;
		}
	}
	return index;
}
/**
 * takes the previously calculated index of the fastest pilot, the index 
 * of slowest pilot, the array of names of the pilot and the array of times
 * of the pilots, prints both of the fastest & slowest pilot names and 
 * times in seconds
 */
void PrintPilot(int index, float avg, char names[F1][NAME_LEN], int times[F1])
{
	if (times[index] < avg)
	{
		printf("The fastest pilot was %s with lap time %d s \n", 
									names[index], times[index]);
	}
	else
	{
		printf("The slowest pilot was %s with lap time %d s \n", 
									names[index], times[index]);
	}
}
/**
 * takes the count of items in array, the elements of the pilot and times
 *  array and calculates which pilots are above and below average, prints
 * them and also returns a floating number of the average to be used in 
 * the next function
 */
float FastAndFurious(int num, char names[F1][NAME_LEN], int times[F1])
{
	int i;
	int sum = 0;
	float avg = 0.0;
	
	for (i = 0; i < num; i++)
	{
		sum += times[i];
	}
	avg = (float) sum / num;
	
	printf("\nThe average lap time is %.2f s\n", avg);
	puts("\n");
	puts("Pilots that are faster than average:");

	for (i = 0; i < num; i++)
	{
		if (times[i] < avg)
		{
			printf("%s ", names[i]);
		}
	}
	puts("\n");
	puts("Pilots that are slower than average:");

	for (i = 0; i < num; i++)
	{
		if (times[i] > avg)
		{
			printf("%s ", names[i]);
		}
	}
	puts("\n");
	return (float) avg;
}
/**
 * takes the previously calculated average, count of items in array, 
 * the elements of the numeric array, two new arrays for names of the 
 * below and above avarege pilots and copies the according values into 
 * them by using strcpy function
 */
void FastAndFurious2(float avg, int num, char names[F1][NAME_LEN], 
		char fastestNames[F1][NAME_LEN], char slowestNames[F1][NAME_LEN],
															int times[F1])
{
	int i;
	for (i = 0; i < num; i++)
	{
		if (times[i] < avg)
		{
			strcpy(fastestNames[i], names[i]);
		}
		else
		{
			strcpy(slowestNames[i], names[i]);
		}
	}
}
