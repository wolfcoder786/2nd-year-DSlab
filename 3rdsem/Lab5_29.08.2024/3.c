/*3 Write a menu driven program to perform the following operations in a double linked list by
using suitable user defined functions for each case.
a) Traverse the list forward
b) Traverse the list backward
c) Check if the list is empty
d) Insert a node at the certain position (at beginning/end/any position)
e) Delete a node at the certain position (at beginning/end/any position)
f) Delete a node for the given key
g) Count the total number of nodes
h) Search for an element in the linked list
Verify & validate each function from main method.*/
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node *create(struct Node *head, int size)
{
    int i;
    struct Node *p = head;

    for (i = 1; i < size; i++)
    { // Starting from 1 since head is already created
        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter the data Element%d: ", i + 1);
        scanf("%d", &(new_node->data));
        new_node->next = NULL;

        if (p == NULL)
        {
            head = new_node;
            p = head;
        }
        else
        {
            p->next = new_node;
            new_node->prev = p;
            p = p->next;
        }
    }

    return head;
}

void traversef(struct Node *head)
{ // Corrected the function signature
    struct Node *p = head;

    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
void trverseb(struct Node *head)
{
    struct Node *p = head;
    struct Node *q;
    struct node *current, *temp;

    current = head;
    while (current != NULL)
    {
        /*
         * Swap the previous and next address fields of current node
         */
        q = p->next;
        p->next = p->prev;
        p->prev = q;

        /* Move the current pointer to next node which is stored in temp */
        p = q;
    }

    /*
     * Swap the head and last pointers
     */

    printf("LIST REVERSED SUCCESSFULLY.\n");
}

int main()
{
    int size;
    printf("Enter the Number of Nodes: ");
    scanf("%d", &size);

    if (size <= 0)
    {
        printf("Size should be greater than 0.\n");
        return 1;
    }

    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data for head: ");
    scanf("%d", &(head->data));
    head->prev = NULL;
    head->next = NULL;

    head = create(head, size);
    traversef(head);

    return 0;
}
