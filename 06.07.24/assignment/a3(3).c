#include <stdio.h>

void checkEqual(int *a, int *b) {
    if ((*a - *b) == 0) {
        printf("The numbers are equal.\n");
    } else {
        printf("The numbers are not equal.\n");
    }
}

int main() {
    int a, b;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    checkEqual(&a, &b);
    return 0;
}
