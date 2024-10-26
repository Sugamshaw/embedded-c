#include <stdio.h>

int main()
{
    int var = 10;    
    int *ptr = &var;                                                      
    printf("Size of value pointed to by ptr: %zu bytes\n", sizeof(*ptr));
    return 0;
}
