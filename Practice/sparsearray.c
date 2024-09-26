#include <stdio.h>
int main()
{
    int n1, n2, i, j;
    int count = 0, nz = 0;

    printf("Enter number of rows:");
    scanf("%d", &n1);
    printf("Enter number of columns:");
    scanf("%d", &n2);
    int arr[n1][n2];
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < n2; j++)
        {
            printf("Enter the number arr[%d][%d] ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    // print
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < n2; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // checking sparse
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < n2; j++)
        {
            if (arr[i][j] == 0)
            {
                count++;
            }
            else
            {
                nz++;
            }
        }
    }
    if (nz > count)
    {
        printf("It is not sparse Matrix");
    }
    else
    {
        int k = 0 ;
        int S[i][3];
        for (i = 0; i < n1; i++)
        {
            for (j = 0; j < n2; j++)
            {
                if (arr[i][j] != 0)
                {
                    S[k][0] = i;
                    S[k][1] = j;
                    S[k][2] = arr[i][j];
                    k++;
                }
            }
        }
        for (i = 0; i < nz; i++)
        {
            printf("\n");
            for (j = 0; j < 3; j++)
            {
                printf("%d", S[i][j]);
            }
        }
    }

    return 0;
}