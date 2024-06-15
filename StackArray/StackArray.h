#ifndef STACK_ARRAY
#define STACK_ARRAY

#include <stdbool.h>

#define MAX 10

typedef struct{
	int data[MAX];
	int top;
}stackA;

void initS(stackA* list);
void push(stackA* list, int new);
void pop(stackA* list);
int peek(stackA* list);

void display(stackA list);
void visualize(stackA* list);
bool isEmpty(stackA* list);
bool isFull(stackA* list);

void evenNumbers(stackA* list, stackA* evenStack);

#endif
