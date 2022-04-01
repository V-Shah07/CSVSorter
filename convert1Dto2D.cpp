#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numRows;

char** singleToDouble(char* text)
{
	int numOfRowInArray = 2;
	int* numCharPerCol = (int*)calloc(numOfRowInArray, sizeof(int));
	if (numCharPerCol == NULL)
	{
		printf("Couldn't allocate enough space!");
		exit(-1);
	}
	char** mainArray;

	int numRow = 0;
	int charInRow = 0;
	for (char* p = text; *p; ++p)
	{


	
			
		if (*p == '\n')
		{
			if (numRow > (numOfRowInArray - 1))//minus one since you can index up to n -1
			{
				if (numCharPerCol != NULL)
				{
					numCharPerCol = (int*)realloc(numCharPerCol, (size_t)numRow * 2 * sizeof(int));
					//make size double of what needed so realloc not too frequent
					if (numCharPerCol == NULL)
					{
						printf("Not enough memory!"); //makes sure realloc doesn't return NULL
						exit(-1);
					}
				}
				else
				{
					printf("Not enough space to be allocated!");
					exit(-1);
				}
			}
			++charInRow; //add one for the new line
			numCharPerCol[numRow] = charInRow;
			++numRow;
			charInRow = 0;
			*p = '\0'; //make new line into null character
			++p; //pass the new line
		}

		++charInRow;
	}

	numRows = numRow;

	mainArray = (char**)calloc(numRow, sizeof(int*));

	int amtMoveForward = 0;
	for (int i = 0; i < numRow; ++i)
	{
		mainArray[i] = (char*)calloc(numCharPerCol[i], sizeof(char));
		memcpy(mainArray[i], text + amtMoveForward, numCharPerCol[i]);
		amtMoveForward += numCharPerCol[i];
	}
	

	return mainArray;


}