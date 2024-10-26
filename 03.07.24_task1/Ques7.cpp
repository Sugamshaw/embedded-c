//7.WACP to copy one string to another.

#include <stdio.h>

int main() {
    char source[100], destination[100];
    int i;

    printf("Enter a string:\n");
    gets(source);

    for (i = 0; source[i] != '\0'; ++i) {
        destination[i] = source[i];
    }
    destination[i] = '\0';  

    printf("Copied string: %s\n", destination);

    return 0;
}

