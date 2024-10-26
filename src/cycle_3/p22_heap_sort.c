#include <stdio.h>
#define MAX_SIZE 100

void heapify(int arr[], int heap_size, int root) {
    int temp;
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < heap_size && arr[left] > arr[largest])
        largest = left;
    if (right < heap_size && arr[right] > arr[largest])
        largest = right;

    if (largest != root) {
        temp = arr[root];
        arr[root] = arr[largest];
        arr[largest] = temp;

        heapify(arr, heap_size, largest);
    }
}

void heap_sort(int arr[], int n) {
    int i, temp;

    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (i = n - 1; i > 0; i--) {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

int main() {
    int array[MAX_SIZE], n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the %d elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &array[i]);

    heap_sort(array, n);

    printf("The sorted elements are\n");
    for (i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
    return 0;
}