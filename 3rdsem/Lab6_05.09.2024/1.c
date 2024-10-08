/*LE5.1 Write a menu driven program to perform the following operations in a stack using array by
using suitable user defined functions for each case.
a) Check if the stack is empty
b) Display the contents of stack
c) Push
d) Pop
Verify &amp; validate each function from main method.*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Define maximum size of stack

int stack[MAX]; // Array to store stack elements
int top = -1;   // Top initialized to -1 indicating the stack is empty

// Function to check if the stack is empty
int isEmpty()
{
    return top == -1;
}

// Function to check if the stack is full
int isFull()
{
    return top == MAX - 1;

}

// Function to push an element onto the stack

void push(int value)
{
    if (isFull())
    {
        printf("Stack overflow! Cannot push %d\n", value);
    }
    else
    {
        top++;
        stack[top] = value;
        printf("%d pushed into the stack\n", value);
    }
}

// Function to pop an element from the stack
int pop()
{
    if (isEmpty())
    {
        printf("Stack underflow! No element to pop\n");
        return -1;
    }
    else
    {
        int value = stack[top];
        top--;
        printf("%d popped from the stack\n", value);
        return value;
    }
}

// Function to display the contents of the stack
void display()
{
    if (isEmpty())
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

int main()
{
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
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            if (isEmpty())
            {
                printf("The stack is empty.\n");
            }
            else
            {
                printf("The stack is not empty.\n");
            }
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
