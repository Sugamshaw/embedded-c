#include <stdio.h>
int main()
{
    int a = 10;
    void *ptr = &a;
    // printf("%lld\n", *(int *)ptr);
    printf("%d\n", *(int *)ptr);

    float b = 15;
    void *ptr2 = &b;
    printf("%f\n", *(float *)ptr2);
    // printf("%f\n", *(float *)ptr2);
    return 0;
}