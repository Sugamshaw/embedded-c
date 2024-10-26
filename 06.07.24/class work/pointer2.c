#include <stdio.h>
int func(int ***a, int ***b)
{
    ***a ^= ***b;
}
int main()
{
    int a = 5;
    int b = 4;

    int *p = &a;
    int **q = &p;
    int ***r = &q;

    int *p1 = &b;
    int **q1 = &p1;
    int ***r1 = &q1;

    func(r, r1);
    printf("%d\n", a);

    char c = 'a';
    char *s = &c;
    printf("%d\n", sizeof(s));

    return 0;
}
