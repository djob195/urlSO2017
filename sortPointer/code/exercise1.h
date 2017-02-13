#pragma once
#define EXERCISE1_H

#pragma region Signature 
/*Description : Function for read a memory.
* @returns : int.
* @parameter pointer (void*) -> its a pointer that you want read.
* @parameter dataLength (size_t) -> Size to type.
* @author : Diego Orellana.
*/
long getValueAddress(void * pointer, size_t dataLength);

/*Description : Function for write a memory.
* @returns : int.
* @parameter pointer (void*) -> its a pointer that you want start.
* @parameter dataLength (size_t) -> Size to type.
* @parameter value (long) -> value to write a memory
* @author : Diego Orellana.
*/
void writeMemory(void * pointer, size_t dataLength, long value);

/*Description : Function for change a pointers.
* @Function: cmpBubble
* @author : Diego Orellana.
*/
typedef void(*_cmpBubble)(void *pNow, void *pFuture, size_t dataLength);

#pragma endregion Its a comparative Funtions for sort array  

#pragma region Functions 

/*Description : Function for create an aleatory array type char (ASCII: 32-127).
* @returns : char pointer.
* @parameters nothing
* @author : Diego Orellana.
*/
char *createCharVector();

/*Description : Function for create an aleatory array type integer (number: 0-100).
* @returns : int pointer.
* @parameter nothing
* @author : Diego Orellana.
*/
int *createIntegerVector();

#pragma endregion Its all functions used for exercise 1.

#pragma region Methods 
/*Description : Function for print the array.
* @returns : nothing
* @parameter pStart (void *) -> Point to start array.
* @parameter elements (int) -> Number to elements in array.
* @parameter dataLength (size_t) -> size to Data
* @author : Diego Orellana.
*/
void printArray(void *pStart, int elements, size_t dataLength, bool isChar);

/*Description : Function for change a pointers.
* @returns : nothing.
* @parameters pNow (*void) -> its a pointer actual, in the vector.
* @parameters pFuture (*void) -> its a pointer actual + 1, in the vector.
* @parameter dataLength (size_t) -> Size to type.
* @author : Diego Orellana.
*/
void cmpBubble(void *pNow, void *pFuture, size_t dataLength);

/*Description : Function for sort element by array
* @returns : nothing
* @parameter pStart (void *) -> Point to start array.
* @parameter elements (size_t) -> Elements in the array.
* @parameter dataLength (size_t) -> Size to type.
* @parameter cmpBubble (_cmpBubble) -> Function cmpBubble.
* @author : Diego Orellana.
*/
void bubble(void *pStart, size_t elements, size_t dataLength, _cmpBubble cmpBubble);

#pragma endregion Its all methods used for exercise 1.
