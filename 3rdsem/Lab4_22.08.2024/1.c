/*4.1 Write a program to create a single linked list of n nodes and perform the following menu
based operations on it using function:
i. Insert a node at the beginning of the SLL
ii. Insert a node at the end of the SLL
iii Insert at a specific position
iv Count nodes
v. Traverse the linked list*/
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data ;
    struct Node* next ;

};
void traversal(struct Node* p  ){
    while (p != NULL)
    {
        printf("Element:%d",p->data);
        p = p->next ;

    }
    
}
void insertatBegin(struct Node* head , int n){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->next = head ;
    ptr->data = n ;
    head = ptr ;
    return head ;

   
}

int main(){
    struct Node* head ;
    struct Node* second ;
    struct Node* third;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    head -> data  = 1 ;
    head -> next = second ;
    second -> data  = 2 ;
    second -> next = third ;
    third -> data  = 4 ;
    third -> next  = NULL;
    printf("The main data elements are:\n");
    traversal(head);
    
    printf("The operation you want :\n");
    printf("1.Insert a node at the beginning of the SLL\n");
    printf("2.Insert a node at the end of the SLL\n");
    printf("3. Insert at a specific position\n");
    printf("4.Count nodesL\n");
    printf("5.Traverse the linked list");
    int a ;
    printf("Enter the number you want:");
    scanf("%d",&a);
    if (a==1)
    {
        int n ;
        printf("Enter the data you want to insert at begin:");
        scanf("%d",&n);
        insertatBegin(head,n);

    }
    
    

    
    

return 0 ;
}