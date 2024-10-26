#include <stdio.h>
#define MAX_SIZE 100

void depth_first_search(int adj_mat[][MAX_SIZE], int n,
                        int pnode, int path[]) {
    int stack[MAX_SIZE], status[MAX_SIZE];
    int i, j, top;

    top = -1;
    j = 0;
    for (i = 0; i < n; i++)
        status[i] = 1;
    stack[++top] = pnode;
    status[pnode] = 2;
    while (top != -1) {
        pnode = stack[top--];
        path[j] = pnode;
        j++;
        status[pnode] = 3;
        for (i = 0; i < n; i++) {
            if (adj_mat[pnode][i] == 1 && status[i] == 1) {
                stack[++top] = i;
                status[i] = 2;
            }
        }
    }
}

int main() {
    int adj_matrix[MAX_SIZE][MAX_SIZE], path[MAX_SIZE];
    int n, i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj_matrix[i][j]);
    
    depth_first_search(adj_matrix, n, 0, path);

    printf("\nThe DFS path is\n");
    for (i = 0; i < n; i++)
        printf("%d ", path[i]);
    printf("\n");
    return 0;
}