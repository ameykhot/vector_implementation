#include <stdio.h>
#include <stdlib.h>

#ifndef profile
#define profile

void profileInsert(Vector * vector, List * list);
void profileRead(Vector * vector, List * list);
void profileRemove(Vector * vector, List * list);

#endif