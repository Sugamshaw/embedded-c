#include <stdio.h>
#include <string.h>
// structure function
struct student
{
    char name[20];
    int roll;
    float marks;
};
void function(char name[20], int roll, float marks)
{
    printf("Name: %s\n", name);
    printf("Roll: %d\n", roll);
    printf("Marks: %f\n", marks);
}
void function1(struct student std)
{
    printf("Name: %s\n", std.name);
    printf("Roll: %d\n", std.roll);
    printf("Marks: %f\n", std.marks);
}
int main()
{

    struct student std = {"Sugam", 30, 50.265};
    function(std.name, std.roll, std.marks);
    function1(std);

    return 0;
}