#include <stdio.h>
#include <stdlib.h>
#include "FCFS.h"

void display(List prcs){
	
	int i;
	
	printf("\nProcessor name | Arrival Time | Burst Time");
	
	for(i=0;i<prcs.count;i++){
		printf("\n%-14c | %-12d | %-10d",prcs.processors[i].name,prcs.processors[i].AT,prcs.processors[i].BT);
	}
}

List populate(){
	
	int i;
	List prcs;
	
	printf("Enter number of processors: ");
	scanf("%d", &prcs.count);
	
	for(i = 0;i<prcs.count;i++){
		printf("Processor #%d name: ",i+1);
		scanf(" %c",&prcs.processors[i].name);
		printf("Processor #%d AT: ",i+1);
		scanf("%d",&prcs.processors[i].AT);
		printf("Processor #%d BT: ",i+1);
		scanf("%d",&prcs.processors[i].BT);
	}
	
	display(prcs);
	
	return prcs;
}

List sortByAT(List unsorted){
	
	List sorted = unsorted;
    int i, j;
    CPU key;
    
    for(i = 1; i < sorted.count; i++){
        key = sorted.processors[i];
        j = i - 1;
        
        while(j >= 0 && (sorted.processors[j].AT > key.AT || (sorted.processors[j].AT == key.AT && sorted.processors[j].BT > key.BT))){
            sorted.processors[j + 1] = sorted.processors[j];
            j = j - 1;
        }
        sorted.processors[j + 1] = key;
    }
    
    return sorted;
}

void findCT(List* asd){
	int i;
	    
    asd->processors[0].CT = asd->processors[0].AT + asd->processors[0].BT;
    
    for (i = 1; i < asd->count; i++) {
        if (asd->processors[i].AT > asd->processors[i - 1].CT) {
            asd->processors[i].CT = asd->processors[i].AT + asd->processors[i].BT;
        } else {
            asd->processors[i].CT = asd->processors[i - 1].CT + asd->processors[i].BT;
        }
    }
}


void findTAT(List* asd){
	int i;
	
	for(i=0;i<asd->count;i++){
		asd->processors[i].TAT = asd->processors[i].CT - asd->processors[i].AT;
	}
}

void findWT(List* asd){
	int i;
	
	for(i=0;i<asd->count;i++){
		asd->processors[i].WT = asd->processors[i].TAT - asd->processors[i].BT;
	}
}

void findAveTAT(List* asd){
	int i;
	float total = 0;
	
	for(i = 0;i<asd->count;i++){
		total += asd->processors[i].TAT;
	}
	
	total = total / asd->count;
	
	asd->aveTAT = total;
}

void findAveWT(List* asd){
	int i;
	float total = 0;
	
	for(i = 0;i<asd->count;i++){
		total += asd->processors[i].WT;
	}
	total = total / asd->count;
	
	asd->aveWT = total;
}

void visualize(List prcs){
	
	int i;
	
	printf("\nProcessor name | Arrival Time | Burst Time | Completion Time | Turnaround Time | Waiting Time");
	
	for(i=0;i<prcs.count;i++){
		printf("\n%-14c | %-12d | %-10d | %-15d | %-10d      | %-15d",prcs.processors[i].name,prcs.processors[i].AT,prcs.processors[i].BT,prcs.processors[i].CT,
		prcs.processors[i].TAT,prcs.processors[i].WT);
	}
	
	printf("\n\nAverage TAT: %.2f",prcs.aveTAT);
	printf("\nAverage WT: %.2f",prcs.aveWT);
}


