#include <stdio.h>
#include <stdlib.h>
#include "Sets.h"

Set initSet(){
	int i;
	Set x;
	
	x.count = 0;
	for(i=0;i<MAX;i++){
		x.list[i] = 0;
	}
	return x;
}

Set Union(Set asd, Set dsa){
	Set new = initSet();
	int i;
	
	for(i=0;i<MAX;i++){
		if(asd.list[i] || dsa.list[i]){
			addElem(&new, i);
		}
	}
	return new;
}

Set Intersect(Set asd, Set dsa){
	Set new = initSet();
	int i;
	
	for(i=0;i<MAX;i++){
		if(asd.list[i] && dsa.list[i]){
			addElem(&new, i);
		}
	}
	return new;
}

bool addElem(Set* asd, int y){
	asd->list[y] = 1;
	asd->count++;
	return true;
}

bool removeElem(Set* asd, int y){
	asd->list[y] = 0;
	asd->count--;
	return true;
}
void display(Set asd){
	int i;
	
	printf("{");
	for(i=0;i<MAX;i++){
		printf("%d ",asd.list[i]);
	}
	printf("}\n");
}
