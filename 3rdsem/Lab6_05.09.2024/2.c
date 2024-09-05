/*LE5.2 Write a menu driven program to perform the following operations in a stack linked list by
using suitable user defined functions for each case.
a) Check if the stack is empty
b) Display the contents of stack
c) Push
d) pop
Verify &amp; validate each function from main method.*/
#include <stdio.h>
#include <stdlib.h>

// Node structure for stack elements
struct Node
{
    int data;
    struct Node *next;
};

// Function to check if the stack is empty
int isEmpty(struct Node *top)
{
    return top == NULL;
}

// Function to push an element onto the stack
void push(struct Node **top, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Stack overflow! Cannot push %d\n", value);
        return;
    }
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
    printf("%d pushed into the stack\n", value);
}

// Function to pop an element from the stack
int pop(struct Node **top)
{
    if (isEmpty(*top))
    {
        printf("Stack underflow! No element to pop\n");
        return -1;
    }
    else
    {
        struct Node *temp = *top;
        int poppedValue = temp->data;
        *top = (*top)->next;
        free(temp);
        printf("%d popped from the stack\n", poppedValue);
        return poppedValue;
    }
}

// Function to display the contents of the stack
void display(struct Node *top)
{
    if (isEmpty(top))
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("Stack elements are:\n");
        struct Node *temp = top;
        while (temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    struct Node *top = NULL;
    int choice, value;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Check if the stack is empty\n");
        printf("4. Display stack contents\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(&top, value);
            break;
        case 2:
            pop(&top);
            break;
        case 3:
            if (isEmpty(top))
            {
                printf("The stack is empty.\n");
            }
            else
            {
                printf("The stack is not empty.\n");
            }
            break;
        case 4:
            display(top);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
