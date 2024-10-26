#include <stdio.h>
#include <string.h>
//structure pointer
struct student
{
    char name[20];
    int roll;
    float marks;
};
int main()
{

    struct student std, std2, *ptr;

    ptr = &std;
    strcpy(ptr->name, "Sugam");
    ptr->roll = 1;
    ptr->marks = 90.5;

    printf("Name: %s\n", ptr->name);
    printf("Roll: %d\n", ptr->roll);
    printf("Marks: %f\n", ptr->marks);
    printf("Size : %lld\n", sizeof(std));
    printf("Size : %lld\n", sizeof(ptr));
    return 0;
}