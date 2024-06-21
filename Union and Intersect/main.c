#include <stdio.h>
#include <stdlib.h>
#include "Sets.h"

int main(){

	Set A = initSet();
	Set B = initSet();
	Set tempSet;
	
	addElem(&A,0);
	addElem(&A,2);
	addElem(&A,3);
	addElem(&A,4);
	addElem(&A,6);
	addElem(&A,7);
	addElem(&A,9);
	addElem(&B,1);
	addElem(&B,3);
	addElem(&B,4);
	addElem(&B,5);
	addElem(&B,6);
	addElem(&B,7);
	addElem(&B,8);
	printf("Set A = ");
	display(A);
	printf("Set B = ");
	display(B);
	
	tempSet = Union(A,B);
	printf("A union B = ");
	display(tempSet);
	
	removeElem(&A,0);
	printf("Set A = ");
	display(A);
	
	printf("A intersect B = ");
	display(tempSet = (Intersect(A,B)));
	
	return 0;
}
