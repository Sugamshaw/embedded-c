#include <stdio.h>
#include <math.h>

float areaOfTriangle(float *base, float *height) {
    return 0.5 * (*base) * (*height);
}

float areaOfSquare(float *side) {
    return (*side) * (*side);
}

float areaOfCircle(float *radius) {
    return M_PI * (*radius) * (*radius);
}

float volumeOfSphere(float *radius) {
    return (4.0/3.0) * M_PI * pow(*radius, 3);
}

int main() {
    float base, height, side, radius;

    // Area of a triangle
    printf("Enter base and height of the triangle: ");
    scanf("%f %f", &base, &height);
    printf("Area of triangle: %f\n", areaOfTriangle(&base, &height));

    // Area of a square
    printf("Enter side of the square: ");
    scanf("%f", &side);
    printf("Area of square: %f\n", areaOfSquare(&side));

    // Area of a circle
    printf("Enter radius of the circle: ");
    scanf("%f", &radius);
    printf("Area of circle: %f\n", areaOfCircle(&radius));

    // Volume of a sphere
    printf("Enter radius of the sphere: ");
    scanf("%f", &radius);
    printf("Volume of sphere: %f\n", volumeOfSphere(&radius));

    return 0;
}
