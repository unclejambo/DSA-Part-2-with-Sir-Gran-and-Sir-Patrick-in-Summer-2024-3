#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackArray.h"

void initS(stackA* list){
	list->top = -1;
}


bool push(stackA* list, int new){
	
	if(list->top == MAX){
		printf("Stack is Full");
	}else{
			list->top++;
			list->data[list->top] = new;
	}
}

bool pop(stackA* list){
	
	if(list->top == -1){
		printf("Stack is Empty");
	}else{
		list->top--;
	}
	
}

int peek(stackA* list){
	
	return list->data[list->top];
}

void display(stackA list){
	
	while(list.top != -1){
		printf("%d\n",list.data[list.top]);
		list.top--;
	}		
	
}


void visualize(stackA* list){
	
}

void evenNumbers(stackA* list){
	
}
