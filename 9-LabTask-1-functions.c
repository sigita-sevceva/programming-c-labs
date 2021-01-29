#include <stdio.h>
#include <stdbool.h>

#define SORTING_FACILITY_SIZE 10

void PrintArray(int numArray[], int arrayLength);
void HowMuchWillFit(int number, int total);
void Sorting();
int CombiningInSorting(int thirdArray[], int sizeOfArray, int thirdArrayLength, int numArray[], int max);

int main(void)
{
    int totalCargo;
    int totalInSorting = 0;
	int storageA[] = {17, 4, 9, 15, 2, 11, 44};
    int storageB[] = {15, 9, 2, 13, 1};
    int sortingFacility[SORTING_FACILITY_SIZE];
    int totalA = sizeof(storageA) / sizeof(int);
    int totalB = sizeof(storageB) / sizeof(int);
    
    printf("Warehouse A contains:\n");
	PrintArray(storageA, sizeof(storageA) / sizeof(int));
    printf("\n\n");
    
    printf("Warehouse B contains:\n");
	PrintArray(storageB, sizeof(storageB) / sizeof(int));
    printf("\n\n");

    // informational print
    totalCargo = totalA + totalB;
    HowMuchWillFit(SORTING_FACILITY_SIZE, totalCargo);
    printf("\n\n");

    // copy the items to the third array
	totalInSorting = CombiningInSorting(sortingFacility, totalA, totalInSorting, storageA, SORTING_FACILITY_SIZE);
	
	totalInSorting = CombiningInSorting(sortingFacility, totalB, totalInSorting, storageB, SORTING_FACILITY_SIZE);
	
    printf("Entry order to the sorting facility:\n");
    PrintArray(sortingFacility, totalInSorting);
    printf("\n\n");
    
    /* rearrange the elements in the descending order */
	Sorting(sortingFacility, totalInSorting);

    printf("Exit order to the sorting facility:\n");
    PrintArray(sortingFacility, totalInSorting);
    printf("\n\n");

    return 0;
}



void PrintArray(int numArray[], int arrayLength)
{
	int i;
	for (i = 0; i < arrayLength; i++)
    {
        printf("%d ", numArray[i]);
    }
}

void HowMuchWillFit(int number, int total)
{
	if (total < number)
    {
        printf("All %d item(s) will be shipped to sorting", total);
    }
    else
    {
        printf("Only %d / %d items will be shipped to sorting",
            number, total);
    }
}

void Sorting(int nums[], int len)
{
	bool sorted;
	int i, j, temp;	
	
	for (i = 0, sorted = false; !sorted; i++)
    {
        /* assume that the array is sorted unless any swaps happen */
        sorted = true;
        
        for (j = 0; j < len - 1 - i; j++)
        {
            if (nums[j] < nums[j + 1])
            {
                temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
                /* since we had to swap something, it was not sorted */
                sorted = false;
            }
        }
    }
}

int CombiningInSorting(int thirdArray[], int sizeOfArray, int thirdArrayLength, int numArray[], int max)
{  
    int i;
    for (i = 0; i < sizeOfArray && thirdArrayLength < max; i++)
    {
        thirdArray[thirdArrayLength] = numArray[i];
        thirdArrayLength++;
    }

    return thirdArrayLength;
}
