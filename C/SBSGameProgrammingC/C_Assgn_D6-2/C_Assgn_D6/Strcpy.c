#include "Strcpy.h"
#include "Strlen.h"
    
void __strcpy(char* pDst, const char* pSrc)
{
	int i = 0;
	int bSrcNullCheck = 0;
	int nLength = __strlen(pDst);

	do 
	{
		//pDst ��ŭ�� ����
		if (nLength == i - 1)
		{
			break;
		}

		*(pDst + i) = *(pSrc + i);

		i++;

	} while (*(pSrc + i) != '\0');

	//pDst�� pSrc���� Ŭ ��� �� ���ڿ� \0��
	while (*(pDst + i) != '\0')
	{
		*(pDst + i) = '\0';
		i++;
	}

}