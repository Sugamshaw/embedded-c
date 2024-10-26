//1.WACP to find the greatest/smallest of 3 numbers using ternary operator.
#include <stdio.h>

int main() {
    int a, b, c;
    int largest, smallest;

    printf("Enter three numbers:\n");
    scanf("%d %d %d", &a, &b, &c);

    largest = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
    smallest = (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);

    printf("Largest number is: %d\n", largest);
    printf("Smallest number is: %d\n", smallest);

    return 0;
}

