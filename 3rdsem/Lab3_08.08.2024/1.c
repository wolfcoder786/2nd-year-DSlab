/* 1.WAP to create a 1-D array of n elements and perform the following menu based operations
using function.
a. insert a given element at specific position.
b. delete an element from a specific position of the array.
c. linear search to search an element
d. traversal of the array */
#include <stdio.h>
void insertion(int arr[], int n)
{
    int a, position, i;
    printf("Enter the element you want to enter :");
    scanf("%d", &a);
    printf("Enter the position you want to enter the element:");
    scanf("%d", &position);
    if (position > n || position < 0)
    {
        printf("Invalid Input ");
    }
    else
    {

        for (int i = n; i >= position; i--)
        {
            arr[i] = arr[i - 1];
        }

        // Insert the new element
        arr[position - 1] = a;

        // Update the size of the array
        n++;

        printf("Array after insertion:\n");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}
void traverse(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
void deletion(int arr[], int n)
{
    int position;
    printf("Enter the position for deletion:");
    scanf("%d", &position);
    if (position > n || position < 0)
    {
        printf("Invalid position");
    }
    else
    {
        for (int i = position; i < n; i++)
        {
            arr[i] = arr[i + 1];
        }
        n--;
        printf("Array after deletion:\n");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
    }
}
int linear(int arr[], int n,int target)
{

    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int n;
    printf("Enter number of elements :");
    scanf("%d", &n);
    int arr[n];
    // taking elements in array
    for (int i = 0; i < n; i++)
    {
        printf("Enter element%d :", i);
        scanf("%d", &arr[i]);
    }
    // taking to menu ;
    int a;
    printf("Enter the number which you want to be followed :\n");
    printf("1.insert a given element at specific position.\n");
    printf("2.delete an element from a specific position of the array.\n");
    printf("3.linear search to search an element.\n");
    printf("4.Traversal of the array.\n");
    scanf("%d", &a);
    printf("Your entered option is :%d\n", a);
    if (a == 1)
    {
        insertion(arr, n);
    }
    if (a == 2)
    {
        deletion(arr, n);
    }
    if (a == 3)
    {
        int target;
        printf("Enter the target number :");
        scanf("%d", &target);
        int result = linear(arr, n,target);
        if (result == -1)
        {
            printf("Element not found");
        }
        else
        {
            printf("Element found at %d", result+1);
        }
    }

    if (a == 4)
    {
        traverse(arr, n);
    }

    return 0;
}