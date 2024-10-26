#include <stdio.h>

int isLeapYear(int *year) {
    if (*year % 400 == 0) return 1;
    if (*year % 100 == 0) return 0;
    if (*year % 4 == 0) return 1;
    return 0;
}

int main() {
    int year;
    printf("Enter a year: ");
    scanf("%d", &year);
    if (isLeapYear(&year)) {
        printf("%d is a Leap Year.\n", year);
    } else {
        printf("%d is not a Leap Year.\n", year);
    }
    return 0;
}
