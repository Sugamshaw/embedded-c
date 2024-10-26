// 14.WACP to use preprocessor constants in GCC.

#include <stdio.h>

// Define constants using #define directives
#define PI 3.14159
#define MAX_VALUE 100
#define MESSAGE "Hello, World!"

int main() {
    // Using the defined constants
    printf("Value of PI: %.5f\n", PI);
    printf("Maximum value: %d\n", MAX_VALUE);
    printf("Message: %s\n", MESSAGE);

    return 0;
}

