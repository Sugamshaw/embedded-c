#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) //
{
    FILE *fp1 = fopen(argv[1], "r");
    FILE *fp2 = fopen(argv[2], "w");
    char ch;
    printf("%d\n", argc);
    printf("%s\n", argv[0]);
    printf("%s\n", argv[1]);
    printf("%s\n", argv[2]);
    if (fp1 == NULL)
    {
        printf("error in opening the file\n");
        exit(1);
    }
    if (fp2 == NULL)
    {
        printf("error in opening the file\n");
        exit(1);
    }

    while ((ch = fgetc(fp1)) != EOF)
    {
        fputc(ch, fp2);
    }

    fclose(fp1);
    fclose(fp2);
}