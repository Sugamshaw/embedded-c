#include <stdio.h>

void printFactors(int *num) {
    printf("Factors of %d are: ", *num);
    for (int i = 1; i <= *num; ++i) {
        if (*num % i == 0) printf("%d ", i);
    }
    printf("\n");
}

int main() {
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);
    printFactors(&num);
    return 0;
}
