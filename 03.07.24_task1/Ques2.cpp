//2.WACP to find the area of a trangle, square, circle, volume of a sphere.

#include <stdio.h>
#include <math.h>

int main() {
    float base, height, side, radius, area_triangle, area_square, area_circle, volume_sphere;
    const float PI = 3.14159;

    printf("Enter the base and height of the triangle:\n");
    scanf("%f %f", &base, &height);
    area_triangle = 0.5 * base * height;
    printf("Area of the triangle: %.2f\n", area_triangle);

    printf("Enter the side length of the square:\n");
    scanf("%f", &side);
    area_square = side * side;
    printf("Area of the square: %.2f\n", area_square);

    printf("Enter the radius of the circle:\n");
    scanf("%f", &radius);
    area_circle = PI * radius * radius;
    printf("Area of the circle: %.2f\n", area_circle);

    printf("Enter the radius of the sphere:\n");
    scanf("%f", &radius);
    volume_sphere = (4.0/3.0) * PI * pow(radius, 3);
    printf("Volume of the sphere: %.2f\n", volume_sphere);

    return 0;
}

