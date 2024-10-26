#include <stdio.h>

int resetBit(int *byte, int *position) {
    return *byte & ~(1 << *position);
}

int main() {
    int byte, position;
    printf("Enter a byte (0-255): ");
    scanf("%d", &byte);
    printf("Enter bit position (0-7): ");
    scanf("%d", &position);
    printf("Byte after resetting bit at position %d: %d\n", position, resetBit(&byte, &position));
    return 0;
}
