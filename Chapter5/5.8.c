#include <stdio.h>

int is_leap(int);

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: определяет день года по месяцу и дню */
int day_of_year(int year, int month, int day)
{
    int i, leap;
    if (year < 1918 || month < 1 || month > 12 || day < 1)
         return -1;
    leap = is_leap(year);
    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

/* month_day: определяет месяц и день по дню года */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    if (year < 1918 || yearday < 1 || yearday > 366)
         return;
    leap = is_leap(year);
    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}

int is_leap(int year)
{
    return  ((year % 4 == 0) && (year % 100 !=0)) || (year % 400 == 0);
}
