#include <stdio.h>

int multiply(int *a, int *b) {
    int result = 0;
    int x = *a, y = *b;
    while (y != 0) {
        if (y & 1)
            result += x;
        x <<= 1;
        y >>= 1;
    }
    return result;
}

int main() {
    int a, b;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    printf("Product: %d\n", multiply(&a, &b));
    return 0;
}
