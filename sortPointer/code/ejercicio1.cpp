#include "stdafx.h"
#include <iostream>
#include "exercise1.h"
#include <string>
using namespace std;
const int lengthArray = 5;
int main()
{
	int out;
	int option = 0;
	bool correctOption = false;
	do
	{
		try
		{
			printf("Select the number option:\r\n");
			printf("1. Sort to char array\r\n");
			printf("2. Sort to int array\r\n");
			fflush(stdout); //vacíamos el buffer de salida
			if (scanf_s("%d", &option) != 1)
			{
				throw std::runtime_error("Failed");
			}
			if ((option < 1) || (option > 2))
			{
				throw std::runtime_error("Failed");
			}
			correctOption = true;
		}
		catch (...)
		{
			correctOption = false;
		}
	} while (!correctOption);
	void *pStart = 0;
	switch (option)
	{
	case 1:
	{
		char *pStart = createCharVector();
		bubble((void *)pStart, lengthArray, sizeof(char), (_cmpBubble)cmpBubble);
		break;
	}
	case 2:
	{
		int *pStart = createIntegerVector();
		bubble((void *)pStart, lengthArray, sizeof(int), (_cmpBubble)cmpBubble);
		break;
	}
	default:
		break;
	}
	cin >> out;
	return 0;
}
