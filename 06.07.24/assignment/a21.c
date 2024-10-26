#include <stdio.h>

int factorial(int n) {
    if (n == 0) return 1;
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int isStrongNumber(int *num) {
    int sum = 0, temp = *num;
    while (temp > 0) {
        sum += factorial(temp % 10);
        temp /= 10;
    }
    return sum == *num;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (isStrongNumber(&num)) {
        printf("%d is a Strong Number.\n", num);
    } else {
        printf("%d is not a Strong Number.\n", num);
    }
    return 0;
}
