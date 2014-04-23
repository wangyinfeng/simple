/*====================================================================
 * Description: count the days since my baby born
 * DATE: 2014/04/23
 * Modify:
 * Conclusion: Is there any better way to calculate the days?
 ===================================================================*/
/* include */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/* Macro definition */
#define false           0
#define true            1

#define INIT_YEAR       2014
#define INIT_MONTH      2
#define INIT_DAY        6
#define INIT_PASSED_DAY 37

char month_length[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int is_leap_year(int year)
{
    if ((year%4 == 0) && (year%100!=0) || (year%400==0))
        return 1;
    else
        return 0;
}

int
main(int argc, char** argv)
{
    int this_year;
    int this_month;
    int this_day;
    time_t rawtime;
    int day_from_init = 0;
    int leap_add = 0;
    int i;

    time(&rawtime); 
    struct tm *timeinfo = localtime(&rawtime);
//#define TEST
#if defined TEST
    printf("now: %d-%d-%d %d:%d:%d\n", 
            timeinfo->tm_year + 1900, 
            timeinfo->tm_mon + 1, 
            timeinfo->tm_mday, 
            timeinfo->tm_hour, 
            timeinfo->tm_min, 
            timeinfo->tm_sec);
#endif
    this_year = timeinfo->tm_year+1900;
    this_month = timeinfo->tm_mon+1;
    this_day = timeinfo->tm_mday;

    if(this_year < INIT_YEAR)
        return 1;

#if defined TEST
    {
        this_year = 2014;
        this_month = 5;
        this_day = 17;
    }
#endif

    day_from_init = (this_year - INIT_YEAR)*365;
    for(i=0;i<this_month;i++)
        day_from_init += month_length[i];
    day_from_init += this_day;
    day_from_init -= INIT_PASSED_DAY;
    if(this_year-INIT_YEAR >0){
        for(i=INIT_YEAR; i<=this_year; i++)
            if(is_leap_year(i))
                leap_add++;
        if(this_month < 2 || (this_month == 2 && this_day <29))
            leap_add--;
    }
    day_from_init += leap_add;

    if (day_from_init >= 0)
        printf("The angel has come for %d days.\n", day_from_init);

    return 0;
}

