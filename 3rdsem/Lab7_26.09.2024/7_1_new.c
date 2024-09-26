#include <stdio.h>
#include <stdlib.h>
// #define MAX 5 // Define the maximum size of the queue

// Queue structure
struct Queue
{
    int *items;
    int front;
    int rear;
};

// Function prototypes
void enqueue(struct Queue *q, int value);
void dequeue(struct Queue *q);
void traverse(struct Queue *q);
int isEmpty(struct Queue *q);
int isFull(struct Queue *q);
void displayMenu();

int main()
{
    struct Queue q;
    q.front = -1;
    q.rear = -1;

    int choice, value;

    while (1)
    {
        printf("\n==== Queue Operations Menu ====\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Traverse\n");
        printf("4. IsEmpty\n");
        printf("5. IsFull\n");
        printf("6. Exit\n");
        printf("===============================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to enqueue: ");
            scanf("%d", &value);
            enqueue(&q, value);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            traverse(&q);
            break;
        case 4:
            if (isEmpty(&q))
            {
                printf("Queue is empty.\n");
            }
            else
            {
                printf("Queue is not empty.\n");
            }
            break;
        case 5:
            if (isFull(&q))
            {
                printf("Queue is full.\n");
            }
            else
            {
                printf("Queue is not full.\n");
            }
            break;
        case 6:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to display menu

// Function to add an element to the queue
void enqueue(struct Queue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue is full. Cannot enqueue.\n");
    }
    else
    {
        if (q->front == -1)
            q->front = 0; // If the queue is initially empty
        q->rear++;
        q->items[q->rear] = value;
        printf("%d enqueued to the queue.\n", value);
    }
}

// Function to remove an element from the queue
void dequeue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty. Cannot dequeue.\n");
    }
    else
    {
        printf("%d dequeued from the queue.\n", q->items[q->front]);
        q->front++;
        if (q->front > q->rear)
        {
            // Reset queue when empty
            q->front = q->rear = -1;
        }
    }
}

// Function to display elements of the queue
void traverse(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Queue elements are: ");
        for (int i = q->front; i <= q->rear; i++)
        {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

// Function to check if the queue is empty
int isEmpty(struct Queue *q)
{
    return q->front == -1;
}

// Function to check if the queue is full
int isFull(struct Queue *q)
{
    return q->rear == MAX - 1;
}
