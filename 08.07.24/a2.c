#include <stdio.h>
int fun(const int *p)
{
    int i = *p;
    i++;
    return i;
}
int main()
{
    int a = 5;
    int (*ptr)(const int*)=fun;
    a = ptr(&a);
    printf("%d", a);
}