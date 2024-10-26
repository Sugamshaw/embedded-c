#include <stdio.h>

void printASCII() {
    for (int i = 32; i < 127; ++i) {
        printf("%d -> %c\n", i, (char)i);
    }
}

int main() {
    printASCII();
    return 0;
}
