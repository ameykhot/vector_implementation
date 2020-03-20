#include "data.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef T
#define T

typedef struct Vector
{

    Data *data;
    unsigned int current_size;
    unsigned int max_size;

    void (*insert)(struct Vector *array, int index, Data data);
    Data *(*read)(struct Vector *array, int index);
    void (*remove)(struct Vector *array, int index);
    void (*delete)(struct Vector *array);

} Vector;

Vector *newVector();
void insertIntoVector(Vector *array, int index, Data data);
Data *readFromVector(Vector *array, int index);
void removeFromVector(Vector *array, int index);
void deleteVector(Vector *array);

#endif