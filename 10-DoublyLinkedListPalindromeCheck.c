#include <stdio.h>              // To check palindrome in a doubly linked list.
#include <stdlib.h>

typedef struct node{
        char value;
        struct node *next;
        struct node *prev;
}node;

node *head = NULL;
node *tail = NULL;
void insert(char a);
void print();

int length;

void palindrome(){
    node *temp = head;
    node *temp2 = tail;
    while(temp != temp2 && temp != temp2->next){
        if(temp->value == temp2->value){
            temp = temp->next;
            temp2 = temp2->prev;
        }
        else{
            printf("\nNOT a palindrome\n");
            return;
        }
    }
    printf("\nPalindrome\n");
    return;
}

int main()
{
    int i;
    char x;
    printf("Enter the no. of characters you want to add to list\n");
    scanf("%d",&length);
    printf("\nEnter one character at a time to enter in the list\n");
    for(i=0; i<length; i++){
        scanf(" %c",&x);
        insert(x);
    }
    print();
    palindrome();
}

void insert(char a)
{
    node *temp = (node*)malloc(sizeof(node));
    if(NULL == head){
        tail = temp;
        temp->prev = NULL;
        temp->value = a;
        temp->next = head;
        head = temp;
        return;
    }
    temp -> value = a;
    temp -> next = head;
    head->prev = temp;
    head = temp;
}
void print()
{
    node *temp = head;
    printf("\nList - \n");
    while(temp != NULL){
        printf("%c ", temp -> value);
        temp = temp -> next;
    }

}
