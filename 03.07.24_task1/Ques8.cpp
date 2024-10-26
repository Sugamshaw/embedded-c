//8.WACP to reverse a string.

#include <stdio.h>
#include <string.h>

int main() {
    char str[100], reversed_str[100];
    int i, len;

    printf("Enter a string:\n");
    gets(str);

    len = strlen(str);

    for (i = 0; i < len; ++i) {
        reversed_str[i] = str[len - 1 - i];
    }
    reversed_str[len] = '\0';  

    printf("Reversed string: %s\n", reversed_str);

    return 0;
}

