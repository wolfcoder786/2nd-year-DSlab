/* Write a menu driven program to implement linear queue operations such as Enqueue,
Dequeue, IsEmpty, Traverse using single linked list.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
void enqueue(struct Node **front, struct Node **rear, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (*rear == NULL)
    {
        *front = *rear = newNode; // If the queue is empty
    }
    else
    {
        (*rear)->next = newNode;
        *rear = newNode;
    }
    printf("%d enqueued to the queue.\n", value);
}
int dequeue(struct Node **front, struct Node **rear)
{
    if (isEmpty(*front))
    {
        printf("Queue is empty, nothing to dequeue.\n");
        return -1;
    }

    int value;
    struct Node *temp = *front;
    value = temp->data;
    *front = (*front)->next;

    if (*front == NULL)
    {
        *rear = NULL;
    }

    free(temp);
    return value;
}
int isEmpty(struct Node *front)
{
    return (front == NULL);
}

void traverse(struct Node *front)
{
    if (isEmpty(front))
    {
        printf("Queue is empty.\n");
        return;
    }

    struct Node *temp = front;
    printf("Queue elements: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *front = NULL;
    struct Node *rear = NULL;
    int choice, value;

    do
    {
        printf("\nQueue Operations: ");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Check if Queue is Empty");
        printf("\n4. Traverse Queue");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to enqueue: ");
            scanf("%d", &value);
            enqueue(&front, &rear, value);
            break;
        case 2:
            if (!isEmpty(front))
            {
                printf("Dequeued value: %d\n", dequeue(&front, &rear));
            }
            else
            {
                printf("Queue is empty, nothing to dequeue.\n");
            }
            break;
        case 3:
            if (isEmpty(front))
            {
                printf("Queue is empty.\n");
            }
            else
            {
                printf("Queue is not empty.\n");
            }
            break;
        case 4:
            traverse(front);
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

// Function to enqueue an element

// Function to check if the queue is empty
