#include <stdio.h>
#include <stdlib.h>
long long expo(int x, int n)
{
    if(n==0)
    {
        return 1;
    }
    return x*expo(x,n-1);
}
long long expo2(int x , int n)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)
       {
          long long y = expo2(x,n/2);
           return y*y;
       }
    else
    {
        long long z = x*expo2(x,n-1);
        return z;
    }

}
int main()
{
    int x,n;
    long long result;
    printf("Enter a number and it's power \n");
    scanf("%d %d",&x,&n);
    printf("\nThe expo. is %lld\nSecond method - %lld\n",expo(x,n),expo2(x,n));
}
