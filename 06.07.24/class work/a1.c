#include <stdio.h>

int stringLength(char *str)
{
    char *s = str;
    while (*s)
    {
        s++;
    }
    return s - str;
}

int main()
{
    char *text = "Hello, World!";
    printf("Length of '%s' is %d\n", text, stringLength(text));
    return 0;
}