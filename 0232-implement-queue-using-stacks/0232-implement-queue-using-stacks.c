
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

// Stack structure
typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack* s) {
    s->top = -1;
}

bool isEmptyStack(Stack* s) {
    return s->top == -1;
}

void pushStack(Stack* s, int x) {
    s->data[++s->top] = x;
}

int popStack(Stack* s) {
    return s->data[s->top--];
}

int peekStack(Stack* s) {
    return s->data[s->top];
}

// Queue structure using two stacks
typedef struct {
    Stack in;
    Stack out;
} MyQueue;

// Initialize queue
MyQueue* myQueueCreate() {
    MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
    initStack(&q->in);
    initStack(&q->out);
    return q;
}

// Push element to back of queue
void myQueuePush(MyQueue* obj, int x) {
    pushStack(&obj->in, x);
}

// Move elements from in to out if needed
void moveInToOut(MyQueue* obj) {
    if (isEmptyStack(&obj->out)) {
        while (!isEmptyStack(&obj->in)) {
            pushStack(&obj->out, popStack(&obj->in));
        }
    }
}

// Removes the element from front of queue and returns it
int myQueuePop(MyQueue* obj) {
    moveInToOut(obj);
    return popStack(&obj->out);
}

// Get the front element
int myQueuePeek(MyQueue* obj) {
    moveInToOut(obj);
    return peekStack(&obj->out);
}

// Returns true if queue is empty
bool myQueueEmpty(MyQueue* obj) {
    return isEmptyStack(&obj->in) && isEmptyStack(&obj->out);
}

// Free memory
void myQueueFree(MyQueue* obj) {
    free(obj);
}

