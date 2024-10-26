#include <stdio.h>

typedef struct {
    unsigned int day : 5;   // 5 bits for day (0-31)
    unsigned int month : 4; // 4 bits for month (0-15)
    unsigned int year : 11; // 11 bits for year (0-2047)
} Date;

int isLeapYear(int year)
{
    if (year % 400 == 0)
        return 1;
    if (year % 100 == 0)
        return 0;
    if (year % 4 == 0)
        return 1;
    return 0;
}

int getDaysInMonth(int month, int year)
{
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        if (isLeapYear(year))
            return 29;
        else
            return 28;
    default:
        return 0;
    }
}

int isValidDate(Date date)
{
    if (date.year < 1)
    {
        return 0;
    }
    if (date.month < 1 || date.month > 12)
    {
        return 0;
    }
    int daysInMonth = getDaysInMonth(date.month, date.year);
    if (date.day < 1 || date.day > daysInMonth)
    {
        return 0;
    }
    return 1;
}

Date getNextDate(Date date)
{
    Date nextDate = date;
    int daysInMonth = getDaysInMonth(date.month, date.year);

    if (date.day < daysInMonth)
    {
        nextDate.day++;
    }
    else
    {
        nextDate.day = 1;
        if (date.month == 12)
        {
            nextDate.month = 1;
            nextDate.year++;
        }
        else
        {
            nextDate.month++;
        }
    }
    return nextDate;
}

int main()
{
    Date date, nextDate;
    int input_day, input_month, input_year;

    printf("Enter date (dd mm yyyy): ");
    scanf("%d %d %d", &input_day, &input_month, &input_year);

    // Assigning values to bit-fields
    date.day = input_day;
    date.month = input_month;
    date.year = input_year;

    if (!isValidDate(date))
    {
        printf("Invalid date entered.\n");
        return 1;
    }

    nextDate = getNextDate(date);

    printf("Next date is: %02d/%02d/%04d\n", nextDate.day, nextDate.month, nextDate.year);

    return 0;
}