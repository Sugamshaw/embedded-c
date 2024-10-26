#include <stdio.h>

int main() {
    printf("\a"); // This sends the bell character to the terminal
    fflush(stdout); // Ensure the bell character is sent immediately
    return 0;
}
