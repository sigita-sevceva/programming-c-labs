#include <stdio.h>
#include <stdlib.h> //srand, rand//
//#include <time.h>	//time//

#define RAND_NUM_COUNT 10
#define USER_NUM_COUNT 6
#define SEED 100
#define RANDOM_MAX 25

int main()
{
	srand(SEED);
	int randNum[USER_NUM_COUNT];
	int finalArray[USER_NUM_COUNT];
	int luckyNr[RAND_NUM_COUNT];
	int i;
	int k, j;
	int counter = 0;
	
	printf("The range of random numbers is: 1 ... %d\n", RANDOM_MAX);
	printf("Enter 6 random numbers: \n");
	for (i = 0; i < USER_NUM_COUNT; i++)
	{
		scanf("%d", &randNum[i]); //user input
		do
		{
			for (k = 0; k < i-1; k++)
			{
					printf("Error, try again: \n");
					scanf("%d", &randNum[i]); //user input
					break;
			}	
		} while (k!=i && randNum[k] == randNum[i]);
	}
	
	printf("Computer chose: \n");
	for (j = 0; j < RAND_NUM_COUNT; j++)
	{
		luckyNr[j] = rand() % RANDOM_MAX;
		printf("%d\n", luckyNr[j]);
	} //regular lucky number generator, might repeat numbers, for simple task
	
	
	for (i = 0; i < j; i++)
	{
		for (j = 0; j < RAND_NUM_COUNT; j++)
		{
			if (luckyNr[j] == randNum[i])
			{
				if (luckyNr[j] != luckyNr[j-1] && randNum[i] != randNum[i-1])
				{
					finalArray[i] = randNum[i];
					counter++;
				}
			} //placing matched numbers to a third array
		}
	}
	
	if (counter == 6) //winner
	{
		printf("\nCongratulations, you've guessed all %d: \n", counter);
	}
	else if (0 < counter && counter <= 5)
	{
		printf("\nYou got %d matches with lucky numbers: \n", counter);
	}
	else //loser
	{
		printf("Sorry, you didn't guess any of the numbers: \n");
	}
	
	for (i = 0; i < counter; i++) //matching numbers
	{
		printf(" %d ", finalArray[i]);
	}
		
	return 0;
}
	
