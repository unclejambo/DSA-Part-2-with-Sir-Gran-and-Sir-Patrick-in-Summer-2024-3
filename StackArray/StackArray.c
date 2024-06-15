#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackArray.h"

void initS(stackA* list){
	list->top = -1;
}

bool isEmpty(stackA* list){
	return list->top == -1;
}

bool isFull(stackA* list){
	return list->top == MAX - 1;
}

void push(stackA* list, int new){
	
	if(isFull(list)){
		printf("Stack is Full");
		return;
	}else{
			list->top++;
			list->data[list->top] = new;
	}
}

void pop(stackA* list){
	
	if(isEmpty(list)){
		printf("Stack is Empty");
		return;
	}else{
		list->top--;
	}
	
}

int peek(stackA* list){
	if(isEmpty(list)){
		printf("Empty");
		return;
	}
	return list->data[list->top];
}

void display(stackA list){
	
	stackA tempStack;
	
	initS(&tempStack);
	while(!isEmpty(&list)){
		push(&tempStack, peek(&list));
		pop(&list);
	}
	while(!isEmpty(&tempStack)){
		printf("%d ", peek(&tempStack));
		pop(&tempStack);
	}
	printf("\n");
}


void visualize(stackA* list){
	
	if(isEmpty(list)){
		printf("Empty");
		return;
	}
		int i;
		printf("CURRENT STACK:\nTOP ==>");
		for(i = list->top; i>=0;i--){
			printf("\t\t%d [%d]index\n", list->data[i],i);
		}
}

void evenNumbers(stackA* list, stackA* evenStack){
	
    stackA tempStack;
    initS(&tempStack);

    while(!isEmpty(list)){
        int num = peek(list);
        if(num % 2 == 0){
            push(evenStack, num);
        } else {
            push(&tempStack, num);
        }
        pop(list);
    }

    while(!isEmpty(&tempStack)){
        push(list, peek(&tempStack));
        pop(&tempStack);
    }
}











