#include <stdio.h>    // binary search along with quick sort
#include <stdlib.h>
#define MAX 1000
void quicksort(int *a,int start,int end);
int binsearch(int *a,int x,int n)
{
    int s=0,e=n-1;
    int mid = (s+e)/2;
    while(s<=e)
    {
        if(a[mid] == x)
        return mid;
        else if(x>a[mid])
            {
                s = mid+1;
                mid = (s+e)/2;
            }
        else if(x<a[mid])
            {
                e = mid-1;
                mid = (s+e)/2;
            }
    }
    return -1;
}
int main()
{
    int i,n,a[MAX],x;
    n = MAX;
    for(i=0; i<n; i++)
        a[i] = rand();
    quicksort(a,0,n-1);
   printf("Enter any element to search\n");
   scanf("%d",&x);
   if(binsearch(a,x,n)==-1)
        printf("Not Found\n");
   else printf("Found\n");
}
void quicksort(int *a,int start,int end)
{
    int i,temp,pivot = end;
    int p = start;
    if(end<=start)
        return;
    for(i=start; i<end; i++)
    {
        if(a[i]<a[pivot])           // if item is less than a[pivot] then swap of a[p] & a[i]
        {
            temp = a[p];
            a[p] = a[i];
            a[i] = temp;
            p++;
        }
    }
    temp = a[pivot];
    a[pivot] = a[p];
    a[p] = temp;
    quicksort(a,start,p-1);
    quicksort(a,p+1,end);
}


