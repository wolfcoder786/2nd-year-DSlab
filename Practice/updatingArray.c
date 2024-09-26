#include <stdio.h>
int main()
{
    int n;
    printf("Enter number of element");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements:\n");
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Enter elements:");
        scanf("%d", &arr[i]);
    }
    int pos;
    printf("Enter the position to get updated:");
    scanf("%d", &pos);
    printf("Enter the value to be updated:");
    int val;
    scanf("%d", &val);
    arr[pos]= val;
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}