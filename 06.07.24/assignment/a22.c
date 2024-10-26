#include <stdio.h>
#include <math.h>

int countDigits(int num) {
    int count = 0;
    while (num != 0) {
        count++;
        num /= 10;
    }
    return count;
}

int isArmstrongNumber(int *num) {
    int sum = 0, temp = *num, digits = countDigits(*num);
    while (temp > 0) {
        sum += pow(temp % 10, digits);
        temp /= 10;
    }
    return sum == *num;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (isArmstrongNumber(&num)) {
        printf("%d is an Armstrong Number.\n", num);
    } else {
        printf("%d is not an Armstrong Number.\n", num);
    }
    return 0;
}
