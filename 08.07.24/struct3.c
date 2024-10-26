#include <stdio.h>

typedef struct
{
    unsigned int arr[] : 10;

} Date;
int main()
{
    Date date, nextDate;

    printf("Enter date (dd mm yyyy): ");
    scanf("%d %d %d", &date.day, &date.month, &date.year);

    if (!isValidDate(date))
    {
        printf("Invalid date entered.\n");
        return 1;
    }

    nextDate = getNextDate(date);

    printf("Next date is: %02d/%02d/%04d\n", nextDate.day, nextDate.month, nextDate.year);

    return 0;
}
