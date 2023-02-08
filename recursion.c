#include<stdio.h>
void main()
{
    int res,n=5;
    res=factorial(5);
    printf("factorial=%d,res");
    return 1;

}
 int factorial(int n)
 {
    if(n==0||n==1)
    return 1;
    else 
   {return n*factorial(n-1);}
 }