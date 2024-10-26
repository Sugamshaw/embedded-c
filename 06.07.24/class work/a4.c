#include <stdio.h>

void stringReverse(char *str) {
    char *start = str;
    char *end = str;
    char temp;
    while (*end) {
        end++;
    }
    end--;

    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main() {
    char text[50] = "Hello, World!";
    stringReverse(text);
    printf("Reversed string: %s\n", text);
    return 0;
}