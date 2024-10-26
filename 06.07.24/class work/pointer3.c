#include <stdio.h>
int main()
{
    // int a[5] = {1, 10, 50, 20, 30};

    // int *p = &a;
    // printf("%d\n", *p);
    // printf("%d\n", *(p + 1));

    // char a[10] = "Sugam Shaw";
    // char *ch = a;

    // for (int i = 0; i < 10; i++)
    // {
    //     printf("%c ", ch[i]);
    // }

    char a[10] = "Sugam Shaw";
    char *ch = a;
    ch++;
    printf("%c\n", ch[0]);
    ch--;
    printf("%c\n", ch[0]);
    ++ch;
    printf("%c\n", ch[0]);
    --ch;
    printf("%c\n", ch[0]);
    *(--ch);
    printf("%c\n", ch[0]);
    return 0;
}