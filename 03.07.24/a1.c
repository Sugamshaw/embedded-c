#include <stdio.h>

int main() {
    unsigned int num;
    int position;
    printf("Enter a 32-bit number: ");
    scanf("%u", &num);
    printf("Enter the bit position (0-31): ");
    scanf("%d", &position);
    if (position < 0 || position > 31) {
        printf("Invalid bit position. Please enter a value between 0 and 31.\n");
        return 1;
    }
    int bitState = (num >> position) & 1;
    printf("The state of bit at position %d is %d.\n", position, bitState);

    return 0;
}
