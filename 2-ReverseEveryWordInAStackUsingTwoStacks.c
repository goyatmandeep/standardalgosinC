#include <stdio.h>  //Reverse every word in a stack.(Using two explicit and one implicit stack.)
#include <stdlib.h>
#define N 100
int arr[100];
int top = -1;
char pop2(){                    // stack to reverse each word.
    if(top >= 0)
    return arr[top--];
    else
    printf("Nothing to pop\n");
    return NULL;
}
void push2(char *a){
    arr[++top] = *a;
    return;
}
char peek2(){
    return arr[top];
}
int isempty2(){
    if(top == -1)
        return 1;
    else return 0;
}

typedef struct node{                    // stack that has words.
    char *word;
    struct node *next;
}node;

node *head = NULL;

char* pop(){
    if(head != NULL){
        node *temp = head;
        head = head->next;
        return temp->word;
    }
    else{
        printf("\nNothing to pop\n");
        return NULL;
    }
}
void push(char *newword){
    node *temp = (node*)malloc(N*sizeof(node));
    temp->word = newword;
    temp->next = head;
    head = temp;
}
char* peek(){
    return head->word;
}
int isempty(){
    if(NULL == head)
        return 1;
    else return 0;
}
void print(){
    node *temp = head;
    while(temp != NULL){
        printf("%s ",temp->word);
        temp = temp->next;
    }
}
void reverseword(){              // creation of implicit stack using recursion,reverse and push.
    if(isempty())
        return;
    char *temp = pop();
    char *t = temp;
    char *temp2 = temp;
    while(*temp2 != '\0'){
        push2(temp2);
        temp2 += sizeof(char);
    }
    while(!isempty2()){
        *temp = pop2();
         temp += sizeof(char);
    }
    reverseword();
    push(t);
}
int main()
{
    int n,i;
    printf("Enter the no. of words in stack to be reversed.\n");
    scanf("%d",&n);
    for(i=0; i<n; i++){
        printf("Enter the word\n");
        char *w = (char*)malloc(N*sizeof(char));
        scanf("%s",w);
        push(w);
    }
    printf("\nBefore reversing - \n");
    print();
    printf("\n");
    reverseword();
    printf("\nAfter reversing - \n");
    print();
    printf("\n");
}
