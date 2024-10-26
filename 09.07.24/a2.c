#include <stdio.h>

void print()
{

    int i;

    char ch[] = "abcde";

    int res = 0;

    for (i = 0; i < 5; i++)
    {

        res += (ch[i] - 'a');
    }

    printf("%d", res);
}

int main()
{
    print();
    return 0;
}