#include <stdio.h>


void PrintHello(void); //prototypes
int FindSquareOfInt(int num);

int main(void)
{
	int val;
	int input = 11;
	PrintHello();
	
	// int result = pow(2, 8)
	val = FindSquareOfInt(8);
	printf("Returned value is %d\n", val);
	printf("The square of 3 is %d\n", FindSquareOfInt(3));
	printf("The square of 11 is %d\n", FindSquareOfInt(input));
	
	return 0;
}

void PrintHello(void) //body of the functions (declarations)
{
	printf("Hello!\n");
}

int FindSquareOfInt(int num)
{
	int result;
	result = num * num;
	return result;
}
