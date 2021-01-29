/**
 * File: 		9-Sigita_Sevceva_LabTask-2-array-functions_fix.c
 * Author:		Sigita Sevceva
 * E-mail:		sisevc@ttu.ee
 * Created:		26.10.2020
 * Last edit:	26.10.2020
 * 
 * Description:	Lab Task #2 on user input and arrays
 * 
 **/

#include <stdio.h>
#include <stdlib.h>

#define MINLIMIT -100
#define MAXLIMIT 100
#define LEN 5

int UserInput(int min, int max);
void PrintArray(int nums[], int len);
float FindAverage(int nums[], int len);
int FindSmallest(int nums[], int len);
int IsMemberOfArray(int num, int nums[], int len);

int main(void)
{
	int i, singleNum = 0;
	int flag = 0;
	float mean;
	int nums[LEN];
	int location, minimum;
	
	singleNum = UserInput(MINLIMIT, MAXLIMIT);
	
	for (i = 0; i < LEN; i++)
	{
		nums[i] = UserInput(MINLIMIT, MAXLIMIT);
	}
	
	PrintArray(nums, LEN);
	
	mean = FindAverage(nums, LEN);
	printf("\nThe average of the numbers is %.2f", mean);
	
	location = FindSmallest(nums, LEN);
	minimum = nums[location];
	printf("\nThe smallest number in array is %d", minimum);
	
	flag = IsMemberOfArray(singleNum, nums, LEN);
	if (flag > 0) 
	{
        printf("\nThe number %d is present in the array", singleNum);
    } 
    else 
    {
        printf("\nThe number %d is not present in the array", singleNum);
    }
	
	return 0;
}	

int UserInput(int min, int max)
{
	int num;
	printf("Choose a number between -100 and 100!\n");
	do 
	{
		scanf("%d", &num);
		if (num < min || num > max)
		{
			printf("Out of range!\n");
		}
	}
	while (num < min || num > max);


	return num;
}	


void PrintArray(int nums[], int len)
{
	int j;
	
	for (j = 0; j < len; j++)
	{
		printf("%d ", nums[j]);
	}
}

float FindAverage(int nums[], int len)
{
	int j;
	float sum = 0;
	float average = 0.00;
	
	for (j = 0; j < len; j++)
	{
		sum += nums[j];
	}
	average = sum / j;	
		
	return average;
}

int FindSmallest(int nums[], int len)
{
	int j, index = 0;
	int smallest = nums[0];
	for (j = 1; j < len; j++)
	{
		if (nums[j] < smallest)
		{
			index = j;
		}
	}	
	return index;
}

int IsMemberOfArray(int num, int nums[], int len)
{
	int flag = 0;
	int j = 0;
	for ( j = 0; j < len; j++)
	{	
		if (num == nums[j])
		{
			flag++;
		}
	}
	return flag;
}
