#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* link;
};

void display(struct Node** head) {
    struct Node* temp;
    if (*head == NULL) {
        printf("Queue empty. Nothing to display.\n");
    } else {
        temp = *head;
        printf("Displaying list...\n");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}

void enqueue(struct Node** head, int item) {
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp;
    new->data = item;
    new->link = NULL;
    if (*head == NULL) {
        *head = new;
    } else {
        temp = *head;
        while (temp->link != NULL)
            temp = temp->link;
        temp->link = new;
    }
}

int dequeue(struct Node** head, int* del_item) {
    struct Node* temp;
    if (*head == NULL) {
        return 0;
    } else {
        temp = *head;
        *head = (*head)->link;
        *del_item = temp->data;
        free(temp);
        return 1;
    }
}

int main() {
    struct Node* head = NULL;
    int choice, item;

    printf("\nLinked List Queue operations\n");
    printf(" [1] Display\n");
    printf(" [2] Enqueue\n");
    printf(" [3] Dequeue\n");
    printf(" [4] Exit\n");
    while (1) {
        printf("\nEnter a choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            display(&head);
        } else if (choice == 2) {
            printf("Enter the element to enqueue: ");
            scanf("%d", &item);
            enqueue(&head, item);
            printf("%d added to queue\n", item);
        } else if (choice == 3) {
            if (dequeue(&head, &item))
                printf("%d removed from queue\n", item);
            else
                printf("Queue empty. Cannot dequeue.\n");
        } else if (choice == 4) {
            printf("Exiting...\n");
            break;
        } else {
            printf("INVALID CHOICE\n");
        }
    }
    return 0;
}