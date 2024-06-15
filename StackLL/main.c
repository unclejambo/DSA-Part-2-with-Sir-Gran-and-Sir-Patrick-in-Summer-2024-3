#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "MyStackLL.h"


int main() {
	
	Stack* lList;
    initList(&lList);
    Stack* evenList;
    initList(&evenList);

    pushL(&lList, 10);
    pushL(&lList, 8);
    pushL(&lList, 9);
    pushL(&lList, 11);
    displayL(lList);
    popL(&lList);
    displayL(lList);
    pushL(&lList, 12);
    pushL(&lList, 1);
    pushL(&lList, 20);
    pushL(&lList, 30);
    visualize(lList);
    evenNum(&lList,&evenList);
    visualize(lList);
    visualize(evenList);
    
	return 0;
}
