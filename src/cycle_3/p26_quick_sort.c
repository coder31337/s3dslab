#include <stdio.h>
#define MAX_SIZE 100

int partition(int arr[], int low, int high) {
    int pivot, temp, i, j;

    pivot = arr[high];
    i = low - 1;
    for (j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quick_sort(int arr[], int low, int high) {
    int pivot_index;
    if (low < high) {
        pivot_index = partition(arr, low, high);
        quick_sort(arr, low, pivot_index - 1);
        quick_sort(arr, pivot_index + 1, high);
    }
}

int main() {
    int array[MAX_SIZE], n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the %d elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &array[i]);

    quick_sort(array, 0, n - 1);

    printf("The sorted elements are\n");
    for (i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
    return 0;
}