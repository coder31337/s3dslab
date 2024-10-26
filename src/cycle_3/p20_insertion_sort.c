#include <stdio.h>
#define MAX_SIZE 100

int main() {
    int array[MAX_SIZE], n, i, j, temp;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the %d elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &array[i]);
    
    for (i = 1; i < n; i++) {
        temp = array[i];
        for (j = i; j > 0 && temp < array[j - 1]; j--)
            array[j] = array[j - 1];
        array[j] = temp;
    }

    printf("The sorted elements are\n");
    for (i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
    return 0;
}