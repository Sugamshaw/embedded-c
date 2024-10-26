//4.WACP to print  all the factors of a number.

#include <stdio.h>

int main() {
    int n, i;

    printf("Enter a number:\n");
    scanf("%d", &n);

    printf("Factors of %d are:\n", n);
    for (i = 1; i <= n; i++) {
        if (n % i == 0) {
            printf("%d\n", i);
        }
    }

    return 0;
}

