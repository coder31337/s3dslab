#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* link;
};

void display(struct Node** head) {
    struct Node* temp;
    if (*head == NULL) {
        printf("List is empty. Nothing to display.\n");
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

void insert_front(struct Node** head, int item) {
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->data = item;
    if (*head == NULL) {
        new->link = NULL;
        *head = new;
    } else {
        new->link = *head;
        *head = new;
    }
}

void insert_rear(struct Node** head, int item) {
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

void insert_at(struct Node** head, int key, int item) {
    struct Node* new;
    struct Node* temp;
    if (*head == NULL) {
        printf("List empty. Cannot insert.\n");
    } else {
        temp = *head;
        while ((temp->data != key) && (temp->link != NULL))
            temp = temp->link;
        if (temp->data != key) {
            printf("Key not found. Cannot insert.\n");
        } else {
            new = (struct Node*)malloc(sizeof(struct Node));
            new->data = item;
            new->link = temp->link;
            temp->link = new;
        }
    }
}

int delete_front(struct Node** head, int* del_item) {
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

int delete_rear(struct Node** head, int* del_item) {
    struct Node* temp;
    struct Node* prev;
    struct Node* curr;
    if (*head == NULL) {
        return 0;
    } else if ((*head)->link == NULL) {
        temp = *head;
        *head = NULL;
        *del_item = temp->data;
        free(temp);
        return 1;
    } else {
        prev = *head;
        curr = (*head)->link;
        while (curr->link != NULL) {
            prev = curr;
            curr = curr->link;
        }
        prev->link = NULL;
        *del_item = curr->data;
        free(curr);
        return 1;
    }
}

int delete_from(struct Node** head, int key) {
    struct Node* temp;
    struct Node* prev;
    struct Node* curr;
    if (*head == NULL) {
        printf("List empty. Cannot delete.\n");
        return 0;
    } else if ((*head)->data == key) {
        temp = *head;
        *head = (*head)->link;
        free(temp);
        return 1;
    } else {
        prev = *head;
        curr = *head;
        while ((curr->data != key) && (curr->link != NULL)) {
            prev = curr;
            curr = curr->link;
        }
        if (curr->data != key) {
            printf("Key not found. Cannot delete.\n");
            return 0;
        } else {
            prev->link = curr->link;
            free(curr);
            return 1;
        }
    }
}

int main() {
    struct Node* head = NULL;
    int choice, item, key;

    printf("\n\nSingly Linked List operations\n");
    printf(" [1] Display\n");
    printf(" [2] Insert at front\n");
    printf(" [3] Insert at rear\n");
    printf(" [4] Insert at position\n");
    printf(" [5] Delete from front\n");
    printf(" [6] Delete from rear\n");
    printf(" [7] Delete from position\n");
    printf(" [8] Exit\n");
    while (1) {
        printf("\nEnter a choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            display(&head);
        } else if (choice == 2) {
            printf("Enter the element to insert at front: ");
            scanf("%d", &item);
            insert_front(&head, item);
            printf("%d inserted at front\n", item);
        } else if (choice == 3) {
            printf("Enter the element to insert at rear: ");
            scanf("%d", &item);
            insert_rear(&head, item);
            printf("%d inserted at rear\n", item);
        } else if (choice == 4) {
            printf("Enter the element and key: ");
            scanf("%d %d", &item, &key);
            insert_at(&head, key, item);
            printf("%d inserted to list\n", item);
        } else if (choice == 5) {
            if (delete_front(&head, &item))
                printf("%d deleted from front\n", item);
            else
                printf("List empty. Cannot delete.\n");
        } else if (choice == 6) {
            if (delete_rear(&head, &item))
                printf("%d deleted from rear\n", item);
            else
                printf("List empty. Cannot delete.\n");
        } else if (choice == 7) {
            printf("Enter the key: ");
            scanf("%d", &key);
            if (delete_from(&head, key))
                printf("%d deleted from list\n", key);
        } else if (choice == 8) {
            printf("Exiting...\n");
            break;
        } else {
            printf("INVALID CHOICE\n");
        }
    }
    return 0;
}