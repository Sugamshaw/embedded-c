
#include <stdio.h>

int even()
{
    int n;
    scanf("%d", &n);
    if (n & 1)
    {
        printf("odd");
    }
    else
    {
        printf("even");
    }
}
int swap()
{
    int a = 10, b = 20;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    printf("a= %d, b= %d\n", a, b);
}
int swapadd()
{
    int a = 10, b = 20;
    a = a + b;
    b = a - b;
    a = a - b;
    printf("a= %d, b= %d\n", a, b);
}
int swapmul()
{
    int a = 10, b = 20;
    a = a * b;
    b = a / b;
    a = a / b;
    printf("a= %d, b= %d\n", a, b);
}
int complement()
{
    int a = 10, b = 20;
    if (a & ~b)
    {
        printf("not equal");
    }
    else
    {
        printf("equal");
    }
}
int sumdigit(int a)
{
    int res = 0;
    while (a != 0)
    {
        int d = a % 10;
        res = res + d;
        a = a / 10;
    }
    return res;
}

int sumdigitrecursion(int a)
{
    //     if (a == 0)
    //         return 0;
    //     return (a % 10) + sumdigitrecursion(a / 10);
    // }
    return a == 0 ? 0 : (a % 10) + sumdigitrecursion(a / 10);
}
int sumevendigitrecursion(int a)
{
    return a == 0 ? 0 : (a % 2 == 0) ? (a % 10) + sumevendigitrecursion(a / 10)
                                     : sumevendigitrecursion(a / 10);
}
int sumodddigitrecursion(int a)
{
    return a == 0 ? 0 : (a % 2) ? (a % 10) + sumodddigitrecursion(a / 10)
                                : sumodddigitrecursion(a / 10);
}
int matrix(int a[3][3])
{
}
int main()
{
    // swap();
    // swapadd();
    // swapmul();

    // complement();
    // printf("%d", sumdigit(1234));
    // printf("%d \n", sumevendigitrecursion(123548));
    // printf("%d \n", sumodddigitrecursion(123548));
    int arr[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j)
            {
                arr[i][j] = 1;
            }
            else
            {
                arr[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}