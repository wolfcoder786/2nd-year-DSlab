/*WAP to create a linked list that represents a polynomial expression with single variable
and display the polynomial by using user defined functions for creation and Display*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
    int coe;
    int expo;
    struct Node *next;
};
struct Node *create(int coe, int expo, int n)
{
    for (int i = 0; i < n; i++)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->coe = coe;
        newNode->expo = expo;
        newNode->next = NULL;
    }

    return newNode;
}

int main()
{
    int size;
    printf("Enter the Size of Linked List:");
    scanf("%d", &size);

    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head->next = NULL;
}