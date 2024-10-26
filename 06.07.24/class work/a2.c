#include <stdio.h>

void stringCopy(char *dest, char *src)
{
    while (*src)
    {
        *dest = *src;
        // printf("%c , % p\n", *dest, *src);
        dest++;
        src++;
    }
}

int main()
{
    char *source = "Hello, World!";
    char destination[50];
    stringCopy(destination, source);
    printf("Copied string: %s\n", destination);
    return 0;
}