#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr = (int *)malloc(16);
    // int *ptr = (int *)malloc(16 * sizeof(int));
    if (ptr == NULL)
    {
        printf("Not allocated");
    }
    else
    {
        for (int i = 0; i < 20; i++)
        {
            ptr[i] = i;
        }
        for (int i = 0; i < 20; i++)
        {
            printf("i %d: %d\n", i + 1, ptr[i]);
        }
    }
    free(ptr);

    return 0;
}
