#include <stdio.h>
#include "Header.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#pragma warning(disable:4996)

#define COMPARE_INT_INDEX 0
#define COMPARE_STRING_INDEX 1
#define COMPARE_DATE_INDEX 2



int main(int argc, char*argv [])
{
	int fileSize;
	char* tempText;
	int numCols = 0;
	int targetColumnIndex;
	char** mainText;
	int (*compareFunctions[])(const void*, const void*) = { compareInt, compareString, compareDate };
	int cmpFuncIndex;


	storeInfo(argv + 1);


	cmpFuncIndex = type; //sets the index so that we know which compare function to use in the future


	//Open the file and find the size
	FILE* mainFile;
	
	mainFile = fopen(fileName, "r");
	if (mainFile == NULL)
	{
		printf("Couldn't open file");
	}
	fseek(mainFile, 0, SEEK_END); //go to end of file
	fileSize = ftell(mainFile);
	fseek(mainFile, 0, SEEK_SET);

	tempText = (char*)calloc(fileSize, sizeof(char));

	fread(tempText, sizeof(char), fileSize, mainFile);
	//Process header row

	char* headerRow = giveHeaderRow(tempText, &numCols); 
	// ^^^1d pointer used since future 2d one will have nulls instead of \n


	//convert text to a 2d array
	mainText = singleToDouble(tempText);



	targetColumnIndex = getColumnNumber(headerRow, columnName);
	if (targetColumnIndex == -1)
	{
		printf("No such column");
		exit(-1);
	}

	sortList* list = (sortList*)calloc(numRows - (size_t)1, sizeof(sortList));

	initList(list, targetColumnIndex, numRows - 1, mainText);

	qsort(list, numRows - (size_t)1, sizeof(sortList), compareFunctions[cmpFuncIndex]);

	fclose(mainFile);
	mainFile = fopen(fileName, "w"); 
	fputs(headerRow, mainFile);
	fputc('\n', mainFile);
	for (int i = 0; i < numRows - 1; ++i)
	{
		fputs(list[i].line, mainFile);
		fputc('\n', mainFile);
	}
	fclose(mainFile);
}