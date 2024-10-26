#include <stdio.h>
#define SETBIT(num, pos) (num | (1 << pos))
#define CLEARBIT(num, pos) (num & ~(1 << pos))
#define TOGGLEBIT(num, pos) (num ^ (1 << pos))
#define reverseBits(num) ({                       \
    unsigned int reversed = 0;                    \
    int bits = 0;                                 \
    unsigned int temp = num;                      \
    unsigned int temp1 = num;                     \
    while (temp > 0)                              \
    {                                             \
        temp >>= 1;                               \
        bits++;                                   \
    }                                             \
    for (int i = 0; i < bits; i++)                \
    {                                             \
        reversed = (reversed << 1) | (temp1 & 1); \
        temp1 >>= 1;                              \
    }                                             \
    reversed;                                     \
})

int main()
{
    // printf("output: %d\n", SETBIT(10, 2));
    // printf("output: %d\n", CLEARBIT(10, 1));
    // int num = 10;
    // for (int i = 1; i <= 4; i++)
    // {
    //     num = TOGGLEBIT(num, 1);
    //     printf("output: %d\n", num);
    // }
    // printf("output: %d\n", num);
    int num=10;
    int result = reverseBits(5);
    int result = reverseBits(5);
    printf("%d\n", result);  // Expected output: 5

    return 0;
}
