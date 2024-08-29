/*perform following operations using function on the single linked list using menu driven
program:
i. search an element in the list
ii. sort the list in ascending order
iii. reverse the list*/
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Function to create a linked list with 'n' nodes
struct Node *create(struct Node *head, int n)
{
    struct Node *p = head;
    for (int i = 1; i < n; i++)
    {
        struct Node *new = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &(new->data));
        new->next = NULL;
        p->next = new;
        p = p->next;
    }
    return head;
}

// Function to traverse and print the linked list
void traversal(struct Node *p)
{
    while (p != NULL)
    {
        printf("Element: %d\n", p->data);
        p = p->next;
    }
}

// Function to search for an element in the linked list
void search(struct Node *head, int n)
{
    struct Node *ptr = head;
    int i = 0;
    int flag = 0; // Flag to indicate if the element was found

    while (ptr != NULL)
    {
        if (ptr->data == n)
        {
            printf("Item found at location %d\n", i + 1);
            flag = 1;
            break; // Exit loop if element is found
        }
        i++;
        ptr = ptr->next;
    }

    if (!flag)
    {
        printf("Item not found\n");
    }
}

// Function to sort the linked list in ascending order
void sortList(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty. Cannot sort.\n");
        return;
    }

    int swapped;
    struct Node *current;
    struct Node *last = NULL;

    do
    {
        swapped = 0;
        current = *head;

        while (current->next != last)
        {
            if (current->data > current->next->data)
            {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = 1;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
    printf("List sorted in ascending order\n");
}

// Function to reverse the linked list
void reverseList(struct Node **head)
{
    struct Node *prev = NULL;
    struct Node *current = *head;
    struct Node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
    printf("List reversed\n");
}

int main()
{
    int size;
    printf("Enter the size of the linked list: ");
    scanf("%d", &size);

    if (size <= 0)
    {
        printf("Invalid size\n");
        return 1;
    }

    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data for head: ");
    scanf("%d", &(head->data));
    head->next = NULL;

    if (size > 1)
    {
        create(head, size);
    }

    printf("The main elements are:\n");
    traversal(head);

    while (1)
    {
        printf("1. Search an element in the list\n");
        printf("2. Sort the list in ascending order\n");
        printf("3. Reverse the list\n");
        printf("4. Display the list\n");
        printf("5. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            int data;
            printf("Enter the data you want to search: ");
            scanf("%d", &data);
            search(head, data);
            break;
        }
        case 2:
        {
            sortList(&head);
            printf("The linked list is:\n");
            traversal(head);
            break;
        }
        case 3:
        {
            reverseList(&head);
            printf("The linked list is:\n");
            traversal(head) ;
            break;
        }
        case 4:
        {
            printf("The linked list is:\n");
            traversal(head);
            break;
        }
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
