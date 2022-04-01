#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Header.h"


void initList(sortList *list, int colIndex, int numRows, char**mainText)
{
	char** mover = mainText;

	int curRow = 1;
	int ct = 0;
	int len;
	while (mover[curRow] && (curRow <= numRows))
	{
		len = strlen(mover[curRow]) + 1;
		list[curRow - 1].line = (char*)calloc(len, sizeof(char));
		memcpy(list[curRow - 1].line, mover[curRow], len); //used since later something else will point to mover and modify it
		
		//reach the target colomn
		for (int i = 0; (i < colIndex) && mover[curRow]; ++i)
		{
			mover[curRow] = strchr(mover[curRow], ',');
			++mover[curRow];
		}


		list[curRow-1].element = mover[curRow];
		
		ct = 0;
		while ((*mover[curRow] != EOF) && (*mover[curRow] != '\0') && (*mover[curRow] != ','))//last col is before a \0 or eof
		{
			++mover[curRow];
			++ct;
		}

		list[curRow - 1].element[ct] = '\0';

		++curRow;
	}

}