#include <stdio.h>

// #define READ_BIT(byte, pos) ((*byte >> *pos) & 1)
#define READ_BIT(byte, pos) ((*byte & (1 << *pos)) ? 1 : 0)
#define SET_BIT(byte, pos) (*byte | (1 << *pos))
#define RESET_BIT(byte, pos) (*byte & ~(1 << *pos))
#define TOGGLE_BIT(byte, pos) (*byte ^ (1 << *pos))

int main()
{
    int byte, position;
    printf("Enter a byte (0-255): ");
    scanf("%d", &byte);
    printf("Enter bit position (0-7): ");
    scanf("%d", &position);

    printf("Bit at position %d: %d\n", position, READ_BIT(&byte, &position));
    printf("Byte after setting bit at position %d: %d\n", position, SET_BIT(&byte, &position));
    printf("Byte after resetting bit at position %d: %d\n", position, RESET_BIT(&byte, &position));
    printf("Byte after toggling bit at position %d: %d\n", position, TOGGLE_BIT(&byte, &position));

    return 0;
}
