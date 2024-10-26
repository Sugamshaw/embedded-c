#include <stdio.h>

#define factorial(num) (num <= 1 ? 1 : num * factorial(num - 1))

int main()
{
    int num = 5;
    printf("%d\n", factorial(num));

    return 0;
}
