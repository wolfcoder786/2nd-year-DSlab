#include<stdio.h>
int traverse(int arr[],int n ){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    
}
void bubbleSort(int arr[],int n ){
    int  i , j ;
    for ( i = 0; i < n-1; i++)
    {
        for ( j = 0; j < n-i-1; j++)
        {
            if (arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp ;
            }
            
        }
        
    }
    
}
void insertionSort(int arr[],int n ){
    int i , j ;
    for ( i = 1; i < n; i++)
    {
        int key = arr[i];
        j= i -1 ;
        while (j>=0&&arr[j]>key)
        {
            arr[j+1] = arr[j];
            j-- ;
        }
        arr[j+1] = key ;

    }
    
}
void selectionSort(int arr[],int n ){
    int i , j ;
    for ( i = 0; i < n; i++)
    {
        int minIndex = i ;
        for ( j = i+1; j < n; j++)
        {
            if (arr[j]<arr[minIndex])
            {
                minIndex = j ;
            }
            
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp ;
    }
    
}
int main(){
    int n ;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    int arr[n];
    int i ;
    for ( i = 0; i < n; i++)
    {
        printf("Enter element%d: ",i);
        scanf("%d",&arr[i]);

    }
    
    printf("Array Original :");
    traverse(arr,n);
    // bubbleSort(arr,n);
    // insertionSort(arr,n);
    selectionSort(arr,n);
    printf("\n");
    printf("Array Sorted :");
    traverse(arr,n);
    

return 0 ;
}