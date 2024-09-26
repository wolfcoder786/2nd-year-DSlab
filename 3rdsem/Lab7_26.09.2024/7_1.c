// Write a menu driven program to create a linear queue using array and perform Enqueue,
// Dequeue, Traverse, IsEmpty, IsFull operations.
#include<stdio.h>
#include<stdlib.h>
#define MAX  5;
struct queue
{
    int arr[MAX];
    int front  ;
    int back;
};
int isempty(struct Queue *q){
    return q->front == -1 ;

}

int main(){
    struct queue q ;
    q.front = - 1;
    q.back = - 1;
    int choice ;
    int n ;


return 0 ;
}