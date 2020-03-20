#ifndef LISTH
#define LISTH
#include "list.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

List *newList()
{

    List *initializeList = (List *)malloc(sizeof(List));
    initializeList->head = NULL;
    initializeList->tail = NULL;
    initializeList->sizeOfList = 0;
    initializeList->insert = insertIntoList;
    initializeList->read = readFromList;
    initializeList->remove = removeFromList;
    initializeList->delete = deleteList;
    return initializeList;
}

void insertIntoList(List *list, int index, Data data)
{
    int iteratorForList = index;
    Node *node = (Node *)malloc(sizeof(Node));
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (list->head == NULL)
    {
        node->data.value = data.value;
        list->head = node;
        list->head->prev = NULL;
        list->head->next = NULL;
        list->tail = list->head;
        list->sizeOfList++;
        return;
    }
    else
    {
        free(node);
    }

    newNode->data = data;
    newNode->prev = list->tail; // Link new node with the previous node
    newNode->next = NULL;

    list->tail->next = newNode; // Link previous node with the new node
    list->tail = newNode;       // Make new node as last/previous node
    list->sizeOfList++;
}

Data *readFromList(List *list, int index)
{
    Node *node;
    int i = 0;
    if (index >= list->sizeOfList)
        return NULL;
    else
    {
        node = list->head;
        while (i < index)
        {
            node = node->next;
            i++;
        }
        return &node->data;
    }
}

void removeFromList(List *list, int index)
{
    int indexIterator;
    Node *node;

    node = list->head;

    for (indexIterator = 0; indexIterator < index && node != NULL; indexIterator++)
    {
        node = node->next;
    }

    if (index == 0)
    {
        if (list->head == NULL)
        {
            printf("List is empty");
        }
        else
        {
            node = list->head;
            list->head = list->head->next;

            if (list->head != NULL)
            {
                list->head->prev = NULL;
            }

            if (list->head == NULL && list->tail != NULL)
            {
                list->tail = NULL;
            }
            free(node);
        }
    }
    else if (node == list->tail)
    {

        if (list->tail == NULL)
        {
            printf("List is empty.\n");
        }
        else
        {
            node = list->tail;
            list->tail = list->tail->prev; // Move last pointer to 2nd last node

            if (list->tail != NULL)
                list->tail->next = NULL; // Remove link to of 2nd last node with last node

            free(node); // Delete the last node
        }
    }
    else if (node != NULL)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        free(node); // Delete the n node
    }
    else
    {
        printf("\n");
    }
}

void deleteList(List *list)
{

    free(list);
}
#endif