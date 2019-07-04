#include <stdio.h>   // array pointer is a constant pointer, you cannot assign it again.
#include <stdlib.h> // pass a pointer -> it creates a copy of that pointer but value outside changes
#define N 10 // for real. changes made to pointer var. in function can only be kept after returning.

void maxheapify(int *arr, int i, int n){
    int left = 2*i;
    int right = 2*i+1;
    int largest;
    if(left<=n && arr[i] < arr[left])
        largest = left;
    else
        largest = i;

    if(right <= n && arr[largest] < arr[right])
        largest = right;

    if(largest != i){
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        maxheapify(arr, largest, n);
    }
}
void createmaxheap(int *arr, int n){ // passed the pointer named arr and not the whole array.
    int start = n/2;                 // cannot use sizeof() here. as arr only a single pointer.
    int i;
    for(i=start; i>0; i--){
      maxheapify(arr, i, n);
    }
}
void heapsort(int *arr, int n){
    int i;
    createmaxheap(arr, n);
    for(i=n; i>1; i--){
        int temp = arr[i];
        arr[i] = arr[1];
        arr[1] = temp;
        maxheapify(arr,1,i-1);
    }
}
int main()
{
    int i,n=N;
    int arr[] = {-1,20,3,100,75,13,24,29,9,72,10};
    for(i=1; i<=n; i++)
        printf("%d ",arr[i]);
   // createmaxheap(arr, n);
    printf("\n");
    heapsort(arr, n);
    for(i=1; i<=n; i++)
        printf("%d ",arr[i]);
}

// as long as we want to change only the values and not the pointer itself, it's fine to use void.
