// 17.WACP to generate the patterns of square , triangles(only boundaries).

#include <stdio.h>
void square(int side)
{
    for (int i = 1; i <= side; i++)
    {
        for (int j = 1; j <= side; printf("* "), j++)
            ;
        ;
    }
}
void rectangle(int length, int breadth)
{
    for (int i = 1; i <= length; printf("\n"), i++)
    {
        for (int j = 1; j <= breadth; printf("* "), j++)
            ;
    }
}
void triangle(int side)
{
    for (int i = 1; i <= side; printf("\n"), i++)
    {
        
        for (int j = 1; j <= i; printf("* "), j++)
            ;
    }
}
void masti(int side)
{
    char c = 'A';
    int i, j;
    for (i = 1; i <= side; ++i)
    {
        for (j = 1; j <= side; ++j)
        {
            if (i == 1 || i == side || j == 1 || j == side)
                printf("* ");
            else
            {
                printf("%c ", c);
                // printf("A ");
                c++;
            }
        }
        printf("\n");
    }
}
void masti2(int side)
{
    char c = 'A';
    int i, j;
    for (i = 1; i <= side; ++i)
    {
        for (int k = 0; k <= side - i; printf(" "), k++)
            ;
        for (j = 1; j <= i; ++j)
        {

            if (i == side || j == 1 || j == i)
                printf("* ");
            else
            {

                printf("%c ", c);
                c++;
            }
        }
        printf("\n");
    }
}
int main()
{
    int side, height, i, j;

    // printf("Square\n");
    // square(10);
    // printf("Traingle\n");
    triangle(10);
    // printf("rectangle\n");
    // rectangle(5, 10);
    // printf("MAsti wala pattern\n");
    // masti2(10);
    // printf("Enter the side length of the square:\n");
    // scanf("%d", &side);

    // printf("Enter the height of the triangle:\n");
    // scanf("%d", &height);

    // printf("\nHollow Square Pattern:\n");
    // for (i = 1; i <= side; ++i)
    // {
    //     for (j = 1; j <= side; ++j)
    //     {
    //         if (i == 1 || i == side || j == 1 || j == side)
    //             printf("* ");
    //         else
    //             printf("  ");
    //     }
    //     printf("\n");
    // }

    // printf("\nHollow Triangle Pattern:\n");
    // for (i = 1; i <= height; ++i)
    // {
    //     for (j = 1; j <= i; ++j)
    //     {
    //         if (i == height || j == 1 || j == i)
    //             printf("* ");
    //         else
    //             printf("  ");
    //     }
    //     printf("\n");
    // }

    return 0;
}
