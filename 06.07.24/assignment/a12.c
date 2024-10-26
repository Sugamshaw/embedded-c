#include <stdio.h>
#include <ctype.h>

void countVowelsConsonants(char str[], int *vowels, int *consonants) {
    *vowels = 0;
    *consonants = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        char ch = tolower(str[i]);
        if (isalpha(ch)) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                (*vowels)++;
            else
                (*consonants)++;
        }
    }
}

int main() {
    char str[100];
    int vowels, consonants;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);
    countVowelsConsonants(str, &vowels, &consonants);

    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);

    return 0;
}
