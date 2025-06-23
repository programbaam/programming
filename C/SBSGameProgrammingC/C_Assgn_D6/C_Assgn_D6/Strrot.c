#include "Strrot.h"

char* __strrot(char* pStr)
{
	if (pStr[0] == '\0') return pStr;

	int i = 0;
	char chFirst = '\0';
	chFirst = pStr[0];

	while (1)
	{	
		if (pStr[i + 1] == '\0')
		{
			pStr[i] = chFirst;
			break;
		}
		pStr[i] = pStr[i + 1];
		i++;
	}

	return pStr;
}