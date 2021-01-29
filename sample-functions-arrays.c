#include <stdio.h>

void PrintArray(int numArray[], int arrayLength);

int main(void)
{
	int firstNumArray[] = {5, 8, -2, 65, 1, 36};
	int secondNumArray[] = {7, 97, -24, -74};
	PrintArray(firstNumArray, sizeof(firstNumArray) / sizeof(int));
	PrintArray(secondNumArray, sizeof(secondNumArray) / sizeof(int));
	return 0;
}

void PrintArray(int numArray[], int arrayLength)
{
	int i;
	for(i = 0; i < arrayLength; i++)
	{
		printf("%d\n", numArray[i]);
	}
}
