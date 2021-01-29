#include <stdio.h>
#include <string.h>

#define MAX_STR 40

void PrintPerson(char person[]);

int main(void)
{
    char data[][MAX_STR] = {"Maria,Kask",
                            "Johanna-Maria,Kask",
                            "Kalev Kristjan,Kask"};
    int i;
    int numOfPeople = sizeof(data) / MAX_STR;

    printf("Number of people: %d\n", numOfPeople);
    for (i = 0; i < numOfPeople; i++)
    {
        PrintPerson(data[i]);
    }

    return 0;
}

void PrintPerson(char person[])
{
    char chr = ',';
    char str1[MAX_STR];
    
    printf("Parsing: '%s'\n", person);
	// Write your code to generate the required e-mail address below this comment!
	
	strcpy(str1, person);
	strncat(str1, "@ttu.ee", MAX_STR);
	printf("E-mail address: %s\n\n", str1);
}


		
