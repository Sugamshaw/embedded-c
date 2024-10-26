#include <stdio.h>
void func(int *a, int *b)
{
    *a += *b;
}
int main()
{
    int a = 10;
    int *p;
    int **q;
    p = &a;
    q = &p;
    printf("%d\n", p);
    printf("%d\n", q);
    printf("%d\n", *q);
    printf("%d\n", **q);
    printf("%d\n", &q);

    return 0;
}