#include <stdio.h>

int *function(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int *add(int a, int b)
{
    int *result = (a + b);
    return result;
}
int main()
{
    int a = 10;
    int b = 120;
    int *value = add(a, b);
    printf("%d\n", value);
}