#ifndef STACK_LL
#define STACK_LL

#include <stdbool.h>

typedef struct node{
	int data;
	struct node* next;
}Stack;

void initList(Stack** asd);
bool isEmptyL(Stack* asd);
void pushL(Stack** asd,int newData);
void popL(Stack** asd);
int peekL(Stack* asd);
void displayL(Stack* asd);
void visualize(Stack* asd);
void evenNum(Stack** asd, Stack** dsa);

#endif
