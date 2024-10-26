#include <stdio.h>
#include <string.h>
const int MAX = 100;
int main()
{
    // get() has no boundary, so we can use fgets()
    //  char a[50];
    //  scanf("%s",a);
    // scanf("%[^\n]s", arr);
    //  printf("%s", a);

    // char arr[10];
    // char arr1[101];
    // gets(arr);
    // // gets(arr);
    // fgets(arr, 100, stdin);
    // // scanf("%[^\n]s", arr);
    // fgets(arr, MAX, stdin);
    // printf("sd s::");
    // fgets(arr1, MAX, stdin);
    // int res = strcmp(arr, arr1); //return 0 or -1
    // printf("%d", res);
    // printf("%lld\n", strlen(arr));
    // for (int i = 0; i < strlen(arr); i++)
    // {
    //     printf("%c\n", arr[i]);
    // }
    // printf("%s", arr);

    char arr[10] = "abcd ";
    char arr1[101] = "sds DSssc";
    // strcpy(arr, arr1);
    // strcat(arr, arr1);
    // puts(arr);
    // strrev(arr1);
    // strupr(arr1);
    // strlwr(arr1);
    puts(arr1);

    // printf("%s", arr);
    return 0;
}