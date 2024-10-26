#include <stdio.h>
int fun(const int *p)
{
    int i = *p;
    i++;
    return i;
}
int fun2(int (*p)(const int))
{
    int a = *p;
    a++;
    return a;
}
int main()
{
    int a = 5;
    int (*ptr)(const int *) = fun;
    a = fun2(ptr(&a));
    printf("%d", a);
}