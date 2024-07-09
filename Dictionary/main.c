#include <stdio.h>
#include <stdlib.h>
#include "Dictionary.h"

int main(){
    int size = SIZE;
    int numElements = 0;
    heroPool test;
    init(&test, &size);

    heroType heroz[] = {
        {{"Invoker", "Kael"}, "Universal", 25, 5},
        {{"NightStkr", "Balanar"}, "Strength", 30, 26},
        {{"Spirit Breaker", "Barathrum"}, "Strength", 12, 32},
        {{"Slark", "NightCrawler"}, "Agility", 1, 35},
        {{"Kardel", "Sniper"}, "Agility", 6, 45},
        {{"Jahrakal", "Troll"}, "Agility", 6, 54},
        {{"Rylai", "CrystalM"}, "Int", 1, 63},
    };

    insert(&test, heroz[1], &size, &numElements);
    insert(&test, heroz[0], &size, &numElements);
    insert(&test, heroz[2], &size, &numElements);
    insert(&test, heroz[3], &size, &numElements);
    insert(&test, heroz[4], &size, &numElements);
    insert(&test, heroz[5], &size, &numElements);
    insert(&test, heroz[6], &size, &numElements);

    delete(test, heroz[1], size);

    display(test, size);

    return 0;
}
