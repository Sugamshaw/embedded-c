#include <stdio.h>

int toggleBit(int *byte, int *position) {
    return *byte ^ (1 << *position);
}

int main() {
    int byte, position;
    printf("Enter a byte (0-255): ");
    scanf("%d", &byte);
    printf("Enter bit position (0-7): ");
    scanf("%d", &position);
    printf("Byte after toggling bit at position %d: %d\n", position, toggleBit(&byte, &position));
    return 0;
}
