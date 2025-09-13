#include <stdio.h>
#include <string.h>
#include <ctype.h>

char infix[100], postfix[100], stack[100];
int top = -1, size = 0;

int priority(char x) {
    switch(x) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

void push(char ch) {
    top++;
    stack[top] = ch;
}

char pop() {
    return stack[top--];
}

char peek() {
    return (top >= 0) ? stack[top] : '\0';
}

int isEmpty() {
    return top == -1;
}

void infixToPostfix() {
    int len = strlen(infix);
    for(int i = 0; i < len; i++) {
        char ch = infix[i];
        if(isspace(ch)) continue;
        if(isalnum(ch)) postfix[size++] = ch;
        else if(ch == '(') push(ch);
        else if(ch == ')') {
            while(!isEmpty() && peek() != '(') {
                postfix[size++] = pop();
            }
            if(!isEmpty()) pop(); // Remove '('
        }
        else {
            while(!isEmpty() && peek() != '(' && 
                  priority(peek()) >= priority(ch)) {
                postfix[size++] = pop();
            }
            push(ch);
        }
    }
    while(!isEmpty()) postfix[size++] = pop();
    postfix[size] = '\0';
}

int main() {
    printf("Enter Infix Expression: ");
    fgets(infix, sizeof(infix), stdin);
    int len = strlen(infix);
    if(len > 0 && infix[len-1] == '\n') {
        infix[len-1] = '\0';
    }
    infixToPostfix();
    printf("Postfix Expression: %s\n", postfix);
    return 0;
}
