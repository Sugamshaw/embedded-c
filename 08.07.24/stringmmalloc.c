#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap1(char *x, char *y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
}

void sortString(char *str)
{
    int n = strlen(str);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (*(str + i) > *(str + j))
            {
                swap1((str + i), (str + j));
            }
        }
    }
}

void stringReverse(char *str)
{
    char *start = str;
    char *end = str;
    char temp;
    while (*end)
    {
        end++;
    }
    end--;

    while (start < end)
    {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

void stringConcat(char *dest, char *src)
{
    while (*dest)
    {
        dest++;
    }
    while (*src)
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}
void stringCopy(char *dest, const char *src)
{
    while ((*dest++ = *src++))
        ;
}

int stringLength(const char *str)
{
    const char *ptr = str;
    while (*ptr)
        ptr++;
    return (size_t)(ptr - str);
}

int main()
{
    char *str = (char *)malloc(20 * sizeof(char));
    if (str == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    stringCopy(str, "Hello, World!");
    printf("Original String: %s\n", str);

    int len = stringLength(str);
    printf("Length of String: %i\n", len);

    sortString(str);
    printf("Sorted String: %s\n", str);

    stringReverse(str);
    printf("Reversed String: %s\n", str);

    char *additionalStr = " Welcome!";
    stringConcat(str, additionalStr);
    printf("Concatenated String: %s\n", str);

    free(str);

    return 0;
}
