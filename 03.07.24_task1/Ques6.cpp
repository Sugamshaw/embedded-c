// 6.WACP to print all visible ASCII values and ASCII characters using a c program.

#include <stdio.h>

int main()
{
    int i;

    printf("ASCII values and their corresponding characters:\n");
    for (i = 97; i <= 122; ++i)
    {
        printf("ASCII value %d: %c\n", i, i);
    }

    return 0;
}
