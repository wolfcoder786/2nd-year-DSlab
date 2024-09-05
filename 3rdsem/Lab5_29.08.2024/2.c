// WAP to reverse the sequence elements in a double linked list.
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

void traverse(struct Node *head)
{ // Corrected the function signature
    struct Node *p = head;

    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
struct Node *reverse(struct Node *head)
{
    struct Node *ptr1 = head;
    struct Node *ptr2 = ptr1->next;
    ptr1->next = NULL;
    ptr1->prev = ptr2;

    if (ptr1 == NULL)
    {
        printf("Empty");
    }
    else
    {
        while (ptr2 != NULL)
        {
            ptr2->prev = ptr2->next;
            ptr2->next = ptr1;
            ptr1 = ptr2;
            ptr2 = ptr2->prev;
        }
        head = ptr1;
        return head;
    }
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
    traverse(head);
    
    head = reverse(head);
    printf("Reversed list :\n");
    traverse(head);

    return 0;
}
