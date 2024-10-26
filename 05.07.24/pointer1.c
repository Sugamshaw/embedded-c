#include <stdio.h>
void func(int *a, int *b)
{
    *a += *b;
}
int main()
{
    int a1 = 10;
    int b1 = 20;
    func(&a1, &b1);
    printf("%d \n", a1);
    return 0;
}