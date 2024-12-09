#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *create(struct Node * head, int  n)
{
    struct Node *p = head;
    int i;
    for (i = 0; i < n - 1; i++)
    {
        struct Node *new = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data for Node%d", i);
        scanf("%d", &(new->data));
        new->next = NULL;
        if (p == NULL)
        {
            head = new;
            p = head;
        }
        else
        {
            p->next = new;
            p = p->next;
        }
    }
    return head;
}
void traversal(struct Node *p)
{
    while (p->next != NULL)
    {
        printf("Element: %d\n ", (p->data));
        p = p->next;
    }
}
//insertion at begin
struct Node* insertatBegin(struct Node*head, int n ){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = n ;
    ptr->next = head ;
    head = ptr ;
    return head ;

}
struct Node* InsertAtEnd(struct Node* head , int n ){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr ->data = n ;
    ptr ->next = NULL;
    if (head == NULL )
    {
        head = ptr ;

    }
    else
    {
        struct Node* p = head ;
        while (p->next != NULL)
        {
            p = p ->next;
        }
        p->next =ptr ;
    }
    
    
    
}
int main()
{
    int size;
    printf("Enter the size of Linked List :");
    scanf("%d", &size);
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data for head:");
    scanf("%d", &(head->data));
    head->next = NULL;
    create(head, size);

    return 0;
}