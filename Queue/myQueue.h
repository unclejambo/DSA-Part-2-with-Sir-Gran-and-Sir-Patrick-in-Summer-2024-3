#ifndef QUEUE_LL
#define QUEUE_LL

#include <stdbool.h>

typedef struct node{
	int data;
	struct node* next;
}Node, *NodePtr;

typedef struct{
	NodePtr front;
	NodePtr rear;
}Queue;

void init(Queue* asd);
void enQueue(Queue* asd, int data);
void deQueue(Queue* asd);
void FrontD(Queue asd);
void RearD(Queue asd);
bool isEmpty(Queue* asd);
void display(Queue asd);

#endif
