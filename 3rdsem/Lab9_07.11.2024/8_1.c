// WAP to read an array of n integers and search for an element using linear search
#include<stdio.h>
int  linearSearch(int arr[],int n , int target ){
    int i;
     for (int  i = 0; i < n; i++)
     {
        if (arr[i]== target )
        {
           return 1 ;
        }
        
     }
     return 0 ;
}
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
    printf("\n");
    printf("Enter the target element :");
    scanf("%d",&target);
    int result = linearSearch(arr,n,target);
    if (result == 1)
    {
        printf("Target found ");

    }
    else
    {
        printf("Target not found ");
    }
    

    
    
return 0 ;
}