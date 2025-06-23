#include "Strcpy.h"
#include "Strlen.h"
    
void __strcpy(char* pDst, const char* pSrc)
{
	int i = 0;
	int bSrcNullCheck = 0;
	int nLength = __strlen(pDst);

	do 
	{
		//pDst 만큼만 복사
		if (nLength == i - 1)
		{
			break;
		}

		*(pDst + i) = *(pSrc + i);

		i++;

	} while (*(pSrc + i) != '\0');

	//pDst가 pSrc보다 클 경우 뒤 문자열 \0값
	while (*(pDst + i) != '\0')
	{
		*(pDst + i) = '\0';
		i++;
	}

}