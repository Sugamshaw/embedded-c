#include <stdio.h>

void findFactorial(int *num, int *factorial) {
    *factorial = 1;
    for (int i = 1; i <= *num; ++i) {
        *factorial *= i;
    }
}

int main() {
    int num, factorial;
    printf("Enter an integer: ");
    scanf("%d", &num);
    findFactorial(&num, &factorial);
    printf("Factorial of %d is %d\n", num, factorial);
    return 0;
}
