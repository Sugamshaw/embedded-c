#include <stdio.h>

void checkEndianness() {
    unsigned int num = 1;
    char *c = (char*)&num;
    if (*c) {
        printf("Little Endian\n");
    } else {
        printf("Big Endian\n");
    }
}

int main() {
    checkEndianness();
    return 0;
}
