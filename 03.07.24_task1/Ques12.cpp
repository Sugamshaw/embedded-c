//12.WACP to find wheather a number is aremstrong or not.

#include <stdio.h>
#include <math.h>

int countDigits(int num) {
    int count = 0;
    while (num != 0) {
        num /= 10;
        count++;
    }
    return count;
}


int isArmstrong(int n) {
    int originalNum = n;
    int numDigits = countDigits(n);
    int sum = 0;

    while (n > 0) {
        int digit = n % 10;
        sum += pow(digit, numDigits);
        n /= 10;
    }

    return (sum == originalNum);
}

int main() {
    int num;

    printf("Enter a number:\n");
    scanf("%d", &num);

    if (isArmstrong(num))
        printf("%d is an Armstrong number.\n", num);
    else
        printf("%d is not an Armstrong number.\n", num);

    return 0;
}

