// WAP to reverse a stack with using extra stack.
#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int top;
    int size;
    int *arr;
};
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}
void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflowed, Cannot be pushed");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflowed, Cannot be popped");
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
        // printf("Popped element is %d\n",val);
    }
}
void display(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack is empty");
    }
    else
    {
        for (int i = 0; i <= ptr->top; i++)
        {
            printf("%d ", ptr->arr[i]);
        }
        printf("\n");
    }
}
void reverse(struct stack *ptr, struct stack *p)
{
    while (!isEmpty(ptr))
    {
        push(p, pop(ptr));
    }
    display(p);
}

int main()
{
    int n;
    printf("Enter the size of the stack:");
    scanf("%d", &n);
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = n;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    struct stack *r = (struct stack *)malloc(sizeof(struct stack));
    r->size = s->size;
    r->top = -1;
    r->arr = (int *)malloc(s->size * sizeof(int));
    while (1)
    {
        printf("\n====Menu====\n");
        printf("\n1.Push\n");
        printf("\n2.reverse\n");
        // printf("\n3.pop\n");
        printf("\n4.display\n");
        printf("\n5.exit\n");
        int choice;
        printf("Enter the choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            int a;
            printf("Enter element you want to push :");
            scanf("%d", &a);
            push(s, a);
            break;
        }

        case 2:
            reverse(s, r);
            break;
        // case 3:
        //     pop(s);
        //     break;
        case 4:
        if (isEmpty(s))
        {
            printf(" Stack is reversed\n");
            display(r);
        }
        else
        {
            display(s);
        }
        
            break;
        case 5:
            printf("Exiting....");
            exit(0);

        default:
            printf("Invalid choice! Please enter a valid option.\n");
            break;
        }
    }

    return 0;
}