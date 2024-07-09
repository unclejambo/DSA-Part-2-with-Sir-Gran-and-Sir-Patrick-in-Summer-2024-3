#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Dictionary.h"

int hash(int x, int size){
	
    int sum = 0;
    
    while(x != 0){
        sum += (x % 31);
        x /= 31;
    }
    return sum % size;
}

Boolean isMember(heroPool D, heroType newH, int size){
	
    int x, hashV = hash(newH.heroID, size);
    Boolean retval = FALSE;

    if(D[hashV].heroID == newH.heroID){
        retval = TRUE;
    }else{
        x = (hashV + 1) % size;
        while(x != hashV && D[x].heroID != newH.heroID && D[x].level != EMPTY){
            x = (x + 1) % size;
        }
        retval = (D[x].heroID == newH.heroID) ? TRUE : FALSE;
    }
    return retval;
}

void insert(heroPool* D, heroType newH, int* size, int* numElements){
	
	int hashV = hash(newH.heroID, *size);
    int x;
	
    if((*numElements + 1) >= (0.65 * (*size))){
        resize(D, size);
    }

    if(isMember(*D, newH, *size) == FALSE){
        if((*D)[hashV].level == EMPTY || (*D)[hashV].level == DELETED){
            (*D)[hashV] = newH;
            (*numElements)++;
        }else{
            x = (hashV + 1) % *size;
            while(x != hashV && (*D)[x].level != EMPTY && (*D)[x].level != DELETED){
                x = (x + 1) % *size;
            }            
            (*D)[x] = newH;
            (*numElements)++;            
        }
    }else{
        printf("Existing Hero\n");
    }
}

void init(heroPool* D, int* size){
	
    int i;

    *D = (heroPool)malloc((*size) * sizeof(heroType));
    for(i = 0; i < *size; i++){
        (*D)[i].level = EMPTY;
    }
}

void display(heroPool D, int size){
	
    int i;

    for(i=0;i<size;i++) {
        printf("Hero[%d]: ", i);
        if (D[i].level == DELETED){
            printf("Deleted Hero!");
        } else if (D[i].level != EMPTY){
            printf("%s `%s`, Level: %d, Attribute: %s, HeroID: %d",
				D[i].name.firstN, D[i].name.lastN, D[i].level,
				D[i].attribute, D[i].heroID);
        }else{
            printf("Empty Slot");
        }
        printf("\n");
    }
}

void delete(heroPool D, heroType newH, int size){
	
    int hashV, x;
    hashV = hash(newH.heroID, size);

    if(D[hashV].heroID == newH.heroID){
        D[hashV].level = DELETED;
    }else{   	
        x=(hashV + 1) % size;      
        while(x != hashV && D[x].level != EMPTY && D[x].heroID != newH.heroID){
            x=(x + 1) % size;
        }
        if(D[x].heroID == newH.heroID){
            D[x].level = DELETED;
        }
    }
}

void resize(heroPool* D, int* size){
	
	int i;
    int newSize = (*size) * 2;
    heroPool newD = (heroPool)malloc(newSize * sizeof(heroType));

    for(i = 0; i < newSize; i++){
        newD[i].level = EMPTY;
    }
		
    for(i = 0; i < *size; i++){
        if((*D)[i].level != EMPTY && (*D)[i].level != DELETED){
            int hashV = hash((*D)[i].heroID, newSize);
            if(newD[hashV].level == EMPTY){
                newD[hashV] = (*D)[i];
            }else{
                int x = (hashV + 1) % newSize;
                while(newD[x].level != EMPTY){
                    x = (x + 1) % newSize;
                }
                newD[x] = (*D)[i];
            }
        }
    }

    free(*D);
    *D = newD;
    *size = newSize;
}
