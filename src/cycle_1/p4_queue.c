#include <stdio.h>
#define MAX_SIZE 10

int main() {
    int queue[MAX_SIZE], choice, element, i;
    int front = -1, rear = -1;
    
    while (1) {
        printf("\nQueue operations\n");
        printf("[1] Enqueue\n");
        printf("[2] Dequeue\n");
        printf("[3] Display\n");
        printf("[4] Exit\n");
        printf("Enter a choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            if (rear == MAX_SIZE - 1)
                printf("Queue is full. Cannot enqueue.\n");
            else {
                printf("Enter the element to enqueue: ");
                scanf("%d", &element);
                if (front == -1)
                    front = 0;
                rear++;
                queue[rear] = element;
                printf("%d added to queue\n", element);
            }
        } else if (choice == 2) {
            if (front == -1)
                printf("Queue is empty. Cannot dequeue.\n");
            else {
                element = queue[front];
                printf("%d removed from queue\n", element);
                front++;
                if (front > rear)
                    rear = front = -1;
            }
        } else if (choice == 3) {
            if (front == -1)
                printf("Queue is empty. Nothing to display.\n");
            else {
                printf("Displaying queue...\n\n");
                printf(" F");
                for (i = front; i <= rear; i++)
                    printf("| %d ", queue[i]);
                printf("|R\n");
            }
        } else if (choice == 4) {
            printf("Quiting\n");
            break;
        } else
            printf("INVALID CHOICE\n");
    }
    return 0;
}