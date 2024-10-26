#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap1(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

void sortString(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (*(str + i) > *(str + j)) {
                swap1((str + i), (str + j));
            }
        }
    }
}

int main() {
    char buffer[100];
    printf("Enter a string: ");
    fgets(buffer, sizeof(buffer), stdin);

    // Remove the newline character if present
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }

    // Dynamically allocate memory for the string
    char *str = (char *)malloc((len + 1) * sizeof(char));
    if (str == NULL) {
        printf("Memory allocation failed\n");
        return 1; // Exit with error if allocation fails
    }

    // Copy the input string to the allocated memory
    strcpy(str, buffer);

    // Sort the string
    sortString(str);

    // Print the sorted string
    printf("Sorted string: %s\n", str);

    // Free the allocated memory
    free(str);

    return 0;
}
