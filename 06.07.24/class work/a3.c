#include <stdio.h>

void stringConcat(char *dest, char *src) {
    while (*dest) {
        dest++;
    }
    while (*src) {      
        *dest = *src;   
        dest++;         
        src++;          
    }
}

int main() {
    char str1[100] = "Hello, ";
    char *str2 = "World!";
    stringConcat(str1, str2);
    printf("Concatenated string: %s\n", str1);
    return 0;
}