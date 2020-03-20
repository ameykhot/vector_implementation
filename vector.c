#ifndef VECTORH
#define VECTORH

#include "data.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

Vector *newVector()
{
	Vector *initVector = (Vector *)malloc(sizeof(Vector));
	initVector->current_size = 0;
	initVector->max_size = 0;
	initVector->data = NULL;
	initVector->insert=insertIntoVector;
	initVector->read=readFromVector;
	initVector->remove=removeFromVector;
	initVector->delete=deleteVector;
	return initVector;
};

void insertIntoVector(Vector *array, int index, Data data)
{

	if (array->current_size == array->max_size || index > array->current_size)
	{
		array->max_size = 2 * index + 1;
		array->data = realloc(array->data, sizeof(Data) * array->max_size);
	}

	array->data[index].value = data.value;

	if (index < array->current_size)
		printf("\n");
	else
		array->current_size = index + 1;

}

Data *readFromVector(Vector *array, int index)
{
	if (index > array->max_size)
		return NULL;
	else
	{
		
		if (array->data[index].value == '\0')
		{
			array->data[index].value = -1;
			return &array->data[index];
		}
		else
		{
			return &array->data[index];
		}
	}
}

void removeFromVector( Vector *array, int index){

	int indexIterator = index;

	if (index > array->current_size)
	{
		return ;
	}

	while (indexIterator < array->current_size)
	{
		array->data[indexIterator] = array->data[indexIterator + 1] ;
		indexIterator++; 
		array->current_size = array->current_size-1;
	}

}

void deleteVector(Vector *array){

	free(array->data);
	free(array);
}

#endif