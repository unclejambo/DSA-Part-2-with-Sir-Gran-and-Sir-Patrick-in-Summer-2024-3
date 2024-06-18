#ifndef QUEUE_C
#define QUEUE_C
#define MAX 10
#define EMPTY 9999

#include <stdbool.h>

typedef struct{
	int data[MAX];
	int front;
	int rear;
}circularQ;

void init(circularQ* list);
void enqueue(circularQ* list, int newData);
void dequeue(circularQ* list);
int Rear(circularQ list);
int Front(circularQ list);
bool isEmpty(circularQ list);
bool isFull(circularQ list);
void display(circularQ list);

#endif
