#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Write your constants here */
#define LIMIT_ROWS 20
#define LIMIT_COLS 20
#define RANDOM 100

/* Write your prototypes here. Some have been made for you. If necessary, modify the existing ones. */
int Menu(void);
int GetIntInRange(int min, int max);
void GenerateMatrix(int matrix[LIMIT_ROWS][LIMIT_COLS], int nrow, int mcol, int RAND);
void DisplayMatrix(int matrix[LIMIT_ROWS][LIMIT_COLS], int nrow, int mcol);
void SwitchRows(int matrix[LIMIT_ROWS][LIMIT_COLS], int nrow, int mcol, int whichrow, int otherrow);
void SwitchCols(int matrix[LIMIT_ROWS][LIMIT_COLS], int nrow, int mcol, int whichcol, int othercol);

int main(void)
{
    int data[LIMIT_ROWS][LIMIT_COLS] = {{0}}; // initialize the matrix to zeros
    int menuSelection;
    int nrow = 0;
    int mcol = 0;
    int whichrow = 0;
    int whichcol = 0;
    int otherrow = 0;
    int othercol = 0;
    do
    {
        menuSelection = Menu();
        int count = 0;
        switch (menuSelection)
        {
            case 1:
				nrow = GetIntInRange(1, LIMIT_ROWS);
				mcol = GetIntInRange(1, LIMIT_COLS);
				GenerateMatrix(data, nrow, mcol, RANDOM);
				count++;
				break;
            case 2:
                if (count >= 1)
                {
					puts("Case 2: Print matrix");
					DisplayMatrix(data, nrow, mcol);
					break;
				}
				else
				{
					break;
				}
            case 3:
                if (count >= 1)
                {	
					puts("Case 3: Switch rows");
					whichrow = GetIntInRange(1, nrow);
					otherrow = GetIntInRange(1, nrow);
					SwitchRows(data, nrow, mcol, whichrow, otherrow);
					DisplayMatrix(data, nrow, mcol);
					break;
				}
				else
				{
					break;
                }
            case 4:
                if (count >= 1)
                {	
					puts("Case 4: Switch columns");
					whichcol = GetIntInRange(1, mcol);
					othercol = GetIntInRange(1, mcol);
					SwitchCols(data, nrow, mcol, whichcol, othercol);
					DisplayMatrix(data, nrow, mcol);
					break;
				}
				else
				{
					break;
				}
            case 0:
                puts("Case 0: Exiting");
                break;
            default:
                puts("Case unknown: We didn't understand Your request");
                break;
        }
    }
    while (menuSelection);
    return 0;
}

/**
 * Function:       Menu
 * Description:    Displays the possible menu options to the user,
 *                 allows to select an action to perform.
 *
 * Parameters:     None
 *
 * Return:         Integer, corrensponds to the menu selection from the list
 */
int Menu(void)
{
    int selection;
    putchar('\n');
    puts("Select Your action!");
    puts("1 - Generate new matrix");
    puts("2 - Display matrix");
    puts("3 - Switch rows");
    puts("4 - Switch columns");
    puts("0 - Exit program");
    selection = GetIntInRange(0, 4);
    return selection;
}

/**
 * Function:       GetIntInRange
 *
 * Description:    Asks the user for an integer in between the given limits.
 *                 Repeats until requirements are met and then returns the number.
 *
 * Parameters:     min - integer, lower limit for the user input (inclusive)
 *                 max - integer, upper limit for the user input (inclusive)
 *
 * Return:         Integer, number within the specified limits
 */
int GetIntInRange(int min, int max)
{
    int num;
    do
    {
        printf("> ");
        scanf("%d", &num);
        if (num < min || num > max)
            printf("\nRetry! Input must be in between %d and %d\n", min, max);
    }
    while (num < min || num > max);
    return num;
}
/**
 * Function:       GenerateMatrix
 *
 * Description:    Allow the user to generate a new matrix within dimensions.
 *                 
 *
 * Parameters:     rows - integer, the number of matrix rows
 *                 cols - integer, the number of matrix columns
 * 				   matrix - 
 */
void GenerateMatrix(int matrix[LIMIT_ROWS][LIMIT_COLS], int nrow, int mcol, int RAND)
{
	int i = 0; 
	srand((int)time(NULL));
		
	do
	{
		int j = 0;
		do 
		{
			matrix[i][j] = rand() % RAND;
			j++;
		}
		while (j < mcol);
		i++;
	}
	while (i < nrow);
}	
/**
 * Function:       DisplayMatrix
 *
 * Description:    Allow the user to print the new matrix within dimensions.
 *                 
 *
 * Parameters:     nrow - integer, the number of matrix rows
 *                 mcols - integer, the number of matrix columns
 * 				   matrix -
 */
void DisplayMatrix(int matrix[LIMIT_ROWS][LIMIT_COLS], int nrow, int mcol)		
{		
	int i = 0;
	while (i < nrow)
	{
		int j = 0;
		while (j < mcol)
		{
			printf("%d\t", matrix[i][j]);
			j++;
		}
		putchar('\n');
		i++;
	}
}
/**
 * Function:       SwitchRows
 *
 * Description:    Allow the user to switch the rows of the matrix.
 *                 
 *
 * Parameters:     rows - integer, the number of matrix rows
 *                 cols - integer, the number of matrix columns
 *
 * Return:         Integer, matrix values
**/
void SwitchRows(int matrix[LIMIT_ROWS][LIMIT_COLS], int nrow, int mcol, int whichrow, int otherrow)
{
	int i = 0;
	for (i = 0; i < nrow; i++)
	{
		int temp = matrix[whichrow][i];
		matrix[whichrow][i] = matrix[otherrow][i];
		matrix[otherrow][i] = temp;
	}
}	
/**
 * Function:       SwitchCols
 *
 * Description:    Allow the user to switch the cols of the matrix.
 *                 
 *
 * Parameters:     rows - integer, the number of matrix rows
 *                 cols - integer, the number of matrix columns
 *
 * Return:         Integer, matrix values
**/
void SwitchCols(int matrix[LIMIT_ROWS][LIMIT_COLS], int nrow, int mcol, int whichcol, int othercol)
{
	int j = 0;
	for (j = 0; j < mcol; j++)
	{
		int temp = matrix[j][whichcol];
		matrix[j][whichcol] = matrix[j][othercol];
		matrix[j][othercol] = temp;
	}
}
