#include <stdio.h>          // Stack using queue.
#include <stdlib.h>
int arr[100];
int start = -1;
int end = -1;
int dequeue(){
    int temp;
    if(!isempty()){
        if(start == end){
            temp = arr[start];
            start = -1;
            end = -1;
            return temp;
        }
        temp = arr[start];
        start = (++start)%100;
        return temp;
    }
    else{
        printf("Nothing to dequeue\n");
        return NULL;
    }
}
void enqueue(int a){
   if(isempty()){
    start = 0;
    end = 0;
    arr[start] = a;
    return;
   }
   end = (++end)%100;
   if(start == end){
        end -= 1;
        printf("\nQueue full\n");
        return;
   }
   else{
   arr[end] = a;
   return;
   }
}
char peek(){
    return arr[start];
}
int isempty(){
    if(start == -1)
        return 1;
    else return 0;
}
void print(){
    if(!isempty()){
        int temp = start;
        printf("\nQueue-\n");
        do{
            printf("%d ",arr[temp]);
            temp = (++temp)%100;
        }while(temp <= end);
        return;
    }
    else{
        printf("Queue empty\n");
        return;
    }
}
void push(int a){
    enqueue(a);
}
int pop(){
     if(isempty()){
        printf("Nothing to pop\n");
        return NULL;
     }
     else{
        int value;
        int temp = end;
        while(start != temp){
            value = dequeue();
            enqueue(value);
        }
        return dequeue();
     }
}
int top(){
   return arr[end];
}
int main()
{
    push(23);
    push(0);
    push(440);
    push(99);
    print();
    printf("\nElement popped - %d\n",pop());
    printf("\nTop of the stack - %d\n",top());
}






