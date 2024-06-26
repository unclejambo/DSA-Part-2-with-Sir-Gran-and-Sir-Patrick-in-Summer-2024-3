#include <stdio.h>
#include <stdlib.h>
#include "FCFS.h"

int main() {
	
	List CPUs = populate();
	List sorted = sortByAT(CPUs);
	
	findCT(&sorted);
	findTAT(&sorted);
	findWT(&sorted);
	findAveTAT(&sorted);
	findAveWT(&sorted);
	printf("\n\n");
	system("pause");
	system("cls");
	visualize(sorted);

	return 0;
}
