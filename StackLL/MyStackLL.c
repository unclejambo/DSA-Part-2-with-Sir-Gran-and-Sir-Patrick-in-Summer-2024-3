#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "MyStackLL.h"

void initList(Stack** asd){
	*asd = NULL;
}

bool isEmptyL(Stack* asd){
	return (asd==NULL);
}

void pushL(Stack** asd,int newData){
	
	Stack* new = malloc(sizeof(Stack));
	
	if(isEmptyL(*asd)){
		new->data = newData;
		new->next = NULL;
		*asd = new;
	}else{
		new->data = newData;
		new->next = *asd;
		*asd = new;
	}
}

void popL(Stack** asd){
	Stack* temp;
	
	if(isEmptyL(*asd)){
		printf("Stack is Empty");
	}else{
		temp = *asd;
		*asd = (*asd)->next;
		free(temp);
	}
}

int peekL(Stack* asd){
	Stack* head = asd;
		if(isEmptyL(asd)){
			printf("Stack is Empty");
			return 0;
		}else{
			return head->data;
		}
}

void displayL(Stack* asd){
	Stack* tempStack;
	initList(&tempStack);
	
	while(!isEmptyL(asd)){
		int top = peekL(asd);
		pushL(&tempStack, top);
		popL(&asd);
	}
	printf("DISPLAYING STACK: ");
	while(!isEmptyL(tempStack)){
		int top = peekL(tempStack);
		printf("%d ", top);
		popL(&tempStack);
	}
	printf("\n");
}

void visualize(Stack* asd){
	Stack* head = asd;
	int i = 0;
	printf("Visualizing Stack:\nTOP==>");
	while(head != NULL){
		printf("\t\t%d-[%d]\n",head->data,i);
		head = head->next;
		i++;
	}
}

void evenNum(Stack** asd, Stack** dsa){
    Stack* tempStack;
    initList(&tempStack);

    while (!isEmptyL(*asd)) {
        int top = peekL(*asd);
        if (top % 2 == 0) {
            pushL(dsa, top);
        } else {
            pushL(&tempStack, top);
        }
        popL(asd);
    }

    while (!isEmptyL(tempStack)) {
        int top = peekL(tempStack);
        pushL(asd, top);
        popL(&tempStack);
    }
}


