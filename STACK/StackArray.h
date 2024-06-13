#ifndef STACK_ARRAY
#define STACK_ARRAY

#include <stdbool.h>

#define MAX 10

typedef struct{
	int data[MAX];
	int top;
}stackA;

void initS(stackA* list);
bool push(stackA* list, int new);
bool pop(stackA* list);
int peek(stackA* list);

void display(stackA list);
void visualize(stackA* list);
bool isEmpty(stackA);
bool isFull(stackA);

void evenNumbers(stackA* list);

#endif
