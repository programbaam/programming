#include "Strlen.h"

int __strlen(char* pStr)
{
	int nStringLength = 0;
	int i = 0;

	while (*(pStr + i) != '\0')
	{
		i++;
		nStringLength++;
	}

	return nStringLength;
}