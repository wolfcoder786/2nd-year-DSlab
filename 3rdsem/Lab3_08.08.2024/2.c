// WAP to insert a new element into a sorted array at the appropriate position.
#include <stdio.h>
int compare(int arr[], int n, int a)
{
    int k, i;
    for (k = 0; k < n; k++)
        if (a < arr[k])

            break;

    for (i = n-1; i >= k; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[k] = a;


    return (1);
}

int main()
{
    int n, i;
    printf("Enter number of elements :");
    scanf("%d", &n);
    int arr[n];
    // taking elements in array
    for (int i = 0; i < n; i++)
    {
        printf("Enter element%d :", i);
        scanf("%d", &arr[i]);
    }
    int a;
    printf("Enter the new element:");
    scanf("%d", &a);
    printf("Main array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    compare(arr, n, a);
    printf("Sorted Array :");
    for (int i = 0; i < n+1; i++)
    {
        printf("%d ", arr[i]);
    }
    

    return 0;
}