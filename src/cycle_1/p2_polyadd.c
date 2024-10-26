#include <stdio.h>

int main() {
    int poly1[100], poly2[100], resultpoly[100], degree, i;
    
    printf("Enter the highest degree of the two polynomials: ");
    scanf("%d", &degree);
    printf("\nPolynomial 1\n");
    for (i = degree; i >= 0; i--) {
        printf("Enter coefficient of x^%d: ", i);
        scanf("%d", &poly1[i]);
    }
    printf("\nPolynomial 2\n");
    for (i = degree; i >= 0; i--) {
        printf("Enter coefficient of x^%d: ", i);
        scanf("%d", &poly2[i]);
    }
    for (i = degree; i >= 0; i--)
        resultpoly[i] = poly1[i] + poly2[i];
    printf("\nResult polynomial is ");
    for (i = degree; i >= 0; i--) {
        if (i == 0)
            printf("%d = 0\n", resultpoly[i]);
        else
            printf("%dx^%d + ", resultpoly[i], i);
    }
}