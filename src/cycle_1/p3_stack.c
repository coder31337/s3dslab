#include <stdio.h>
#define MAX_SIZE 10

int main() {
    int stack[MAX_SIZE], choice, element, i;
    int top = -1;
    
    while (1) {
        printf("\nStack operations\n");
        printf("[1] Push\n");
        printf("[2] Pop\n");
        printf("[3] Display\n");
        printf("[4] Exit\n");
        printf("Enter a choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            if (top == MAX_SIZE - 1)
                printf("Stack is full. Cannot push.\n");
            else {
                printf("Enter the element to push: ");
                scanf("%d", &element);
                top++;
                stack[top] = element;
                printf("%d pushed to stack\n", element);
            }
        } else if (choice == 2) {
            if (top == -1)
                printf("Stack is empty. Cannot pop.\n");
            else {
                element = stack[top];
                printf("%d popped from stack\n", element);
                top--;
            }
        } else if (choice == 3) {
            if (top == -1)
                printf("Stack is empty. Nothing to display.\n");
            else {
                printf("Displaying stack...\n\n");
                for (i = top; i >= 0; i--)
                    printf("| %d\t|\n", stack[i]);
                printf("+-------+\n");
            }
        } else if (choice == 4) {
            printf("Quiting\n");
            break;
        } else
            printf("INVALID CHOICE\n");
    }
    return 0;
}