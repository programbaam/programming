#include "Strcat.h"
#include "Strlen.h"

char* __strcat(char* pDst, const char* pSrc)
{
	int iDst = __strlen(pDst);
	int iSrc = 0;

	
	
	while (*(pSrc + iSrc) != '\0')
	{
		*(pDst + iDst) = *(pSrc + iSrc);
		iDst++;
		iSrc++;
	}

	return pDst;
}