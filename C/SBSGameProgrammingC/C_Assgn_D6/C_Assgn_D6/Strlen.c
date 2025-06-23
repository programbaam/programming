#include "Strlen.h"

int __strlen(char* pStr)
{
	int nStringLength = 0;

	while (1)
	{
		if (pStr[nStringLength] == '\0') break;
		nStringLength++;
	}

	return nStringLength;
}