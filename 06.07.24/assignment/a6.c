#include <stdio.h>

void sumEvenOdd(int *arr, int n, int *sumEven, int *sumOdd) {
    *sumEven = 0;
    *sumOdd = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] % 2 == 0) {
            *sumEven += arr[i];
        } else {
            *sumOdd += arr[i];
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    int sumEven, sumOdd;
    sumEvenOdd(arr, n, &sumEven, &sumOdd);
    printf("Sum of even numbers: %d\n", sumEven);
    printf("Sum of odd numbers: %d\n", sumOdd);
    return 0;
}
