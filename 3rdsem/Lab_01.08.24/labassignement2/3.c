//  Write a C program to generate nth Fibonacci term using recursion.
#include <stdio.h>
int fibonacci(int n)
{
    if (n == 1 || n == 2)
    {
        return n - 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}
int main()
{
    int n;
    printf("Enter the term :");
    scanf("%d",&n) ;
    printf("The term %d in fibonaci series :%d",n,fibonacci(n));
    return 0;
}