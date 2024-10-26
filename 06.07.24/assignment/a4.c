#include <stdio.h>

int sumOfDigits(int *num) {
    if (*num == 0)
        return 0;
    int last_digit = *num % 10;
    *num /= 10;
    return last_digit + sumOfDigits(num);
}

int main() {
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);
    int sum = sumOfDigits(&num);
    printf("Sum of digits: %d\n", sum);
    return 0;
}
