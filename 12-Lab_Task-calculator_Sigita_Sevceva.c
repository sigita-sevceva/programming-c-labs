/**
 * File: 		12-Lab_Task-calculator_Sigita_Sevceva.c
 * Author:		Sigita Sevceva
 * E-mail:		sisevc@ttu.ee
 * Created:		16.11.2020
 * Last edit:	16.11.2020
 * 
 * Description:	Lab Task on command line arguments for calculator creation
 * 
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define POS_OPER_1 1
#define POS_OPER_2 2
#define POS_OPER_3 3

void GetHelp();
int CheckArgumentCount(int argc, char* help);
int CheckOperands(char* operand);
long Calculate(int nr1, int nr2, char operation);

int main(int argc, char *argv[])
{
	int i = 0;
	puts("Input --help for more information at any time");
	
	if (!CheckArgumentCount(argc, argv[i]))
	{
		GetHelp();
		exit(1);
	}
	else 
	{
		int nr1 = CheckOperands(argv[POS_OPER_1]);
		int nr2 = CheckOperands(argv[POS_OPER_3]);
		int result;
	
		printf("%d\n", nr1);
		printf("%c\n", *argv[POS_OPER_2]);
		printf("%d\n", nr2);
	
		result = Calculate(nr1, nr2, *argv[POS_OPER_2]);
		printf("Result: %d", result);
	}
	
	return 0;
}
 /**
 * Function:       GetHelp
 *
 * Description:    Gives the user more information
 *                 about the program.
 *
 * Parameters:     none
 *
 * Return:         none
 */
void GetHelp()
{
	puts("Enter the program name, first operand, the operator,"); 
	puts("and the second operator to do calculation. E.g. ./calc 1 + 2");
}
 /**
 * Function:       CheckArgumentCount
 *
 * Description:    Checks whether the user inputted the correct number
 *                 of arguments to perform the calculation, warns if not.
 *
 * Parameters:     argument count, argument vector
 *
 * Return:         error code
 */	
int CheckArgumentCount(int argc, char* help)
{
	int i = 0;
	
	if (argc != 4)
	{		
		puts("Wrong number of arguments to perform the calculation.\n");
		return 0;
	}
	else if (strcmp(&help[i], "--help") == 0)
	{
		return 0;
	}
	return 1;
}
 /**
 * Function:       CheckOperands
 *
 * Description:    Checks whether the operands are integers
 *                 if not, the program shows that the operand is invalid.
 *					If correct type of operands, the function returns
 * 					the number as integer.
 * 
 * Parameters:     operands
 *
 * Return:         either error code for exit or the operands as integers
 */
int CheckOperands(char* operand)
{	
	int i = 0;
	
	while (operand[i] != '\0')
	{
		if (operand[i] < '0' || operand[i] > '9')
		{
			printf("'%c' is not a valid operand\n", operand[i]);
			exit(1);
		}
		i++;
	}
	return atoi(operand);
}
 /**
 * Function:       Calculate
 *
 * Description:    Performs the calculations depending on the users choice
 *                 
 *
 * Parameters:     1st operand, 2nd operand, and operator
 *
 * Return:         result as integer
 */
long Calculate(int nr1, int nr2, char operation)
{
	long result = 0;
	//float resultf = 0.00f;
	
	switch (operation)
	{
		case '+':
			result = nr1 + nr2;
			break;
		case '-':
			result = nr1 - nr2;
			break;
		case '*':
			result = nr1 * nr2;
			break;
		case '/':
			if (nr2 == 0)
			{
				puts("Error! Divion by zero.");
				exit(1);
			}
			else
			{
				 result = (float) nr1 / (float) nr2;
			}
			break;
		default:
			puts("Operator invalid.");
			break;
	}
	return result;
}
