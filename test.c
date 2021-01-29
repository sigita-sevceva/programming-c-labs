#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int CheckOperands(char num[], int i);

int main(void)
{
	num[3] = { 1, 3, 5};
	
	CheckOperands(num[i], 3);
	
	return 0;
}
	

int CheckOperands(char num[], int i)
{	
	while (num[i] != '\0')
	{
		if (numv[i] < '0' || num[i] > '9')
		{
			return num[i];
		}
	}
	return atoi(num[i]);
}
