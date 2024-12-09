#include <stdio.h>
int traverse(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
int binarySearch(int arr[], int n, int target)
{
    int left = 0;
    int right = n - 1;
    int mid;
    int i, j;
    while (left <= right)
    {
        mid = left + (right + left) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int n,target;
    printf("Enter the size of the array:");
    scanf("%d", &n);
    int arr[n];
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Enter element%d: ", i);
        scanf("%d", &arr[i]);
    }
    printf("Array Original :");
    traverse(arr, n);
    printf("\n");
    printf("Enter a target:");
    scanf("%d",&target);
    int result  = binarySearch(arr, n , target);
    if (result != - 1)
    {
        printf("Target found at %d",result);
    }
    else
    {
        printf("Target Not found");
    }
    

    return 0;

}