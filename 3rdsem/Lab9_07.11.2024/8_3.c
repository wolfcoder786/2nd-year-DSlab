// WAP to sort an array of n integers in an ascending order by using insertion sort.
#include<stdio.h>
int main(){
    int n,target ;
    printf("Enter the size of an Array :");
    scanf("%d",&n); 
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter element%d:",i);
        scanf("%d",&arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
        
    }
return 0 ;
}