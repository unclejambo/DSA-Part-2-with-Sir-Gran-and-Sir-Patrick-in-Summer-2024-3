#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "MyQueueCircle.h"

void init(circularQ* list){
	
	int i;
	
	list->front = 7;
	list->rear = 6;
	
	for(i = 0;i<MAX;i++){
		list->data[i] = EMPTY;
	}
}

void enqueue(circularQ* list,int newData){
	
	if(!isFull(*list)){
		list->rear = (list->rear + 1) % MAX;
		list->data[list->rear] = newData;
	}
	
}

void dequeue(circularQ* list){
	if(!isEmpty(*list)){
		list->data[list->front] = EMPTY;
		list->front = (list->front + 1) % MAX;
	}
}

int Rear(circularQ list){
	if(isEmpty(list)){
		return EMPTY;
	}else{
		return list.data[list.rear];
	}
}

int Front(circularQ list){
	if(isEmpty(list)){
		return EMPTY;
	}else{
		return list.data[list.front];
	}
}

bool isEmpty(circularQ list){
	return ((list.rear+1)%MAX == list.front);
}

bool isFull(circularQ list){
	return ((list.rear+2)%MAX == list.front);
}

void display(circularQ list){
	
	int i;
	
		printf("Current List:  ");

			for(i = 0;i<MAX;i++){
				if(!isEmpty(list)){
					printf("%d ",list.data[i]);
				}else{
			printf("  ");
				}
			}
}
	
