#include <stdio.h>
#include <ctype.h>

int get_precedence(char operator) {
    switch (operator) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}

int main() {
    char infix[100], postfix[100], stack[100];
    int i, j, top;

    printf("Enter an infix expression: ");
    scanf("%s", infix);
    top = -1;
    i = j = 0;
    while (infix[i] != '\0') {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(') {
            stack[++top] = infix[i];
        }
        else if (infix[i] == ')') {
            while (top > -1 && stack[top] != '(')
                postfix[j++] = stack[top--];
            top--;
        }
        else if (get_precedence(infix[i]) > 0) {
            while (get_precedence(stack[top])
                    >= get_precedence(infix[i])
                    && top > -1)
                postfix[j++] = stack[top--];
            stack[++top] = infix[i];
        }
        i++;
    }
    while (top > -1) {
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';
    printf("The postfix expression is %s\n", postfix);
    return 0;
}