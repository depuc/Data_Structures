#include <stdio.h>

#define SIZE 100

typedef struct queue {

    int items[SIZE];
    int front;
    int rear;

}queue;

void init_queue(queue *q){

    q->front = -1;
    q->rear = -1;
    
}

int isEmpty(queue *q){
    
    return q->front = -1;
}

int isFull(queue *q){

    return q->rear == SIZE -1;
    
}

void enqueue(queue *q, int data){

    if(isFull(q)){
        printf("\nQueue is full!");
        return;
    }

    if(isEmpty(q))
        q->front = 0; 

    q->rear++;
    q->items[q->rear] = data;

}

int dequeue(queue* q){

    if(isEmpty(q)){
        printf("Queue is empty\n");
        return -1;
    }

    int value = q->items[q->front];

    if(q->front == q->rear){
        q->front = -1;
        q->rear = -1;
    }

    else
        q->front++;

    return value;

}

int peek(queue *q){

    if(isEmpty(q)){
        printf("Queue is empty\n");
        return -1;
    }

    int value = q->items[q->front];

    return value;
}

void display(queue *q){
   
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");

    for(int i = q->front; i <= q->rear; i++){
        printf("%d " ,q->items[i]);
    }
    printf("\n");
}
int main() {
    queue q;
    init_queue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(&q);

    printf("Dequeued: %d\n", dequeue(&q));
    display(&q);

    printf("Front item: %d\n", peek(&q));

    return 0;
}
