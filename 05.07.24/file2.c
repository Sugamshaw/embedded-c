#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int main()
{
    FILE *fp1 = fopen("myfile.txt", "w");
    char str[] = "Hello bro";
    if (fp1 == NULL)
    {
        printf("error in opening the file\n");
        exit(1);
    }
    int count = fwrite(str, 1, sizeof(str), fp1);
    printf("the number of elements write: %d\n", count);
    fclose(fp1);

    FILE *fp2 = fopen("myfile.txt", "r");
    char buffer[100];
    if (fp2 == NULL)
    {
        printf("error in opening the file\n");
        exit(1);
    }
    int count2 = fread(&buffer, sizeof(char), 100, fp2);
    printf("Data: %s \n", buffer);
    printf("the number of elements read: %d\n", count2);
    fclose(fp2);

    FILE *fp3 = fopen("new.txt", "w");
    if (fp3 == NULL)
    {
        printf("error in opening the file\n");
        exit(1);
    }
    int count3 = fwrite(buffer, 1, count2, fp3);
    printf("new file write: %d\n", count3);
    fclose(fp3);
}