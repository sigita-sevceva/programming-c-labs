#include <stdio.h>
#include <string.h>

#define PASS_SIZE 25
#define MAX_SIZE 100

int Menu(void);
int GetIntInRange(int min, int max);
void GetInp(char s[], unsigned max);
void PasswordCheck();
void SentenceLength();
void SearchWord(char* searchWord);
void CombineText(char* str2);

int main()
{
	int menuSelection;
	char newSentence[MAX_SIZE];
	char str1[MAX_SIZE];
	char str2[MAX_SIZE];
	char key[MAX_SIZE]; 
	int count = 0;
	
	do
    {
        menuSelection = Menu();
        switch (menuSelection)
        {
            case 1:
                {
					PasswordCheck();
					break;
				}
			case 2:
				{
					SentenceLength(str1);
					count++;
					break;
				}
			case 3:
				if (count > 0)
				{
					SearchWord(key);
					break;
				}
				else
				{
					puts("Generate a sentence first!");
					break;
				}
            case 4:
                {
					CombineText(str2);
					strcpy(newSentence, str2);
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
    puts("Select Your action:");
    puts("1 - Password check");
    puts("2 - Check sentence length");
    puts("3 - Check whether in sentence");
    puts("4 - Sentence combining");
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
    getchar();
    return num;
}
/**
 * Function:       GetInPut
 *
 * Description:    Asks the user for an integer in between the given limits.
 *                 Repeats until requirements are met and then returns the number.
 */
void GetInp(char s[], unsigned max)
{
	fgets(s, max, stdin);
	s[strlen(s) - 1] = '\0';
}
/**
 * Function:       PasswordCheck
 *
 * Description:    Asks the user to enter a password, checks whether its valid.
 *                 Repeats until requirements are met and then returns the number.
 *
 * Parameters:     min - integer, lower limit for the user input (inclusive)
 *                 max - integer, upper limit for the user input (inclusive)
 *
 * Return:         Integer, number within the specified limits
 */
void PasswordCheck()
{
	char password[PASS_SIZE] = "password123";
	char userPass[PASS_SIZE];
	
	do
	{
		puts("Please enter the correct password: \n");
		fgets(userPass, PASS_SIZE, stdin);
	}
	while (strcmp(password, userPass) != 0);
	
	printf("The length of password is %lu \n", strlen(userPass));
}
/**
 * Function:       SentenceLength
 *
 * Description:    Asks the user for a sentence.
 *                 Shows length.
 *
 * Parameters:     min - integer, lower limit for the user input (inclusive)
 *                 max - integer, upper limit for the user input (inclusive)
 *
 * Return:         Integer, number within the specified limits
 */
void SentenceLength(char* str1)
{
	char userSentence[MAX_SIZE];
	
	puts("Please enter a sentence (max 100 chars): \n");
	GetInp(userSentence, MAX_SIZE);

	strcpy(str1, userSentence);
	printf("The entered sentence contains: %lu characters!", strlen(userSentence));
}
/**
 * Function:       Search for a word
 *
 * Description:    Searches whether the word is found in the previously generated sentence.
 *                 
 *
 * Parameters:     min - integer, lower limit for the user input (inclusive)
 *                 max - integer, upper limit for the user input (inclusive)
 *
 * Return:         Integer, number within the specified limits
 */
 void SearchWord(char* str1)
 {
	 char searchWord[MAX_SIZE];
	 char *needle;
	 
	 puts("Enter a word to search in the previously generated sentence: \n");
	 GetInp(searchWord, MAX_SIZE);
	 needle = (strstr(str1, searchWord));
	 if (needle == NULL)
	 {
		 puts("The word is in the sentence.");
	 }
	 else 
	 {
		 puts("The word is not in the sentence.");
	 }
	 
 }
 /**
 * Function:       CombineText
 *
 * Description:    Asks the user for 2 words.
 *                 Combines them into a sentence.
 *
 * Parameters:     min - integer, lower limit for the user input (inclusive)
 *                 max - integer, upper limit for the user input (inclusive)
 *
 * Return:         Integer, number within the specified limits
 */
void CombineText(char* str2)
{
	char str1[MAX_SIZE];
	char word1[PASS_SIZE];
	char word2[PASS_SIZE];
	
	puts("Enter the first word: ");
	GetInp(word1, PASS_SIZE);
	puts("Enter the second word: ");
	GetInp(word2, PASS_SIZE);
	
	strcpy(str1, word1);
	strncat(str1, " is an ", MAX_SIZE);
	strncat(str1, word2, MAX_SIZE);
	strncat(str1, " person!", MAX_SIZE);
	printf("%s", str1);
}
	
