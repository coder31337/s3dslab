#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_SIZE 100

void push(int stack[], int* top, int item) {
    if (*top < MAX_SIZE - 1) {
        stack[++(*top)] = item;
    } else {
        printf("ERROR: Stack full\n");
        exit(-1);
    }
}

int pop(int stack[], int* top) {
    int item;
    if (*top > -1) {
        item = stack[*top];
        stack[(*top)--] = -1;
        return item;
    }
    printf("ERROR: Stack empty\n");
    exit(-1);
}

int main() {
    char postfix_expr[MAX_SIZE], ch;
    int stack[MAX_SIZE], top;
    int i, x, y, result;

    top = -1;
    for (i = 0; i < MAX_SIZE; i++) {
        stack[i] = -1;
    }

    printf("Enter a postfix expression: ");
    scanf("%s", postfix_expr);

    for (i = 0; postfix_expr[i] != '\0'; i++) {
        ch = postfix_expr[i];
        if (isdigit(ch)) {
            push(stack, &top, ch - '0');
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            y = pop(stack, &top);
            x = pop(stack, &top);
            switch (ch) {
                case '+':
                    result = x + y;
                    break;
                case '-':
                    result = x - y;
                    break;
                case '*':
                    result = x * y;
                    break;
                case '/':
                    result = x / y;
                    break;
            }
            push(stack, &top, result);
        } else {
            printf("ERROR: Invalid characters in input\n");
            return(-1);
        }
    }
    result = pop(stack, &top);
    printf("The postfix evaluation is %d\n", result);
    return 0;
}