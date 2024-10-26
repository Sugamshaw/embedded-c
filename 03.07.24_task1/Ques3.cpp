//3.WACP to find wheather the number is prime or not.

#include <stdio.h>

int main() {
    int n, i, temp = 0;

    printf("Enter a number:\n");
    scanf("%d", &n);

    if (n <= 1) {
        temp = 1;
    } else {
        for (i = 2; i <= n / 2; ++i) {
            if (n % i == 0) {
                temp = 1;
                break;
            }
        }
    }

    if (temp == 0) {
        printf("%d is a prime number.\n", n);
    } else {
        printf("%d is not a prime number.\n", n);
    }

    return 0;
}

