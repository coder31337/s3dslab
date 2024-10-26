#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* link;
};

void display(struct Node** top) {
    struct Node* temp;
    if (*top == NULL) {
        printf("Stack empty. Nothing to display\n");
    } else {
        temp = *top;
        printf("Displaying stack...\n");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}

void push(struct Node** top, int item) {
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->data = item;
    if (*top == NULL) {
        new->link = NULL;
        *top = new;
    } else {
        new->link = *top;
        *top = new;
    }
}

int pop(struct Node** top, int* del_item) {
    struct Node* temp;
    if (*top == NULL) {
        return 0;
    } else {
        temp = *top;
        *top = (*top)->link;
        *del_item = temp->data;
        free(temp);
        return 1;
    }
}

int main() {
    struct Node* top = NULL;
    int choice, item;

    printf("\nLinked List Stack operations\n");
    printf(" [1] Display\n");
    printf(" [2] Push\n");
    printf(" [3] Pop\n");
    printf(" [4] Exit\n");
    while (1) {
        printf("\nEnter a choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            display(&top);
        } else if (choice == 2) {
            printf("Enter the element to push: ");
            scanf("%d", &item);
            push(&top, item);
            printf("%d pushed to stack\n", item);
        } else if (choice == 3) {
            if (pop(&top, &item))
                printf("%d popped from stack\n", item);
            else
                printf("Stack empty. Cannot pop.\n");
        } else if (choice == 4) {
            printf("Exiting...\n");
            break;
        } else {
            printf("INVALID CHOICE\n");
        }
    }
    return 0;
}