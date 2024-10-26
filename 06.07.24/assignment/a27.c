#include <stdio.h>

int readBit(int *byte, int *position) {
    return (*byte >> *position) & 1;
}

int main() {
    int byte, position;
    printf("Enter a byte (0-255): ");
    scanf("%d", &byte);
    printf("Enter bit position (0-7): ");
    scanf("%d", &position);
    printf("Bit at position %d: %d\n", position, readBit(&byte, &position));
    return 0;
}
