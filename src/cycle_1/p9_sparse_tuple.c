#include <stdio.h>
#define MAX_SIZE 100

int main() {
    int sparse_matrix[MAX_SIZE][MAX_SIZE];
    int tuple_matrix[MAX_SIZE][3];
    int rows, cols, i, j, k;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    printf("Enter the element at the given index\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &sparse_matrix[i][j]);
        }
    }

    printf("\n\nThe matrix is\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d\t", sparse_matrix[i][j]);
        }
        printf("\n");
    }

    tuple_matrix[0][0] = rows;
    tuple_matrix[0][1] = cols;
    k = 1;
    for (i = 0; i < tuple_matrix[0][0]; i++) {
        for (j = 0; j < tuple_matrix[0][1]; j++) {
            if (sparse_matrix[i][j]) {
                tuple_matrix[k][0] = i;
                tuple_matrix[k][1] = j;
                tuple_matrix[k][2] = sparse_matrix[i][j];
                k++;
            }
        }
    }
    tuple_matrix[0][2] = k - 1;

    printf("\n\nThe tuple matrix is\n");
    for (i = 0; i <= tuple_matrix[0][2]; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d\t", tuple_matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}