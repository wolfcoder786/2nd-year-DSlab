// duplicate parethesis
#include <stdio.h>

int duplicate(char arr[])
{
    int i = 0;
    int x = 0;

    while (arr[i] != '\0')
    {
        if (arr[i] == '(')
        {
            x++; // Increment for an opening parenthesis
        }
        else if (arr[i] == ')')
        {
            x--; // Decrement for a closing parenthesis
            if (x < 0)
            {
                break;
            }
        }
        i++;
    }
    return x;
}

int main()
{
    char arr[50];
    printf("\nEnter an expression: ");
    scanf("%s", arr);
    int x = duplicate(arr);
    if (x == 0)
    {
        printf("Expression is balanced\n");
    }
    else
    {
        printf("Expression is unbalanced\n");
    }
    return 0;
}