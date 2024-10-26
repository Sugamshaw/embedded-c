#include <stdio.h>
#include <stdbool.h>

void printBinary(unsigned int num) {
    for (int i = 31; i >= 0; --i) {
        printf("%d", (num >> i) & 1);
        if (i % 4 == 0)
            printf(" ");
    }
    printf("\n");
}

void setBit(unsigned int *num, int pos) {
    *num |= (1 << pos);
}

void resetBit(unsigned int *num, int pos) {
    *num &= ~(1 << pos);
}

bool readBit(unsigned int num, int pos) {
    return (num >> pos) & 1;
}

void toggleBit(unsigned int *num, int pos) {
    *num ^= (1 << pos);
}

int main() {
    unsigned int num;
    int choice, pos;

    printf("Enter a number: ");
    scanf("%u", &num);

    while (true) {
        printf("\nCurrent number in binary: ");
        printBinary(num);

        printf("\nMenu:");
        printf("\n1. Set a bit");
        printf("\n2. Reset a bit");
        printf("\n3. Read a bit");
        printf("\n4. Toggle a bit");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter bit position to set (0-31): ");
                scanf("%d", &pos);
                setBit(&num, pos);
                break;
            case 2:
                printf("Enter bit position to reset (0-31): ");
                scanf("%d", &pos);
                resetBit(&num, pos);
                break;
            case 3:
                printf("Enter bit position to read (0-31): ");
                scanf("%d", &pos);
                if (readBit(num, pos))
                    printf("Bit at position %d is 1\n", pos);
                else
                    printf("Bit at position %d is 0\n", pos);
                break;
            case 4:
                printf("Enter bit position to toggle (0-31): ");
                scanf("%d", &pos);
                toggleBit(&num, pos);
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
                break;
        }
    }

    return 0;
}
