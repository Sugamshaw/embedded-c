#include <stdio.h>

void checkEvenOdd(int *num) {
    if (*num % 2 == 0) {
        printf("%d is even.\n", *num);
    } else {
        printf("%d is odd.\n", *num);
    }
}

int main() {
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);
    checkEvenOdd(&num);
    return 0;
}
