#include <stdio.h>
#include <string.h>

int recursionstr(char *str)
{
    if (*str == '\0')
        return 0;

    return 1 + recursionstr(str + 1);
}
int stringLength(char *str)
{
    int len = 0;
    for (len = 0; str[len] != '\0'; len++)
        ;
    return len;
}
void reverseString(char *str)
{
    int length = stringLength(str);
    char temp;
    for (int i = 0; i < length / 2; temp = str[i], str[i] = str[length - i - 1], str[length - i - 1] = temp, i++)
        ;
}
int stringcomare(char *str1, char *str2)
{
    int length1 = stringLength(str1);
    int length2 = stringLength(str2);

    if (length1 > length2)
    {
        return 1;
    }
    if (length1 < length2)
    {
        return -1;
    }

    while (length1--)
    {
        if (str1[length1] > str2[length1])
        {
            return 1;
        }
        if (str1[length1] < str2[length1])
        {
            return -1;
        }
    }
    return 0;
}

void constring(char *str1, char *str2)
{
    int length1 = stringLength(str1);
    int length2 = stringLength(str2);
    while (str1[length1] != '\0')
    {
        length1++;
    }
    int i = 0;
    while (str2[i] != '\0')
    {
        str1[length1 + i] = str2[i];
        i++;
    }
    str1[length1 + i] = '\0';
}

int main()
{
    char str[100] = "sugam";

    printf("%d\n", recursionstr(str));
    // fgets(str, 100, stdin);
    // char str2[100]="shaw";
    // fgets(str2, 100, stdin);
    // str[constring(str,"\n")]
    // strcpy(str2, str);

    // int length = stringLength(str);
    // int length = recstr(str);
    // printf("Length of the string: %d\n", length);
    // reverseString(str2);
    // printf("Length of the string1: %s\n", str);
    // printf("Length of the string2: %s\n", str2);
    // printf("Value: %d\n", stringcomare(str, str2));
    // constring(str,str2);
    // char str[100];
    // fgets(str, 100, stdin);
    // fgets(str, 100, stdin);
    // char str2[100]="shaw";
    // fgets(str2, 100, stdin);

    printf("Ouput: %s\n", str);

    return 0;
}
