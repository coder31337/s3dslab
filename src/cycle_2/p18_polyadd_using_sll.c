#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coef;
    int expo;
    struct Node* link;
};

struct Node* read_poly() {
    struct Node* phead = NULL;
    struct Node* new;
    int count, i;
    struct Node* temp = NULL;
    printf("Enter the number of non zero terms: ");
    scanf("%d", &count);
    printf("Enter the coefficient and exponent in order");
    for (i = 0; i < count; i++) {
        new = (struct Node*)malloc(sizeof(struct Node));
        printf("\nEnter coefficient: ");
        scanf("%d", &new->coef);
        printf("Enter exponent: ");
        scanf("%d", &new->expo);
        new->link = NULL;
        if (temp == NULL) {
            phead = temp = new;
        } else {
            temp->link = new;
            temp = new;
        }
    }
    temp->link = NULL;
    return phead;
}

void display_poly(struct Node* phead) {
    struct Node* temp = phead;
    while (temp->link != NULL) {
        printf("%dx^%d", temp->coef, temp->expo);
        temp = temp->link;
        if (temp->link != NULL) printf(" + ");
    }
    printf(" + %dx^%d", temp->coef, temp->expo);
    printf("\n");
}

struct Node* add_poly(struct Node* ptr1, struct Node* ptr2) {
    struct Node* result_head;
    struct Node* new;
    struct Node* rptr = NULL;

    while (ptr1 != NULL && ptr2 != NULL) {
        new = (struct Node*)malloc(sizeof(struct Node));
        new->link = NULL;
        if (ptr1->expo > ptr2->expo) {
            new->coef = ptr1->coef;
            new->expo = ptr1->expo;
            ptr1 = ptr1->link;
        } else if (ptr2->expo > ptr1->expo) {
            new->coef = ptr2->coef;
            new->expo = ptr2->expo;
            ptr2 = ptr2->link;
        } else {
            new->coef = ptr1->coef + ptr2->coef;
            new->expo = ptr1->expo;
            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        }
        if (rptr == NULL) {
            result_head = new;
            rptr = new;
            rptr->link = NULL;
        } else {
            rptr->link = new;
            rptr = new;
            rptr->link = NULL;
        }
    }
    while (ptr1 != NULL) {
        new = (struct Node*)malloc(sizeof(struct Node));
        new->link = NULL;
        new->coef = ptr1->coef;
        new->expo = ptr1->expo;
        ptr1 = ptr1->link;
        if (rptr == NULL) {
            result_head = new;
            rptr = new;
            rptr->link = NULL;

        } else {
            rptr->link = new;
            rptr = new;
            rptr->link = NULL;
        }
    }
    while (ptr2 != NULL) {
        new = (struct Node*)malloc(sizeof(struct Node));
        new->link = NULL;
        new->coef = ptr2->coef;
        new->expo = ptr2->expo;
        ptr2 = ptr2->link;
        if (rptr == NULL) {
            result_head = new;
            rptr = rptr->link;
            rptr->link = NULL;

        } else {
            rptr->link = new;
            rptr = new;
            rptr->link = NULL;
        }
    }
    return result_head;
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* sum_poly = NULL;

    printf("\nPolynomial 1\n");
    poly1 = read_poly();
    printf("Entered polynomial 1 = ");
    display_poly(poly1);

    printf("\n\nPolynomial 2\n");
    poly2 = read_poly();
    printf("Entered polynomial 2 = ");
    display_poly(poly2);

    sum_poly = add_poly(poly1, poly2);
    printf("\nSum polynomial = ");
    display_poly(sum_poly);
    return 0;
}