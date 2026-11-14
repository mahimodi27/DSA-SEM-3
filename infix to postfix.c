#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[100];
int top = -1;

void push(char x) {
    if (top < MAX - 1) {
        stack[++top] = x;
    }
}

char pop() {
    if (top == -1) return -1;
    return stack[top--];
}

char peek() {
    if (top == -1) return -1;
    return stack[top];
}

int precedence(char x) {
    if (x == '^')
        return 3;
    if (x == '*' || x == '/' || x == '%')
        return 2;
    if (x == '+' || x == '-')
        return 1;
    return 0;
}

int main() {
    char infix[MAX], x;
    int i; 

    printf("Enter the infix expression: ");
    fgets(infix, MAX, stdin);

    printf("The postfix expression is: ");
    for (i = 0; infix[i] != '\0'; i++) {
        x = infix[i]; // FIX: Assign current character to x

        // Skip newline and carriage return characters from fgets
        if (x == '\n' || x == '\r' || x == ' ') {
            continue;
        }

        if (isalnum(x)) {
            printf("%c", x);
        }
        else if (x == '(') {
            push(x);
        }
        else if (x == ')') {
            while (top != -1 && peek() != '(') {
                printf("%c", pop());
            }
            if (top != -1) {
                pop(); // Remove '(' from stack
            }
        }
        else if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^') {
            while (top != -1 && peek() != '(' && 
                  (precedence(peek()) > precedence(x) || 
                  (precedence(peek()) == precedence(x) && x != '^'))) {
                printf("%c", pop());
            }
            push(x);
        }
    }

    // Pop any remaining operators from the stack
    while (top != -1) {
        printf("%c", pop());
    }
    
    printf("\n");
    return 0;
}