#include <stdio.h>
#define MAX_SIZE 100

void merge(int arr[], int lower, int mid, int upper) {
    int i, j, k, sub_arr[MAX_SIZE];

    i = lower;
    j = mid + 1;
    k = lower;
    while (i <= mid && j <= upper) {
        if (arr[i] <= arr[j]) {
            sub_arr[k] = arr[i];
            i++;
            k++;
        } else {
            sub_arr[k] = arr[j];
            j++;
            k++;
        }
    }
    if (i > mid) {
        while (j <= upper) {
            sub_arr[k] = arr[j];
            j++;
            k++;
        }
    } else {
        while (i <= mid) {
            sub_arr[k] = arr[i];
            i++;
            k++;
        }
    }
    for (k = lower; k <= upper; k++)
        arr[k] = sub_arr[k];
}

void merge_sort(int arr[], int lower, int upper) {
    int mid;
    if (lower < upper) {
        mid = (lower + upper) / 2;
        merge_sort(arr, lower, mid);
        merge_sort(arr, mid + 1, upper);
        merge(arr, lower, mid, upper);
    }
}

int main() {
    int array[MAX_SIZE], n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the %d elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &array[i]);
    
    merge_sort(array, 0, n - 1);

    printf("The sorted elements are\n");
    for (i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
    return 0;
}