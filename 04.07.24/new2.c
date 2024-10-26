#include <stdio.h>
#define SUM(a, b) (a + b)
#define DIFF(a, b) (a - b)
#define PROD(a, b) (a * b)
#define DIV(a, b) (a / b)
#define TEST 5
#define SETBIT(num, pos) (num | (1 << pos))
int main()
{
    // printf("what to print sum: %d\n", SUM(10, 20));

    // #undef TEST
    // #ifndef TEST
    // #if TEST > 2
    //     printf("hello");
    // #else
    //     printf("bye");
    // #endif
    // #endif
    printf("output: ", setbit(10, 2));
    return 0;
}