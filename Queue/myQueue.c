#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "myQueue.h"

void init(Queue* asd){
	asd->front = NULL;
	asd->rear = NULL;
}

void display(Queue asd){
	if(asd.front!=NULL){
		printf("Front: %d\tRear: %d\n", asd.front->data,asd.rear->data);
	}else{
		("Empty");
	}
}

void enQueue(Queue* asd, int elem){
	
		NodePtr new = malloc(sizeof(Node));
		if(new != NULL){
			new->data = elem;
			if(asd->front==NULL){
				asd->front=asd->rear = new;
			}else{
				asd->rear->next = new;
				asd->rear = new;
			}
		}
		
	asd->rear->next = NULL;
}

void deQueue(Queue* asd){
	
	NodePtr temp;
	if(asd != NULL){
		temp = asd->front;
		asd->front = asd->front->next;
		free(temp);
	}
	
}

void FrontD(Queue asd){
	printf("\nFront Value: %d", asd.front->data);
}

void RearD(Queue asd){
	printf("\nRear Value: %d", asd.rear->data);
}

bool isEmpty(Queue* asd){
	
	return (asd->front == NULL && asd->rear == NULL)?true:false;
}
