#include <stdio.h>
#include <stdlib.h>
#include "MyQueueCircle.h"

int main(){
	
	circularQ myList;
	
	init(&myList);
	enqueue(&myList, 1);
	enqueue(&myList, 2);
	enqueue(&myList, 3);
	dequeue(&myList);
	enqueue(&myList, 4);
	enqueue(&myList, 5);
	enqueue(&myList, 6);
	enqueue(&myList, 7);
	enqueue(&myList, 8);
	enqueue(&myList, 9);
	enqueue(&myList, 10);
	enqueue(&myList, 11);
	display(myList);
	
	return 0;
}
