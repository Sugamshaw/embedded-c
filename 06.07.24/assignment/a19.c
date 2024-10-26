#include <stdio.h>
#include <string.h>

void concatenateString(char destination[], char source[]) {
    int dest_len = strlen(destination);
    int i;
    for (i = 0; source[i] != '\0'; ++i) {
        destination[dest_len + i] = source[i];
    }
    destination[dest_len + i] = '\0';
}

int main() {
    char str1[100], str2[100];
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str1[strcspn(str1, "\n")] = '\0'; // Remove the newline character from first string
    concatenateString(str1, str2);
    printf("Concatenated string: %s", str1);
    return 0;
}
