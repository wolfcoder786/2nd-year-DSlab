//  Write a C program to find maximum and minimum elements in array using recursion.
#include <stdio.h>

int maximum(int *num, int n, int big)
{
    if (n < 0)
    {
        return big;
    }

    else
    {
        if (*num > big)
        {
            big = *num;
        }
        return maximum(num + 1, n - 1, big);
    }
}

int minimum(int *num, int n, int min)
{
    if (n < 0)
    {
        return min;
    }
    else
    {
        if (*num < min)
        {
            min = *num;
        }
        return minimum(num + 1, n - 1, min);
    }
}

int main()
{
    int n;
    printf("Enter the number of elements in an array: ");
    scanf("%d", &n);

    int arr[n];
    int *ptr = arr;

    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Maximum element in array is %d\n", maximum(arr, n - 1, arr[0]));
    printf("Minimum element in array is %d\n", minimum(arr, n - 1, arr[0]));

    return 0;
}
