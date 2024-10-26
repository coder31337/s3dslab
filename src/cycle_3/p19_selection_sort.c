#include <stdio.h>
#define MAX_SIZE 100

int main() {
    int array[MAX_SIZE], n, i, j, temp, min;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the %d elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &array[i]);
    
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (array[j] < array[min])
                min = j;
        }
        if (min != i) {
            temp = array[i];
            array[i] = array[min];
            array[min] = temp;
        }
    }

    printf("The sorted elements are\n");
    for (i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
    return 0;
}