#include <stdio.h>
#include <stdlib.h>
#include "StackArray.h"

int main(){
	
    stackA stack;
    stackA evenStack;

    initS(&stack);
    initS(&evenStack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 4);
    push(&stack, 6);
    push(&stack, 8);
    push(&stack, 9);
    pop(&stack);
    push(&stack, 11);
    push(&stack, 13);
    push(&stack, 14);
    push(&stack, 15);
    push(&stack, 16);

    printf("Original Stack:\n");
    display(stack);

    evenNumbers(&stack, &evenStack);

    printf("\nNo even numbers:\n");
    visualize(&stack);

    printf("\nEven numberss:\n");
    visualize(&evenStack);
	
	return 0;
}
