#ifndef SETS
#define SETS

#define MAX 10

#include <stdbool.h>

typedef struct{
	bool list[MAX];
	int count;
}Set;

Set initSet();
Set Union(Set list1, Set list2);
Set Intersect(Set list1, Set list2);
bool addElem(Set* list, int newD);
bool removeElem(Set* list, int newD);
void display(Set list);

#endif
