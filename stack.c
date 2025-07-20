#include <stdio.h>
#include <stdlib.h>

#define MAX 100
typedef struct Stack{

    int items[MAX];
    int top;

}Stack;

void initialize(Stack *s){

    s->top = -1;

}

int is_full(Stack *s){

    return s->top == MAX-1;

}

int is_empty(Stack *s){

    return s->top == -1;

}

void push(Stack *s, int value){

    if(is_full(s)) return;

    s->items[++(s->top)] = value;

    return;
}

int pop(Stack *s){

    if(is_empty(s)) return -1;

    return s->items[(s->top)--]; 

}

int peek(Stack *s){

    if(is_empty(s)) return -1;

    return s->items[s->top];

}

int main(){


    Stack s;

    initialize(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Top element is %d\n", peek(&s));

    printf("Popped %d\n", pop(&s));
    printf("Top element is %d\n", peek(&s));

    return 0;

}
