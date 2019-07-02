#include <stdio.h>                      // Insertion Sort on Linked List
#include <stdlib.h>

typedef struct node
    {
        int value;
        struct node *prev;
        struct node *next;
    }node;
int condition = 0;
int length;
node *head = NULL;
void insert(int a);
void print();
void sort();

int main()
{
    int i,x,n;
    length = 0;
    for(i = 0 ; i < 6 ; i++){
        x = rand()%100+1;
        insert(x);
        length++;
        print();
    }
    printf("\nSorting begins\n");
    sort();
    print();
}

void insert(int a)
{
    node *temp = (node*)malloc(sizeof(node));
    temp -> value = a;
    temp -> next = head;
    temp -> prev = NULL;
    if(condition)
        head->prev = temp;
    head = temp;
    condition = 1;
}


void print()
{
    int i = 0;
    node *temp = head;
    printf("\nList - ");
    while(i < length)
    {
        printf("%d ", temp -> value);
        temp = temp -> next;
        i++;
    }

}

void sort(){

    int i,j,val;
    node *present = head;
    node *temp = present;

    for(i=0; i<length-1; i++){

            while(NULL != temp && (temp->value > temp->next->value)){
                val = temp->value;
                temp->value = temp->next->value;
                temp->next->value = val;
                temp = temp->prev;
            }
    present = present->next;
    temp = present;
    }
}








