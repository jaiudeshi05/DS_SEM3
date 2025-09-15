#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

char stack[100],s[100];
int top=-1;

void push(char ch) {
    top++;
    stack[top] = ch;
}

char pop() {
    top--;
}

char peek() {
    return stack[top];
}

bool isEmpty() {
    return top == -1;
}

bool ParenthesisCheck(){
    int len=strlen(s);
    for(int i=0;i<len;i++){
        if(s[i]=='('||s[i]=='{'||s[i]=='['){
            push(s[i]);
        }
        else if(s[i]==')'||s[i]=='}'||s[i]==']'){
            if(s[i]=='}'&&peek()=='{') pop();
            else if(s[i]==']'&&peek()=='[') pop();
            else if(s[i]==')'&&peek()=='(') pop();
            else return false;
        }
    }
    if(isEmpty()) return true;
    else return false;
}

void main() {
    printf("Enter Expression: ");
    fgets(s, sizeof(s), stdin); //Can Use Normal gets(s) function
    int len = strlen(s);
    if(len > 0 && s[len-1] == '\n') { //Not necessary to be written
        s[len-1] = '\0';
    }
    if(ParenthesisCheck()) printf("Parenthesis Balanced");
    else printf("Parenthesis Unbalanced");
}