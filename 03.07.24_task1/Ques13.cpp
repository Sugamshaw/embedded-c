// 13.WACP to find a wheather a processor is endian or not using type cat.

#include <stdio.h>

int main()
{
    unsigned int num = 1;
    char *c = (char *)&num;

    if (*c)
    {
        printf("Processor is Little-Endian\n");
    }
    else
    {
        printf("Processor is Big-Endian\n");
    }

    return 0;
}
