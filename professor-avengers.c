#include <stdio.h>
 
// constants
#define AVENGER_LIM 10
#define NAME_LIM 15
#define LOWER_LIMIT 1
 
// function prototypes
int GetAvengerCount(int minVal, int maxVal);
void FillMissionStats(char avenger[AVENGER_LIM][NAME_LIM], int disposeCount[],
                      int listLen);
double FindAvgBaddieDisposedOf(int disposeCount[], int listLen);
void DisplaySlackers(char avenger[AVENGER_LIM][NAME_LIM], int disposeCount[],
                     int avengerCount, double avgBaddiesDisposed);
 
int main(void)
{
    double avgBaddiesDisposed;
    char avengers[AVENGER_LIM][NAME_LIM];
    int disposeCount[AVENGER_LIM];
    int avengerCount = GetAvengerCount(LOWER_LIMIT, AVENGER_LIM);
    FillMissionStats(avengers, disposeCount, avengerCount);
    avgBaddiesDisposed = FindAvgBaddieDisposedOf(disposeCount, avengerCount);
    DisplaySlackers(avengers, disposeCount, avengerCount, avgBaddiesDisposed);
    return 0;
}
 
/**
 * Function to get a value in specified range. The range will be in between
 * the 2 passed integers. User will be prompted for a new value until
 * a suitable one is entered, after which the function will return the
 * specified value as an integer.
 */
int GetAvengerCount(int minVal, int maxVal)
{
    int count;
    do
    {
        printf("Enter avenger count between %d and %d\n", minVal, maxVal);
        scanf("%d", &count);
        if (count < minVal || count > maxVal)
            puts("I'm sorry, I can't handle that :(");
    }
    while (count < minVal || count > maxVal);
    return count;
}
 
/**
 * Fills in the baddies disposed of count and avengers who were on the
 * mission. Requires arrays where to store the data, function has no return.
 */
void FillMissionStats(char avenger[AVENGER_LIM][NAME_LIM], int disposeCount[],
                      int listLen)
{
    int i;
    for (i = 0; i < listLen; i++)
    {
        scanf("%s %d", avenger[i], &disposeCount[i]);
    }
}
 
/**
 * Takes the counts of baddies disposed of by the avengers on the mission
 * and finds the average amount. The average is returned as a double.'
 */
double FindAvgBaddieDisposedOf(int disposeCount[], int listLen)
{
    int i = 0;
    int sum = 0;
    while (i < listLen)
    {
        sum += disposeCount[i++];
        i++;
    }
    return (double)sum / (double)listLen;
}
 
/**
 * Takes the average of how many baddies were disposed of on the mission,
 * the count and list of avengers who were on the mission and their
 * corresponding counts of how many baddies they disposed of during it.
 * Outputs he ones who were goofing off and reports them to Fury.
 */
void DisplaySlackers(char avenger[AVENGER_LIM][NAME_LIM], int disposeCount[],
                     int avengerCount, double avgBaddiesDisposed)
{
    int i;
    printf("Total number of avengers in mission was %d\n", avengerCount);
    puts("Printing the list of avengers slacking off");
    printf("Average baddies disposed of was: %lg\n\n", avgBaddiesDisposed);
    for (i = 0; i < avengerCount; i++)
    {
        if (disposeCount[i] < avgBaddiesDisposed)
        {
            printf("%15s %3d\n", avenger[i], disposeCount[i]);
        }
    }
 
}
