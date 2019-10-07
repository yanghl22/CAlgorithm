/*
 * CArray.h
 *
 * Author: honglin
 * Created on 05/10/2019
 *
 * Modified by: honglin
 * Last modified: 05/10/2019
 *
 * Header for Array in C
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "CArray.h"


int swap(CArray *arr, int position1, int position2);

CArray * createArray(int size)
{
	CArray *arr= (CArray *) malloc(sizeof(CArray));
	arr->array=(int *) malloc(size * sizeof(int));
	arr->size = size;
	for(int i=0; i<size; i++)
	{
		arr->array[i] = 0;	
	}	
	return arr;
}

int insertItem(CArray *arr, int position, int value)
{
	if(position >= 0 && position < arr->size)
	{
		if(arr->array[position]== 0)
		{
			arr->array[position] = value;
			return SUCCESS;
		}
		else 
		return POSITION_INIT;;
	}
	return INVALID_POSITION;
} 

int removeItem(CArray *arr, int position)
{
	if(position > 0 && position < arr->size)
	{
		if(arr->array[position] != 0)
		{
			arr->array[position] = 0;
			return SUCCESS;
		}
		else
		return POSITION_EMPTY;
	}
	return INVALID_POSITION;
}

int pushItem(CArray *arr, int value)
{
	for(int i = 0; i < arr->size; i++)
	{
		if(arr->array[i] == 0)
		{
			arr->array[i] = value;
			return SUCCESS;
		}	
	}
	return ARRAY_FULL;
}


int updateItem(CArray *arr, int position, int value)
{
	if(position > 0 && position < arr->size)
	{
		if(arr->array[position] != 0)
		{
			arr->array[position] = value;	
		}
		else
		return POSITION_NOT_INIT;

	}
	return INVALID_POSITION;
}


int eraseArray(CArray *arr)
{
	for(int i = 0; i < arr->size; i++)
	{
		arr->array[i] = 0;	
	}
	return SUCCESS;
}



int swap(CArray *arr, int position1, int position2)
{
	if(position1 > 0 && position1 < arr->size && position2 > 0 && position2 < arr->size)
	{
		int temp = arr->array[position1];
		arr->array[position1] = arr->array[position2];
		arr->array[position2] = temp;
		return SUCCESS;
	}
	else 
	return INVALID_POSITION;
}


int reverse(CArray *arr)
{
	for(int i = 0; i < arr->size / 2; i++)
	{
		swap(arr,i,arr->size-i-1);
	}
	return SUCCESS;
}


int display(CArray *arr)
{
	printf("\nC Array\n");
	for(int i = 0; i <arr->size; i++)
	{
		printf("%d", arr->array[i]);	
	}
	printf("\n");
	return SUCCESS;
}



CArray * cloneCArray(CArray *arr)
{
	CArray *arry = (CArray *) malloc(sizeof(CArray));
	arry->array = (int *) malloc(arr->size * sizeof(int));
	arry->size = arr->size;
	for(int i = 0; i < arr->size; i++)
	{
		arry->array[i] = arr->array[i];		
	}
	return SUCCESS;
}

int bubbleSort(CArray *arr)
{
	for(int i = 0; i < arr->size; i++)
	{
		for(int j = 1; i < arr->size; j++)
		{
			if(arr->array[i] > arr->array[j])
			{
				swap(arr,i,j);
			}			
		}	
	}
	return SUCCESS;
}


int selectionSort(CArray *arr)
{
	int min;
	for(int i = 0; i < arr->size - 1; i++)
	{
		min = i;
		for(int j = 1; j < arr->size; j++)
		{
			if(arr->array[j] < arr->array[i])
			{
				min = j;
			}				
		}
		swap(arr,i,min);
	}
	return SUCCESS;
}


int insertSort(CArray *arr)
{
	for(int i = 0; i < arr->size; i++)
	{
		int j = i + 1;
		while(j > 0 && arr->array[j] < arr->array[j-1])
		{
			swap(arr, j, j-1);
			j--;	
		}	
	}
	return SUCCESS;
}

int ocurrance(CArray *arr, int value)
{
	int total;
	for(int i = 0 ; i < arr->size; i++)
	{
		if(arr->array[i] == value)
		total++;
	}
	return total;
}



CArray * getPositions(CArray *arr, int value)
{
	int total = ocurrance(arr,value);
	CArray *arry = createArray(total);
	for(int i = 0 ; i < arr->size; i++)
	{
		if(arr->array[i] == value)
		pushItem(arry, i);
	}
	return arry;
}



int findMax(CArray *arr)
{
	int max = arr->array[0];
	for(int i = 1 ; i < arr->size; i ++)
	{
		if(arr->array[i] > max)
		max = arr->array[i];	
	}
	return max;
}



int findMin(CArray *arr)
{
	int min = arr->array[0];
	for(int i = 1 ; i < arr->size; i ++)
	{
		if(arr->array[i] <  min)
		min = arr->array[i];	
	}
	return min;
}
