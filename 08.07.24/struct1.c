#include <stdio.h>
#pragma pack(1) // structure packing
struct student
{
    char name[50];
    int age;
    float height;
};

struct information
{
    int a;
    int b;
    int result;
};
struct information sum1(struct information *std)
{
    struct information std1;
    std1.result = std->a + std->b;
    return std1;
}
int main()
{
    // struct information std1, std2, *ptr;
    // std1.a = 10;
    // std1.b = 20;
    // std1.result = 0;
    // std2 = sum1(&std1);
    // printf("%d\n", std2.result);
    // printf("%lld\n", sizeof(ptr));

    struct student s;
    printf("%lld\n", sizeof(s));

    return 0;
}