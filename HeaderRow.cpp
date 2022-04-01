#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* giveHeaderRow(char* allText, int* numCols)
{
	int colsFound = 0;
	int len = 0;
	for (char* p = allText; *p != '\n'; ++p)
	{
		if (*p == ',')
		{
			++colsFound;
		}
		++len;
	}
	colsFound += 1; //n columns means n + 1 items
	len += 1; //for null

	char* headerRow = (char*)malloc(len);
	memcpy(headerRow, allText, len);
	headerRow[len - 1] = '\0'; //change \n to null

	*numCols = colsFound;

	return headerRow;
}
int getColumnNumber(const char* headerRow, const char* columnName)
{
	int lenColumn = strlen(columnName);
	int index = 0;
	for (const char* p = headerRow; p; ++p, ++index)
	{
		if (memcmp(p, columnName, lenColumn) == 0)
		{
			return index;
		}
		p = strchr(p, ',');
		if (p == NULL)
		{
			break; // this is over here because in loop first p gets incremented and then checked for null
		}
	}
	return -1;
}