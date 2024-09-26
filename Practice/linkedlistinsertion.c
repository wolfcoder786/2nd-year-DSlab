#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *create(struct Node *head, int n) {
    int i;
    struct Node *p = head;

    for (i = 0; i < n; i++) {
        struct Node *newnode;
        newnode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data: ");
        scanf("%d", &(newnode->data));
        newnode->next = NULL;
        if (p == NULL) {
            head = newnode;
            p = head;
        } else {
            p->next = newnode;
            p = p->next;
        }
    }
    return head;
}

void traversal(struct Node *head) {
    struct Node *p = head;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

struct Node *insertatbegin(struct Node *head, int n) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = n;
    ptr->next = head;
    head = ptr;
    return head;
}
struct Node* insertatend(struct Node* head , int n ){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = n;
    ptr->next = NULL;
    struct Node* p = head ;
    while (p!=NULL)
    {
        p=p->next ;

    }
    p->next = ptr ;
    ptr ->next = NULL;
    return head ;
}

int main() {
    int size;
    printf("Enter the size of the linked list: ");
    scanf("%d", &size);

    struct Node *head = NULL; // Initialize head to NULL

    // Creating the linked list
    head = create(head, size);

    // Traversing the created list
    printf("The linked list elements are:\n");
    traversal(head);

    while (1) {
        printf("1. Traversal\n");
        printf("2. Insert at Begin\n");
        printf("3. Insert at End\n");
        int choice;
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            traversal(head);
            break;
        case 2: {
            int m;
            printf("Enter a number to insert at the beginning: ");
            scanf("%d", &m);
            head = insertatbegin(head, m);  // Capture the updated head
            break;
        }
        case 3:{
            int m;
            printf("Enter a number to insert at the beginning: ");
            scanf("%d", &m);
            head = insertatend(head, m);  // Capture the updated head
            break;
        }
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }

    return 0;
}
