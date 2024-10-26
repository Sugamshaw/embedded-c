#include <stdio.h>
#include <conio.h>
#define func(a, b) a##b  //func(a, b): Concatenates the tokens a and b into a single token.
#define func2(a, b) #a #b //func2(a, b): Converts the tokens a and b into string literals.
int fun(int a, int b)
{
    return 10 * a + b;
}
int main()
{
    // FILE *fp1 = fopen("myfile.txt", "w");
    // if (fp1 == NULL)
    // {
    //     printf("Hi hi hi");
    //     exit(1);
    // }
    // fclose(fp1);
    printf("%d\n", func(9, 5));
    printf("%s", func2(hello, world));
    return 0;
}