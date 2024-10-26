//11.WACP to find wheather a number is strong number or not.

#include <stdio.h>

int factorial(int num) {
    if (num == 0 || num == 1)
        return 1;
    else
        return num * factorial(num - 1);
}

int isStrongNumber(int n) {
    int originalNum = n;
    int sum = 0;

    while (n > 0) {
        int digit = n % 10;
        sum += factorial(digit);
        n /= 10;
    }

    return (sum == originalNum);
}

int main() {
    int num;

    printf("Enter a number:\n");
    scanf("%d", &num);

    if (isStrongNumber(num))
        printf("%d is a strong number.\n", num);
    else
        printf("%d is not a strong number.\n", num);

    return 0;
}

