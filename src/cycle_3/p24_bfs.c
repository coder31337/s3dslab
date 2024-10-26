#include <stdio.h>
#define MAX_SIZE 100

void enqueue(int queue[], int* rear, int* front, int item) {
    if (*rear == MAX_SIZE - 1)
        printf("Queue full\n");
    else {
        if (*front == -1)
            *front = 0;
        *rear = *rear + 1;
        queue[*rear] = item;
    }
}

int dequeue(int queue[], int* rear, int* front, int* dequeued_item) {
    if (*front == -1 || *front > *rear)
        return 0;
    *dequeued_item = queue[*front];
    *front = *front + 1;
    return 1;
}

void breadth_first_search(int adj_mat[][MAX_SIZE], int n, int pnode, int path[]) {
    int queue[MAX_SIZE], status[MAX_SIZE];
    int i, j, rear, front;

    rear = -1; front = -1;
    j = 0;
    for (i = 0; i < n; i++)
        status[i] = 1;
    enqueue(queue, &rear, &front, pnode);
    status[pnode] = 2;
    while (front != -1) {
        if (!dequeue(queue, &rear, &front, &pnode))
            return;
        path[j] = pnode;
        j++;
        status[pnode] = 3;
        for (i = 0; i < n; i++) {
            if (adj_mat[pnode][i] == 1 && status[i] == 1) {
                enqueue(queue, &rear, &front, i);
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
    
    breadth_first_search(adj_matrix, n, 0, path);

    printf("\nThe BFS path is\n");
    for (i = 0; i < n; i++)
        printf("%d ", path[i]);
    printf("\n");
    return 0;
}