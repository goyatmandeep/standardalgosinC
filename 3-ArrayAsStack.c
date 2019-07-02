#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
int a[MAXSIZE];
int top = -1;
void push(int x)
{
    if(top != MAXSIZE-1)
        a[++top] = x;
    else
        printf("\nStack Overflow \n");
}
void pop()
{
    if(top != -1)
        --top;
    else
        printf("\nNo element to pop\n");
}
int topf()
{
    return a[top];
}
void isempty()
{
    if(top == -1)
        printf("TRUE\n");
    else
        printf("FALSE\n");
}
void print()
{
    int i;
    printf("\nStack\n");
    for(i=0;i<=top;i++)
    {
        printf("%d ",a[i]);
    }
}
int main()
{
    int x;
    scanf("%d",&x);
    push(x);
    print();
    push(x*2);
    print();
    push(x*3);
    print();
    pop();
    print();
    topf();
    isempty();
    pop();
    print();
}
