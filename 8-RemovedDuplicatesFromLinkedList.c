#include <stdio.h>    //remove duplicates from a unsorted doubly linked list.
#include <stdlib.h>

typedef struct node{
        int value;
        struct node *next;
        struct node *prev;
}node;

node *head = NULL;
node *tail = NULL;
void insert(int a);
void print();
int length = 0;

int main()
{
    int i,x;
    printf("Enter the no. elements in the list\n");
    scanf("%d",&length);
    for(i=0; i<length; i++){
        printf("\nEnter the number to insert in the list\n");
        scanf("%d",&x);
        insert(x);
    }
    print();
    removedup();
    print();
}


void insert(int a)
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
        printf("%d ", temp -> value);
        temp = temp -> next;
    }

}
void removedup(){
    node *temp = head;
    node *temp2 = head->next;
    node *temp1 = head;
    while(temp != NULL){
        while(temp2 != NULL){
            if(temp->value == temp2->value){
                temp2 = temp2->next;
                deletenode(temp2->prev);
                continue;
            }
            temp2 = temp2->next;
        }
        temp = temp->next;
        if(temp->next != NULL)
            temp2 = temp->next;
            else
                break;
    }
}

void deletenode(node *temp2){
    node *past = temp2->prev;
    if(temp2->next != NULL){
        node *future = temp2->next;
        past->next = future;
        future->prev = past;
        free(temp2);
        return;
    }
    else{
        free(temp2);
        past->next = NULL;
        return;
    }
}



