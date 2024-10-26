#include <stdio.h>
int main()
{
    char *ptr[3];
    char arr[] = "Hello";
    char arr1[] = "world";
    ptr[0] = arr;
    ptr[1] = arr1;
    printf("Output: %s\n", ptr[0]);
    printf("Output: %s\n", ptr[1]);
    printf("Output: %s\n", ptr[2]);
    return 0;
}