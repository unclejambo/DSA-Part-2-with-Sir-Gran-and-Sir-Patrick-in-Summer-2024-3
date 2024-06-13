#include <stdio.h>
#include <stdlib.h>
#include "StackArray.h"

int main(){
	
	stackA stack;
	
	initS(&stack);
	push(&stack,1);
	push(&stack,2);
	push(&stack,3);
	pop(&stack);
	display(stack);
					
	return 0;
}
