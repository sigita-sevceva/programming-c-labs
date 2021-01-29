#include <stdio.h>
 
#define F_LEN_NAME 13
#define F_LEN_AGE 3
#define F_LEN_ID 6
#define F_LEN_WAGE 5
 
int main(void)
{
    char *names[] = {"Ott", "Dolores", "Johanna-Maria"};
    int employeeNum[] = {7, 19, 2123};
    int ages[] = {22, 19, 53};
    float wages[] = {13, 8.95, 10.1};
    int i;
    printf("%-*s  %*s  %*s  %*s\n", F_LEN_NAME, "name",
                                    F_LEN_AGE, "age",
                                    F_LEN_ID, "id #",
                                    F_LEN_WAGE, "wage");
    for (i = 0; i < 3; i++)
    {
        printf("%-*s  %*d  %0*d  %*.2f\n", F_LEN_NAME, names[i],
                                           F_LEN_AGE, ages[i],
                                           F_LEN_ID, employeeNum[i],
                                           F_LEN_WAGE, wages[i]);
    }
    return 0;
}
