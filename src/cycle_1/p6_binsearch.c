#include <stdio.h>

int main() {
    int array[100], n, i, target, low, high, mid, found = 0;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the %d sorted elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &array[i]);
    printf("Enter the element to search for: ");
    scanf("%d", &target);
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (array[mid] == target) {
            found = 1;
            break;
        } else if (array[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if (found)
        printf("Element found at position %d\n", mid + 1);
    else
        printf("Element not found\n");
    return 0;
}