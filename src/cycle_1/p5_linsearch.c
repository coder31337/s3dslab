#include <stdio.h>

int main() {
    int array[100], n, i, target, found = 0;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the %d elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &array[i]);
    printf("Enter the element to search for: ");
    scanf("%d", &target);
    for (i = 0; i < n; i++) {
        if (array[i] == target) {
            found = 1;
            break;
        }
    }
    if (found)
        printf("Element found at position %d\n", i + 1);
    else
        printf("Element not found\n");
    return 0;
}