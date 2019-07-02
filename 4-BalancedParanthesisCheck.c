#include <stdio.h>  // last filled - top ,STACK ,To check balanced parenthesis using stack.
#include <stdlib.h>
char arr[100];
int top = -1;
char pop(){
    if(top >= 0)
    return arr[top--];
    else
    printf("Nothing to pop\n");
    return NULL;
}
void push(char a){
    arr[++top] = a;
    return;
}
char peek(){
    return arr[top];
}
int isempty(){
    if(top == -1)
        return 1;
    else return 0;
}
void print(){
    int temp = top;
    while(temp != -1){
        printf("%c ",arr[temp]);
        temp--;
    }
}
void check(char *input){
    int i = -1;
    while(input[i] != '\0'){
            i++;
        if(input[i] == ' '){
            continue;
        }
        if(input[i] == '{' || input[i] == '(' || input[i] == '['){
                push(input[i]);
           }
        if(input[i] == '}'){
            if(peek() == '{'){
                pop();
                continue;
            }
            else{
                printf("Unbalanced parenthesis\n");
                return;
            }
        }
        if(input[i] == ')'){
            if(peek() == '('){
                pop();
                continue;
            }
            else{
                printf("Unbalanced parenthesis\n");
                return;
            }
        }
        if(input[i] == ']'){
            if(peek() == '['){
                pop();
                continue;
            }
            else{
                printf("Unbalanced parenthesis\n");
                return;
            }
        }
    }
    if(isempty()){
        printf("Balanced Parenthesis\n");
        return;
    }
    else{
        printf("Unbalanced Parenthesis\n");
        return;
    }
}
int main()
{
    char input[50];
    gets(input);
    printf("\n");
    check(input);
    print();
}
