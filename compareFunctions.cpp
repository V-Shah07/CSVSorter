#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "Header.h"


#pragma warning(disable:4996)

int inverted()
{
	if (order == Ascending)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
int stringToInt(const char* number)
{
	int* digits = (int*)calloc(strlen(number), sizeof(int));
	int index = 0;

	while (*number)
	{
		if (isdigit(*number) || *number == '-')
		{
			digits[index] = *number - '0';
			++index;
		}
		else
		{
			printf("Not a valid number!");
			exit(-1);
		}
		++number;
	}
	--index;
	int num = 0;
	for (int i = 0; index >= 0; ++i, --index)
	{
		num += digits[i] * (int)(pow(10, index + (double)1) / 10); //division by 10 and add 1 since 10 ^ 0 = 0 in computer
	}

	return num;
	
}
int compareInt(const void* num1, const void* num2)
{
	const sortList* number1 = (sortList*)num1;
	const sortList* number2 = (sortList*)num2;
	
	int n1 = stringToInt(number1->element);
	int n2 = stringToInt(number2->element);

	int inverse = inverted();
	if (n1 > n2)
	{
		return 1 * inverse;;
	}
	else if (n1 == n2)
	{
		return 0;
	}
	else
	{
		return -1 * inverse;
	}
}
int compareString(const void* string1, const void* string2)
{
	const sortList* str1 = (sortList*)string1;
	const sortList* str2 = (sortList*)string2;
	return inverted() * strcmp(str1->element, str2->element);
}
int compareDate(const void* date1, const void* date2)
{
	sortList* x = (sortList*)date1;
	sortList* y = (sortList*)date2;
	char* d1 = x->element;
	char* d2 = y->element;

	char* month1 = (char*)malloc((2+1) * sizeof(char));
	char* month2 = (char*)malloc((2+1) * sizeof(char));

	int i;
	for (i = 0;*d1 != '/'; ++d1,++i)
	{
		month1[i] = *d1;
	}
	month1[i] = '\0';
	for (i = 0; *d2 != '/'; ++d2, ++i)
	{
		month2[i] = *d2;
	}
	month2[i] = '\0';

	//pass the slash
	++d1;
	++d2;

	char* day1 = (char*)malloc((2 + 1) * sizeof(char));
	char* day2 = (char*)malloc((2 + 1) * sizeof(char));
	
	for (i = 0; *d1 != '/'; ++d1, ++i)
	{
		day1[i] = *d1;
	}
	day1[i] = '\0';
	for (i = 0; *d2 != '/'; ++d2, ++i)
	{
		day2[i] = *d2;
	}
	day2[i] = '\0';
	
	//pass the slash
	++d1; 
	++d2;

	char* year1 = (char*)malloc((4 + 1) * sizeof(char));
	char* year2 = (char*)malloc((4 + 1) * sizeof(char));
	
	for (i = 0; *d1; ++d1, ++i)
	{
		year1[i] = *d1;
	}
	year1[i] = '\0';
	for (i = 0; *d2; ++d2, ++i)
	{
		year2[i] = *d2;
	}
	year2[i] = '\0';

	int finalDate1 = 100 * stringToInt(year1) + 10 * stringToInt(month1) + 1 * stringToInt(day1);
	int finalDate2 = 100 * stringToInt(year2) + 10 * stringToInt(month2) + 1 * stringToInt(day2);

	return inverted() * (finalDate1 - finalDate2);
}