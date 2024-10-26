#include <stdio.h>

int reverseDigits(int *num) {
    int reversed = 0;
    while (*num != 0) {
        reversed = reversed * 10 + *num % 10;
        *num /= 10;
    }
    return reversed;
}

int main() {
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);
    int reversed = reverseDigits(&num);
    printf("Reversed number: %d\n", reversed);
    return 0;
}
