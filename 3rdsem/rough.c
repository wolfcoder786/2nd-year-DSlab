//sorted linked list ascending order
#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * next;
}*head=NULL;
void create(int);
void display();
int main(){
    int m,n,i;
    printf("Enter the no. of nodes to be created\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter the values\n");
        scanf("%d",&m);
        create(m);
    }
    display();
}
void create(int v){
    struct node *tmp;
    struct node *p;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data=v;
    tmp->next=NULL;
    if(head==NULL||head->data>v){
        tmp->next=head;
        head=tmp;
    }
    else {
        p = head;
        while (p->next != NULL && p->next->data < v) {
            p = p->next;
        }

       
        tmp->next = p->next;
        p->next = tmp;
    }
}
void display(){
    struct node *p;
    if(head==NULL)
        printf("no linked list exists\n");
    else{
        p=head;
        while(p!=NULL){
            printf("%d\t",p->data);
            p=p->next;
        }
    }
}

