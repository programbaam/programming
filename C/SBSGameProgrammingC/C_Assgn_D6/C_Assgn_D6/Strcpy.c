#include "Strcpy.h"

void __strcpy(char* pDst, const char* pSrc)
{
	int i = 0;
	while (1)
	{
		*(pDst+i) = *(pSrc+i);
		if (*(pSrc + i) == '\0')
			break;
		i++;
	}
}