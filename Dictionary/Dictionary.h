#ifndef DICTIONARY
#define DICTIONARY

#define SIZE 31
#define EMPTY -1
#define DELETED -2

#include <stdbool.h>

typedef struct {
    char firstN[20], lastN[15];
} heroName;

typedef struct {
    heroName name;
    char attribute[10];
    int level;
    int heroID;
} heroType;

typedef heroType* heroPool;

typedef enum { TRUE, FALSE } Boolean;

int hash(int x, int size);
void init(heroPool* D, int* size);
void insert(heroPool* D, heroType newH, int* size, int* numElements);
void display(heroPool D, int size);
void delete(heroPool D, heroType newH, int size);
Boolean isMember(heroPool D, heroType newH, int size);
void resize(heroPool* D, int* size);

#endif
