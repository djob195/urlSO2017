#include "exercise1.h"
#include "stdafx.h"
#include <string>
#include <iostream>
#include <stdlib.h> 
#include <math.h>
#include <sstream>
using namespace std;

const int byteToBits = 256;
const int lengthArray = 5;

#pragma region Signature 
long getValueAddress(void * pointer, size_t dataLength) {
	int offset = (dataLength / sizeof(char));
	long rValue = 0;
	char *byte = (char *)pointer;
	for (size_t i = 0; i < offset; i++)
	{
		char cValue = *byte;
		int  iValue = (int)cValue;
		rValue += (iValue*pow(byteToBits, i));
		*byte++;
	}
	return rValue;
}

void writeMemory(void * pointer, size_t dataLength, long value)
{
	char * cPointer = (char *)pointer;
	for (size_t i = 0; i < dataLength; i++)
	{
		if (value==0)
		{
			*cPointer = 0;
		}
		else
		{
			*cPointer = value % byteToBits;
			value = value / byteToBits;
		}
		*cPointer++;
	}
}

void cmpBubble(void *pNow, void *pFuture, size_t dataLength)
{
	long valueNow = getValueAddress(pNow, dataLength);
	long valueFuture = getValueAddress(pFuture, dataLength);
	if (valueNow > valueFuture)
	{
		writeMemory(pNow, dataLength, valueFuture);
		writeMemory(pFuture, dataLength, valueNow);
	}
}
#pragma endregion Its a comparative Funtions for sort array  

#pragma region Functions 

char *createCharVector() {
	static char array[lengthArray];
	stringstream printArray;
	for (size_t i = 0; i < lengthArray; i++)
	{
		int rnd = rand() % 96 + 32;
		printArray << (char)rnd << ",";
		array[i] = (char)rnd;
	}
	cout << "Unsorted char array: " << printArray.str()<< endl;
	return array;
}

int *createIntegerVector() {
	static int array[lengthArray];
	stringstream printArray;
	for (size_t i = 0; i < lengthArray; i++)
	{
		int rnd = rand() % 101;
		array[i] = (char)rnd;
		printArray << std::to_string(rnd) << ",";
	}
	cout << "Unsorted int array: " << printArray.str() << endl;
	return array;
}
#pragma endregion Its all functions used for exercise 1.

#pragma region Methods 
void printArray(void *pStart, int elements, size_t dataLength, bool isChar)
{
	stringstream out;
	out << "Sort Array: ";
	int offSet = dataLength / sizeof(char);
	for (size_t i = 0; i < elements; i++)
	{
		if (isChar)
		{
			long value = getValueAddress(pStart, dataLength);
			char aux = (char)value;
			out << aux;
			pStart = (void *)((int)pStart + sizeof(char));
		}
		else
		{
			long value = getValueAddress(pStart, dataLength);
			out << std::to_string(value);
			pStart = (void *)((int)pStart + sizeof(int));
		}
		out << ", ";
	}
	cout << out.str() << endl;
}

typedef void(*_cmpBubble)(void *pNow, void *pFuture, size_t dataLength);
void bubble(void *pStart, size_t elements, size_t dataLength, _cmpBubble cmpBubble)
{
	void *pReset = pStart;
	for (size_t i = 1; i < elements; i++)
	{
		pStart = pReset;
		for (size_t j = 0; j < (elements - i); j++)
		{
			void *pLast = pStart;
			pStart = (void *)((int)pStart + dataLength);
			cmpBubble(pLast, pStart, dataLength);
		}
	}
	bool isChar = true;
	if (dataLength!=1)
	{
		isChar=false;
	}
	printArray(pReset, elements, dataLength,isChar);
}

#pragma endregion Its all methods used for exercise 1.