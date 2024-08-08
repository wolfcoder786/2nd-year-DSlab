//  Write a C program to find GCD (HCF) of two numbers using recursion.
#include<stdio.h>
int gcd(int a , int b ){
    if (b==0)
    {
        return a;
    }
    else
    {
        return gcd(b , a%b);
    }
    
}
int main(){
int a , b ;
printf("Enter num1:");
scanf("%d",&a);
printf("Enter num2:");
scanf("%d",&b);
printf("GCD of %d and %d :%d",a,b,gcd(a,b));

return 0 ;
}