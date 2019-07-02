#include <stdio.h>      // Linked List Stack (Evaluation of postfix) NOT WORKING
#include <stdlib.h>
char val1,val2,val3;
typedef struct node
{
    char value;
    struct node *next;
}node;
node *top = NULL;
void push(char x){
    node *temp = (node*)malloc(sizeof(node));
    temp->value = x;
    temp->next = top;
    top = temp;
}
char pop()
{
    if(top == NULL){
        printf("No element to pop\n");
        return NULL;
    }
    node *temp = top;
    char val = top->value;
    top = top->next;
    free(temp);
    return val;
}
char first()
{
    if(top != NULL)
        return top->value;
    else
        printf("\nThe stack is empty\n");
}
void isempty()
{
    if(top != NULL)
        printf("\nFALSE\n");
    else
        printf("\nTRUE\n");
}
void print()
{
    node *temp = top;
    printf("\nElement in Stack\n");
    while(temp != NULL)
    {
        printf("%d ",temp->value);
        temp = temp->next;
    }
}
int main()
{
    char x[20];
    printf("The stack is currently empty\n");
    printf("Enter any statement\n");
    gets(x);
    int i = 0;
    int j;
    while(x[i] != '\0'){
            if(x[i] == ' '){
                i++;
                continue;
            }
            if(x[i] == '+'){
                    char val1 = pop()-'0';
                    char val2 = pop()-'0';
                    char val3 = val2 + val1;
                    push(val3);
                    print();
                    i++;
                    continue;
            }
            if(x[i] == '-'){
                    char val1 = pop()-'0';
                    char val2 = pop()-'0';
                    char val3 = val2 - val1;
                    push(val3);
                    print();
                    i++;
                    continue;
            }
            if(x[i] == '*'){
                    char val1 = pop()-'0';
                    char val2 = pop()-'0';
                    char val3 = val2*val1;
                    push(val3);
                    print();
                    i++;
                    continue;
            }
            if(x[i] == '/'){
                    char val1 = pop()-'0';
                    char val2 = pop()-'0';
                    char val3 = val2/val1;
                    push(val3);
                    print();
                    i++;
                    continue;
                }
            if(x[i] == '%'){
                    char val1 = pop()-'0';
                    char val2 = pop()-'0';
                    char val3 = val2%val1;
                    push(val3);
                    print();
                    i++;
                    continue;
            }
            push(x[i]);
            i++;
        }
    }






