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

#pragma once

#ifdef __cplusplus
extern "C"  {
#endif

		#define ARRAY_ERASED -1
		#define SUCCESS 0
		#define INVALID_POSITION 1
		#define POSITION_INIT 2
		#define POSITION_NOT_INIT 3
		#define POSITION_EMPTY 4
		#define ARRAY_EMPTY 5
		#define ARRAY_FULL 6

		typedef struct CArray {
			int *array;
			int size;	
		} CArray;
		
		/* return a CArray */
		CArray * createArray(int size);
		CArray * cloneCArray(CArray *arr);


		/* Input and Output */
		int insertItem(CArray *array, int position, int value);
		int removeItem(CArray *array, int position);
		int pushItem(CArray *array, int value);
		int updateItem(CArray *array, int position, int value);
				
		/* Erase Array */

		int eraseArray(CArray *array);

		/* switching */
		
		int swap(CArray *array, int position1, int position2);
		int reverse(CArray *array);

		/* Sorting */
		int bubbleSort(CArray *array);
		int selectionSort(CArray *array);
		int insertSort(CArray *array);
		/* todo
		int mergeSort(CArray *array);
		int quickSort(CArray *array);
		int blender(CArray *array);
		*/

		/* Searching */
		
		int exist(CArray *array, int value);
		CArray * getPositions(CArray *arr, int value);
		int findMax(CArray *array);
		int findMin(CArray *array);


		/* Display */

		int display(CArray *array);



#ifdef __cplusplus
}
#endif
