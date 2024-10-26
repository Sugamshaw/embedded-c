#include <stdio.h>
#include <conio.h>
struct student
{
    char name[20];
    int roll;
    float marks;
};
int main()
{
    int i = 0;
    struct student s[5];
    for (i = 0; i < 5; i++)
    {
        printf("Input data no.: %d\n", i + 1);
        printf("Name: "), scanf("%s", s[i].name);
        printf("roll: "), scanf("%d", &s[i].roll);
        printf("marks: "), scanf("%f", &s[i].marks);
    }

    FILE *fp = fopen("myfile.txt", "w");

    for (i = 0; i < 5; i++)
    {
        fprintf(fp, "%d, Name: %s, Roll: %d, Marks: %.2f\n", i+1, s[i].name, s[i].roll, s[i].marks);
    }

    fclose(fp);

    return 0;
}