//5.WACP to print convert lower case character to upper case and vice versa in a string.

#include <stdio.h>
#include <ctype.h>

int main() {
    char str[100];
    int i;

    printf("Enter a string:\n");
    gets(str);

    for (i = 0; str[i] != '\0'; ++i) {
        if (islower(str[i])) {
            str[i] = toupper(str[i]);
        } else if (isupper(str[i])) {
            str[i] = tolower(str[i]);
        }
    }

    printf("Converted string: %s\n", str);

    return 0;
}

