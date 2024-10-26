#include <stdio.h>
#include <stdlib.h>

int *multiple_values()
{
    int *values = malloc(3 * sizeof(int));
    values[0] = 1;
    values[1] = 20;
    values[2] = 3000;

    return values;
}

int main()
{
    int *values = multiple_values();

    printf("%d %d %d\n", values[0], values[1], values[2]);
    return 0;
}
