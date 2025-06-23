#include "Strrot.h"

char* __strrot(char* pStr)
{
	if (*pStr == '\0') return pStr;

	
	char chFirst = '\0';
	chFirst = *pStr;
	int i = 0;

	while (*(pStr + i) != '\0')
	{	
		if (*(pStr + i + 1) == '\0')
		{
			*(pStr + i) = chFirst;
			break;
		}
		*(pStr + i) = *(pStr+ i + 1);
		i++;
	}

	return pStr;
}