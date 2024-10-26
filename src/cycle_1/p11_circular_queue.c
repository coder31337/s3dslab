#include <stdio.h>
#define SIZE 10

int main() {
    int cqueue[SIZE];
    int front, rear, choice, item, i;

    front = rear = -1;
    printf("\n\nCircular Queue operations\n");
    printf(" [1] Display\n");
    printf(" [2] Insert\n");
    printf(" [3] Delete\n");
    printf(" [4] Exit\n");
    while (1) {
        printf("\nEnter a choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (front == -1 && rear == -1) {
                printf("Queue is empty. Nothing to display.\n");
            } else {
                printf("Displaying circular queue...\n");
                for (i = front; i != rear; i = (i + 1) % SIZE)
                    printf("%d ", cqueue[i]);
                printf("%d ", cqueue[i]);
            }
        } else if (choice == 2) {
            if ((rear + 1) % SIZE == front) {
                printf("Queue is full. Cannot insert.\n");
            } else {
                printf("Enter the element to insert: ");
                scanf("%d", &item);
                if (front == -1 && rear == -1) {
                    front = rear = 0;
                    cqueue[rear] = item;
                } else {
                    rear = (rear + 1) % SIZE;
                    cqueue[rear] = item;
                }
                printf("%d added to circular queue\n", item);
            }
        } else if (choice == 3) {
            if (front == -1 && rear == -1) {
                printf("Queue is empty. Cannot delete.\n");
            } else {
                if (front == rear) {
                    item = cqueue[front];
                    front = rear = -1;
                } else {
                    item = cqueue[front];
                    front = (front + 1) % SIZE;
                }
                printf("%d deleted from circular queue\n", item);
            }
        } else if (choice == 4) {
            printf("Exiting...\n");
            break;
        } else {
            printf("INVALID CHOICE\n");
        }
    }
    return 0;
}