/*Write a menu driven program to create a stack using linked list and perform the following 
operation using function
a. Push
b. Pop
c. IsEmpty
d. display the stack elements*/
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
void push(struct Node** top, int value);
int pop(struct Node** top);
int isEmpty(struct Node* top);
void display(struct Node* top);
// Function to push an element onto the stack
void push(struct Node** top, int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
    printf("%d pushed onto the stack.\n", value);
}

// Function to pop an element from the stack
int pop(struct Node** top) {
    if (isEmpty(*top)) {
        printf("Stack is empty, nothing to pop.\n");
        return -1;
    }

    int value;
    struct Node* temp = *top;
    value = temp->data;
    *top = (*top)->next;
    free(temp);

    return value;
}

// Function to check if the stack is empty
int isEmpty(struct Node* top) {
    return (top == NULL);
}


void display(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty.\n");
        return;
    }

    struct Node* temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() {
    struct Node* top = NULL;
    int choice, value;

    do {
        printf("\nStack Operations: ");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Check if Stack is Empty");
        printf("\n4. Display Stack Elements");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(&top, value);
                break;
            case 2:
                if (!isEmpty(top)) {
                    printf("Popped value: %d\n", pop(&top));
                } else {
                    printf("Stack is empty, nothing to pop.\n");
                }
                break;
            case 3:
                if (isEmpty(top)) {
                    printf("Stack is empty.\n");
                } else {
                    printf("Stack is not empty.\n");
                }
                break;
            case 4:
                display(top);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

