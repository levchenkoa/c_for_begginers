#include <stdio.h>

int is_leap(int);

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: определяет день года по месяцу и дню */
int day_of_year(int year, int month, int day)
{
    char *p;
    int leap;
    if (year < 1918 || month < 1 || month > 12 || day < 1)
         return -1;
    leap = is_leap(year);
    p = daytab[leap];
    while(p < daytab[leap] + month)
        day += *p++;
    return day;
}

char *month_name(int n)
{
    static char *name[] = {"Неверный месяц","Январь","Февраль","Март","Апрель","Май","Июнь","Июль","Август","Сентябрь","Октябрь","Ноябрь","Декабрь"};

    return (n < 1 || n > 12) ? name[0] : name[n];


}

/* month_day: определяет месяц и день по дню года */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    char *p;
    int leap;
    *pmonth = *pday = 0;
    if (year < 1918 || yearday < 1 || yearday > 366)
         return;
    leap = is_leap(year);
    p = daytab[leap];

    while(yearday > *p){
        yearday -= *p++;

    }

    *pmonth += p - daytab[leap];
    *pday = yearday;
}

int is_leap(int year)
{
    return  ((year % 4 == 0) && (year % 100 !=0)) || (year % 400 == 0);
}

int main(){
    int month;
    int day;
    int year = 3020;
    int nday = 36;
    month_day(year, nday, &month, &day);
    printf("%d день в %d году: %d %s %d\n", nday, year, day, month_name(month), year);
    printf("%d %s %d: это %d день в %d году.\n",day, month_name(month), year, nday, year);
}
