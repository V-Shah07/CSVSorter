#pragma once

/*ABSTRACT DATA TYPES*/
enum enTypes{NumericType, StringType, DateType};
enum enOrder{Ascending, Descending};

struct sortList
{
	char* line;
	char* element; //pointer to the part of line to check(eg. DOB, Fname)
};
/*FUNCTION DECLERATIONS*/
char* giveHeaderRow(char* allText, int* numCols);

int getColumnNumber(const char* headerRow, const char* columnName);


int compareInt(const void* num1, const void* num2);
int compareString(const void* string1, const void* string2);
int compareDate(const void* date1, const void* date2);

char** singleToDouble(char* text);

void storeInfo(char** Args);

void initList(sortList* list, int colIndex, int numRows, char** mainText);
/*GLOBAL VARIABLES*/

extern char* fileName;
extern char* columnName;
extern enOrder order;
extern enTypes type;
extern int numRows;