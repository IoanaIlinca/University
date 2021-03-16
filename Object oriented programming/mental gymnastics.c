#include <stdio.h>
#include <string.h>

int main()
{
    char initial_date_text[100];
    int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, sums[100], countersums = 0;
    scanf("%s", initial_date_text);
    while (strcmp(initial_date_text, "exit") != 0) /* calculates the number of days in the year so far, given the date */
    {
        long day, sum = 0, year;
        long month = -1;
        char month_text[100], year_text[100];
        strcpy(month_text, initial_date_text + 3); /* copies from the month onwards */
        strcpy(year_text, initial_date_text + 6); /* copies from the year onwards */
        day = strtol(initial_date_text, initial_date_text + 2, 10); /* saves the day in an integer, format dd-mm-yyyy */
        month = strtol(month_text, month_text + 2, 10); /* saves the month in an integer */
        year = strtol(year_text, year_text + 4, 10); /* saves the year in an integer */
        int iterator = 0;
        for (iterator; iterator < month - 1; ++iterator)
            sum += months[iterator];

        sum += day;

        if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && month > 2) /* leap year formula, which also checks if februrary has ended */
            sum++;
        sums[countersums++] = sum;

        scanf("%s", initial_date_text);
    }

    int iterator = 0;
    for (iterator = 0; iterator < countersums; iterator++)
        printf("%d ", sums[iterator]);


    return 0;
}

