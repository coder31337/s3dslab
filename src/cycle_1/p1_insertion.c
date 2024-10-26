#include <stdio.h>

int main() {
    int array[100], n, i, new;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the %d elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &array[i]);
    printf("Enter the new element to be inserted at the beginning: ");
    scanf("%d", &new);
    for (i = n-1; i >= 0; i--)
        array[i + 1] = array[i];
    array[0] = new;
    n++;
    printf("Array after insertion: [ ");
    for (i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("]\n");
    return 0;
}