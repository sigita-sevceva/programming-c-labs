/**
 * File: 		HW2_Sigita_Sevceva.c
 * Author:		Sigita Sevceva
 * E-mail:		sisevc@ttu.ee
 * Created:		8.11.2020
 * Last edit:	24.11.2020
 * 
 * Description:	Big Homework #2 on sale of TVs and discounts
 * 
 **/
// importing libraries
#include <stdio.h>
#include <stdlib.h>
// defining macros of table layout, product name max length; 
// min and max possible discount amount
#define F_LEN 13
#define MAX_ENTRY_LEN 20
#define MIN_DISC 10
#define MAX_DISC 60
// function prototypes
void ReadArrays(char brands[][MAX_ENTRY_LEN], int prices[], int len);
int GetIntInRange(int min, int max);
int DiscountCalc(int discountPercent, int regPrice);
void ShowBrandsAndPrices(char brands[][MAX_ENTRY_LEN], int prices[], int len);

int main(void)
{
	// the first number in the file specifying the amount of items
	int lengthArray;
	scanf("%d", &lengthArray); 
	printf("%d", lengthArray);
	
	// reading in the manufacturers and prices from stdin and storing them
	char brandArray[lengthArray][MAX_ENTRY_LEN];
	int priceArray[lengthArray];
	ReadArrays(brandArray, priceArray, lengthArray);
	
	// printing the old price table
	puts("\nOld prices:\n");
	ShowBrandsAndPrices(brandArray, priceArray, lengthArray);
	
	// defining a 3rd array for discounts and calculating, storing each price
	int discountArr[lengthArray];
	int discount, i;			
	discount = GetIntInRange(MIN_DISC, MAX_DISC);
	for (i = 0; i < lengthArray; i++)
	{
		discountArr[i] = DiscountCalc(discount, priceArray[i]);
	}

	// printing the new price table
	puts("New prices:\n");
	ShowBrandsAndPrices(brandArray, discountArr, lengthArray);
	// printing the discount amount
	printf("%d", discount);

    return 0;
}
/**
 * Description:    Reads brand names and prices arrays from stdin
 *                 Repeats until the end of length of the array
 *
 * Parameters:     brands[][] string array with specified entry char lim
 *                 price[] integer array
 * 				   len - length of the arrays
 * 
 * Type:		   void
 */
void ReadArrays(char brands[][MAX_ENTRY_LEN], int prices[], int len)
{
	//code to read in brands and prices from a file 
	int i;
	for (i = 0; i < len; i++)
	{
		scanf("%s", &brands[i][i]);
		scanf("%d", &prices[i]);
	}
}
/**
 * Description:    Asks the user for an integer in between the given limits.
 *                 Repeats until requirements are met and  returns the number.
 *                 Outputs a warning when input is out of range
 *
 * Parameters:     min - integer, lower limit for the user input (inclusive)
 *                 max - integer, upper limit for the user input (inclusive)
 *
 * Return:         Returns an integer within the specified limits
 */
int GetIntInRange(int min, int max)
{
    int num;
    do
    {
        scanf("%d", &num);
        if (num < min || num > max)
            printf("\nInput must be in between %d and %d\n", min, max);
            break;
    }
    while (num < min || num > max);
    return num;
}
/**
 * Description:    Calculates the discount according to the regular price
 *                 and the discount % input by user.
 *
 * Parameters:     discountPercent - int, discount chosen by user
 *                 regPrice - int, regular price of the product
 *
 * Return:         Returns an integer with the new discount price.
 */
int DiscountCalc(int discountPercent, int regPrice)
{
	int newPrice;
	int one = 1;
	float hundred = 100.0;
	
	newPrice = regPrice * ( one - (discountPercent / hundred));
	
	return newPrice;
}
/**
 * Description:    Displays a table of brands and their according prices
 *
 * Parameters:     brands - string array, product titles
 *                 prices - int array, regular or discount prices 
 * 				   len - integer, the size of the array
 * 
 * Type:		   void
 */
void ShowBrandsAndPrices(char brands[][MAX_ENTRY_LEN], int prices[], int len)
{
	int i;
	printf("%-*s %*s\n", 	F_LEN, "manufacturer",
							F_LEN, "price");
	for (i = 0; i < len; i++)
	{
		printf("%-*s %*d\n", 	F_LEN, &brands[i][i], 
								F_LEN, prices[i]);
	}
	printf("\n");
}
