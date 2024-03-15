#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void fibonacci(int n,int a1,int a2)
{
    
    if(n>0)
    {
        int a3= a1+a2;
        printf("%d\n",a3);
        a1=a2;
        a2=a3;
        fibonacci(n-1,a1,a2);

    }
}
int main()
{
    int n;
    printf("Enter the number of elemnts you want :");
    scanf("%d",&n);
    printf("0\n1\n");
    fibonacci(n-2,0,1);
}