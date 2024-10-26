#include <stdio.h>
typedef enum week
{
    Mon,
    Tues,
    wed,
    Thru,
    Fri,
    Sat,
    Sun
} _week_;
int main()
{
    _week_ day = Mon;

    while (day <= Sun)
    {
        printf("%d\n", day);
        day++;
    }
    printf("\n\n");
    day = (_week_)3;

    while (day <= Sun)
    {
        printf("%d\n", day);
        day++;
    }
    return 0;
}