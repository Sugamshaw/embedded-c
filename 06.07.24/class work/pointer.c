#include <stdio.h>
int main()
{
    int a = 10;
    int *c = &a;
    int **p = &c;
    (**p)++;
    printf("%d\n", a);
    printf("%d\n", *c);
    printf("%d\n", **p);
    return 0;
}
