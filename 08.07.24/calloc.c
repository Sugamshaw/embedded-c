#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr = (int *)calloc(16, sizeof(int));

    if (ptr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < 20; i++)
    {
        ptr[i] = i;
    }

    for (int i = 0; i < 20; i++)
    {
        printf("i %d : %d\n", i, ptr[i]);
    }
    printf("\n");

    free(ptr);
    return 0;
}
