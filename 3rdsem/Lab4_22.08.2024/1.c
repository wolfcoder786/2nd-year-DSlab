/*4.1 Write a program to create a single linked list of n nodes and perform the following menu
based operations on it using function:
i. Insert a node at the beginning of the SLL
ii. Insert a node at the end of the SLL
iii Insert at a specific position
iv Count nodes
v. Traverse the linked list*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Function to create a linked list with 'n' nodes
struct Node* create(struct Node *head, int n) {
    int i;
    struct Node* p;
    p = head;
    for (i = 0; i < n; i++) {
        struct Node* new;
        new = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &(new->data));
        new->next = NULL;
        if (p == NULL) {
            head = new; // First node becomes the head
            p = head;
        } else {
            p->next = new;
            p = p->next;
        }
    }
    return head;
}

// Function to traverse and print the linked list
void traversal(struct Node *p) {
    while (p != NULL) {
        printf("Element: %d\n", p->data);
        p = p->next;
    }
}

// Function to insert a node at the beginning
struct Node* insertatBegin(struct Node *head, int n) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = n;
    head = ptr;
    return head;
}

// Function to insert a node at the end
struct Node* insertatend(struct Node* head, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;
    if (head == NULL) {
        head = ptr;
    } else {
        struct Node* p = head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = ptr;
    }
    return head;
}

// Function to insert a node at a specific index
struct Node* insertatIndex(struct Node* head, int data, int index) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node* p = head;
    int i = 0;
    while (i != index - 1 && p != NULL) {
        p = p->next;
        i++;
    }
    if (p != NULL) {
        ptr->next = p->next;
        p->next = ptr;
    } else {
        printf("Index out of range\n");
    }
    return head;
}

// Function to count the number of nodes
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* p = head;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

int main() {
    int size ;
    printf("Enter the Size of Linked List:");
    scanf("%d",&size);

    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
      // Initialize head to NULL
      printf("Enter the data for Head :");
      scanf("%d",&(head->data));
      head ->next = NULL;
      create(head , size);
      printf("The main elements are:\n");
      traversal(head);
      



    while (1) {
        printf("1. Insert at begin\n");
        printf("2. Insert at end\n");
        printf("3. Insert at index\n");
        printf("4. Count nodes\n");
        printf("5. Traverse the linked list\n");
        printf("Enter the number you want: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int data;
                printf("Enter the data you want to insert at begin: ");
                scanf("%d", &data);
                head = insertatBegin(head, data);
                traversal(head);
                break;
            }
            case 2: {
                int data;
                printf("Enter the data you want to insert at end: ");
                scanf("%d", &data);
                head = insertatend(head, data);
                traversal(head);
                break;
            }
            case 3: {
                int data, index;
                printf("Enter the data you want to insert: ");
                scanf("%d", &data);
                printf("Enter the index where you want to insert: ");
                scanf("%d", &index);
                head = insertatIndex(head, data, index);
                traversal(head);
                break;
            }
            case 4: {
                int count = countNodes(head);
                printf("The number of nodes is: %d\n", count);
                break;
            }
            case 5:
                traversal(head);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
