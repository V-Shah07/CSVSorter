#include <stdio.h>
#include "Header.h"
#include <string.h>
#include <stdlib.h>

char* fileName;
char* columnName;
enOrder order;
enTypes type;

void storeInfo(char** Args)
{
	size_t elementSize = 0;


	//fileName
	elementSize = strlen(Args[0]) + 1;
	fileName = (char*)calloc(elementSize, sizeof(char));
	memcpy(fileName, Args[0], elementSize * sizeof(char));

	//columnName
	elementSize = strlen(Args[1]) + 1;
	columnName = (char*)calloc(elementSize, sizeof(char));
	memcpy(columnName, Args[1], elementSize * sizeof(char));

	//columnOrder
	elementSize = strlen(Args[2]);
	if (elementSize != 1)
	{
		Args[2][0] = 'x'; //set to something random so it goes to default
	}
	switch (Args[2][0])
	{
	case 'a': case 'A':
		order = Ascending;
		break;
	case 'd': case 'D':
		order = Descending;
		break;
	default:
		printf("NOT A VALID ORDER TYPE\a");
		exit(-1);
		break;
	}

	//columnType
	elementSize = strlen(Args[3]);
	if (elementSize != 1)
	{
		Args[3][0] = 'x'; //set to something random so it goes to default
	}
	switch (Args[3][0])
	{
	case 'n': case 'N':
		type = NumericType;
		break;
	case 's': case 'S':
		type = StringType;
		break;
	case 'd': case 'D':
		type = DateType;
		break;
	default:
		printf("NOT A VALID SORT TYPE\a");
		exit(-1);
		break;
	}


}