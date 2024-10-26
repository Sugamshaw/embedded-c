#include <stdio.h>

#define factorial(num) (num == 1 ? 1 : num * factorial(num - 1))

int main()
{
    int num = 5;
    printf("%d\n", factorial(num)); // Expected output: 120

    return 0;
}
