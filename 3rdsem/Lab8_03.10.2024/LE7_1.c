/*Write a menu driven program to implement queue operations such as Insert, Delete, Display,
whether queue is empty etc by using array.*/
#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
};
int isEmpty(struct queue *ptr)
{
    if (ptr->front == -1)
    {
        return 1;
    }
    return 0;
}
int isFull(struct queue *ptr)
{
    if (ptr->rear == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}
void enq(struct queue *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Queue is full cannot be enqueued");
    }
    else
    {
        ptr->front = 0 ;
        ptr->rear++;
        ptr->arr[ptr->rear] = val;
        printf("Inserted %d into the queue.\n", val);
    }
}
void deq(struct queue *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Queue is empty .");
    }
    else
    {
        int val = ptr->arr[ptr->front];
        printf("Deleted %d from the queue.\n", val);
        ptr->front++;

    }
}
void display(struct queue* ptr) {
    if (isEmpty(ptr)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements are: ");
    for (int i = ptr->front; i <= ptr->rear; i++) {
        printf("%d ", ptr->arr[i]);
    }
    printf("\n");
}
int main()
{
    struct queue *Q = (struct queue *)malloc(sizeof(struct queue));
    int n;
    printf("Enter size of queue:");
    scanf("%d", &n);
    Q->size = n;
    Q->arr = (int *)malloc(n * sizeof(int));
    Q->front = -1;
    Q->rear = -1;
   int choice, value;

    while (1)
    {
        printf("\n Queue Operations Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. IsEmpty\n");
        printf("5. IsFull\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to enqueue: ");
            scanf("%d", &value);
            enq(Q, value);
            break;
        case 2:
            deq(Q);
            break;
        case 3:
            display(Q);
            break;
        case 4:
            if (isEmpty(Q))
            {
                printf("Queue is empty.\n");
            }
            else
            {
                printf("Queue is not empty.\n");
            }
            break;
        case 5:
            if (isFull(Q))
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