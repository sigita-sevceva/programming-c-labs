#ifndef IMPORT_H
#define IMPORT_H

// Pre-specified lengths matching the original source files provided.
// These should be used with the original source files provided when calling
// functions and declaring arrays.
#define INVOICES_COUNT 4
#define INVOICES_COLUMNS 4

#define CUSTOMERS_COUNT 3
#define CUSTOMERS_COLUMNS 5

#define ITEMS_COUNT 8
#define ITEMS_COLUMNS 4

#define DATAFIELD_LEN 21


/* Functions that are available for public use within the black box */

/**
 * Description:  Fills a 3-dimensional array with data from a specified file
 *
 * Parameters:
 *        rows - number of data rows in the file
 *     columns - number of data fields per row
 *   destArray - 3-dimensional array of appropriate size to populate with data
 *               1st dim - rows, uses the first parameter from function call
 *               2nd dim - columns, uses the second parameter from function call
 *               3rd dim - maximum text field length, prespecified.
 *    fileName - string, specifies the file name to read the data from.
 *
 * Return:       Integer. 1 will be returned, if the reading was successful.
 *
 * Side effects: The function may exit the program when an error occurs!
 */
int GetFileContents(int rows, int columns, char destArray[rows][columns][DATAFIELD_LEN], char *fileName);

/**
 * Description:  This function is used to test if the project was successfully
 *               assembled and the 'black box' is included. Print out the string
 *               to verify.
 * Parameters:   none
 * Return:       pointer to a string
*/
char *CheckStatus();

#endif /* IMPORT_H */

