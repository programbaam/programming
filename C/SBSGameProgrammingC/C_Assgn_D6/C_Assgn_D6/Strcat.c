#include "Strcat.h"
#include "Strlen.h"

char* __strcat(char* pDst, const char* pSrc)
{
	int iDst = __strlen(pDst);
	int iSrc = 0;
	while (1)
	{
		if (pSrc[iSrc] == '\0') break;
		pDst[iDst] = pSrc[iSrc];
		iDst++;
		iSrc++;
	}

	return pDst;
}