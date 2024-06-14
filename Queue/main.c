#include <stdio.h>
#include <stdlib.h>

#include "myQueue.h"

int main(){
	
	Queue queue1;
	
	init(&queue1);
	enQueue(&queue1,9);
	display(queue1);
	enQueue(&queue1,2);
	display(queue1);
	enQueue(&queue1,3);
	display(queue1);
	deQueue(&queue1);
	display(queue1);
	FrontD(queue1);
	RearD(queue1);	
	
	return 0;
}
