#include <stdio.h>

void findGreatestSmallest(int *a, int *b, int *c, int *greatest, int *smallest) {
    *greatest = (*a > *b) ? ((*a > *c) ? *a : *c) : ((*b > *c) ? *b : *c);
    *smallest = (*a < *b) ? ((*a < *c) ? *a : *c) : ((*b < *c) ? *b : *c);
}

int main() {
    int a, b, c, greatest, smallest;
    printf("Enter three integers: ");
    scanf("%d %d %d", &a, &b, &c);
    findGreatestSmallest(&a, &b, &c, &greatest, &smallest);
    printf("Greatest: %d\n", greatest);
    printf("Smallest: %d\n", smallest);
    return 0;
}
