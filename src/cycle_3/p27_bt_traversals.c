#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

struct Node* create(struct Node* node, int value) {
    if (node == NULL) {
        node = (struct Node*)malloc(sizeof(struct Node));
        node->value = value;
        node->left = NULL;
        node->right = NULL;
    } else if (value < node->value) {
        node->left = create(node->left, value);
    } else if (value > node->value) {
        node->right = create(node->right, value);
    } else if (value == node->value) {
        printf("Duplicate value cannot be inserted\n");
    }
    return node;
}

void preorder(struct Node* node) {
    if (node != NULL) {
        printf("%d ", node->value);
        preorder(node->left);
        preorder(node->right);
    }
}

void inorder(struct Node* node) {
    if (node != NULL) {
        inorder(node->left);
        printf("%d ", node->value);
        inorder(node->right);
    }
}

void postorder(struct Node* node) {
    if (node != NULL) {
        postorder(node->left);
        postorder(node->right);
        printf("%d ", node->value);
    }
}

int main() {
    struct Node* node = NULL;
    int choice, node_count, i, value;

    printf("Binary tree operations\n");
    printf("  [1] Add tree\n");
    printf("  [2] Preorder traversal\n");
    printf("  [3] Inorder traversal\n");
    printf("  [4] Postorder traversal\n");
    printf("  [5] Exit\n");
    while (1) {
        printf("\nEnter a choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter the number of nodes: ");
            scanf("%d", &node_count);
            printf("Enter the node values level wise: ");
            for (i = 0; i < node_count; i++) {
                scanf("%d", &value);
                node = create(node, value);
            }
        } else if (choice == 2) {
            printf("Displaying preorder traversal...\n");
            preorder(node);
            printf("\n");
        } else if (choice == 3) {
            printf("Displaying inorder traversal...\n");
            inorder(node);
            printf("\n");
        } else if (choice == 4) {
            printf("Displaying postorder traversal...\n");
            postorder(node);
            printf("\n");
        } else if (choice == 5) {
            printf("Exiting...\n");
            break;
        } else {
            printf("INVALID CHOICE\n");
        }
    }
    return 0;
}