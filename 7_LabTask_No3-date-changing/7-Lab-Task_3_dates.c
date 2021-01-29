
/**
 * File:        7-Lab-Task_3_dates.c
 * Author:      Sigita Śevceva
 * Created:     12.10.2020
 * Edited:      
 *
 * Description: base code for date verification. Use stream redirection to store
 *              input.
 **/

#include <stdio.h>
 
#define DATE_LIMIT 100
 
int main(void)
{
	int i, verification, day[DATE_LIMIT], month[DATE_LIMIT], year[DATE_LIMIT];
	int entries = 0; // date count
 
	// loop to read the dates
	while (entries < DATE_LIMIT)
	{
	    // doing additional checks for how many elements were successfully read.
	    // Format is DDMMYYY, %2d reads 2 digits at a time and stores as a number
		verification = scanf("%2d%2d%4d", &day[entries], &month[entries], &year[entries]);
		if (verification != 3) // check if there was a problem storing the whole date
		{
			break; // abort reading, assuming no more dates
		}
		entries++; // new date stored
	}
	printf("Entries read %d:\n", entries);
	// Test output to see if reading was successful.
	for (i = 0; i < entries; i++)
	{
	    // format DD.MM.YYYY. Missing zeros will be shown (e.g. 5 -> 05)
		printf("%02d.%02d.%04d", day[i], month[i], year[i]);
	
		if (year[i] >= 1582 && year[i] <= 2100)
		{
			if((day[i] >= 1 && day[i] <= 31) && (month[i] == 1 || month[i] == 3 || month[i] == 5 || month[i] == 7 || month[i] == 8 || month[i] == 10 || month[i] == 12))
                printf(" < OK.\n");
                
			else if((day[i] >=1 && day[i] <= 30 ) && (month[i] == 4 || month[i] == 6 || month[i] == 9 || month[i] == 11))
                printf(" < OK.\n");
                
			else if((day[i] >= 1 && day[i] <= 28) && (month[i] == 2))
                printf(" < OK.\n");
                
			else if(day[i] == 29 && month[i] == 2 && (year[i] % 400 == 0 ||(year[i] % 4 == 0 && year[i] % 100 != 0)))
                printf(" < OK.\n");
                
			else
                printf(" < Date is invalid.\n");
		}
		else 
		{
			printf(" < Date is invalid.\n");
		}
	}
	
	return 0;
}
