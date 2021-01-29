#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#define SEED 100
#define RANDOM_NUMS 8


int main()
{
	int val, i;
	srand(time(NULL));
	
	for (i = 0; i < RANDOM_NUMS; i++)
	{	
		val = rand();
		printf("Random nr. is %d\n", val);
	}
	
	
	return 0;
}

