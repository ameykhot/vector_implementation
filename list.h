#include "data.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef LIST1
#define LIST1

typedef struct Node
{
    Data data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct List
{
    int sizeOfList;
    struct Node *head;
    struct Node *tail; 
    void (*insert)(struct List *list, int, Data);
    Data *(*read)(struct List *list, int Data);
    void (*remove)(struct List *list, int Data);
    void (*delete)(struct List *list);
}List;

List *newList();
void insertIntoList(List *list, int index, Data data);
Data *readFromList(List *list, int index);
void removeFromList(List *list, int index);
void deleteList(List *list);

#endif