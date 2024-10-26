
#include <stdio.h>

int mul(int a, int b)
{
    int mul = 0;
    while (b--)
    {
        mul += a;
    }
    return mul;
}
int mulbit(int a, int b)
{
    int res = 0;
    while (b > 0)
    {
        if (b & 1)
        {
            res += a;
        }
        a = a << 1;
        b = b >> 1;
    }
    return res;
}

int main()
{

    // printf("%d \n", mulbit(50, 5));
    char a[5] = {'a', 'b', 'c', 'd', 's'};
    for(int i=0;i<5;i++)
    {
        if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')
        {
            
        }
    }
}