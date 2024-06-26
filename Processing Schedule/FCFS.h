#ifndef PROCESS
#define PROCESS
#define MAX 5

typedef struct{
	int AT;
	int BT;
	int CT;
	int TAT;
	int WT;
	char name;
}CPU;

typedef struct{
	CPU processors[MAX];
	int count;
	float aveTAT;
	float aveWT;
}List;

List populate();
List sortByAT(List unsorted);
void display(List asd);
void findCT(List* asd);
void findTAT(List* asd);
void findWT(List* asd);
void findAveTAT(List* asd);
void findAveWT(List* asd);
void visualize(List asd);

#endif
