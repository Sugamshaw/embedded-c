#include <stdio.h>
int main()
{
    unsigned int num;
    int pos;
    scanf("%u", &num);
    scanf("%d", &pos);

    int result = (num >> pos) & 1;
    
    printf("Result : %d", result);

    // printf("%d", printf("hello"));
}