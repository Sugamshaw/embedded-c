//17.WACP to generate the patterns of square , triangles(only boundaries).

#include <stdio.h>

int main() {
    int side, height, i, j;

    printf("Enter the side length of the square:\n");
    scanf("%d", &side);

    printf("Enter the height of the triangle:\n");
    scanf("%d", &height);

    printf("\nHollow Square Pattern:\n");
    for (i = 1; i <= side; ++i) {
        for (j = 1; j <= side; ++j) {
            if (i == 1 || i == side || j == 1 || j == side)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }

    printf("\nHollow Triangle Pattern:\n");
    for (i = 1; i <= height; ++i) {
        for (j = 1; j <= i; ++j) {
            if (i == height || j == 1 || j == i)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }

    return 0;
}

