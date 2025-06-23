#include <malloc.h>
#include "CrossMemCpy.h"

unsigned char* __crossmemcpy(const unsigned char* pSrc2, const unsigned char* pSrc1, int nSize)
{
	unsigned char* sTemp = (char*)malloc(sizeof(char) * (nSize + 1));

	//할당 못받음 널 반환
	if (sTemp == '\0')
		return '\0';

	//각 스트링에 해당하는 인덱스
	int iTemp = 0;
	int iSrc1 = 0;
	int iSrc2 = 0;

	while (iTemp < nSize + 1)
	{
		// 복사하는 문자열 중 하나가 널값이면
		if (pSrc1[iSrc1] == '\0' || pSrc2[iSrc2] == '\0')
		{
			if (pSrc1[iSrc1] == '\0' && pSrc2[iSrc2] == '\0') // 둘 다 널이면 나머지 문자열 널로 채움
			{
				sTemp[iTemp] = '\0';
			}
			else if (pSrc1[iSrc1] == '\0') //pSrc1이 널이면 pSrc2 나머지 복사
			{
				sTemp[iTemp] = pSrc2[iSrc2];
				iSrc2++;
			}
			else if (pSrc2[iSrc2] == '\0') //pSrc2가 널이면 pSrc1 나머지 복사
			{
				sTemp[iTemp] = pSrc1[iSrc1];
				iSrc1++;
			}
			iTemp++;
			continue;
		}

		//인덱스가 홀수이냐 짝수이냐 따라서 번갈아가며 저장
		if (iTemp % 2 == 0)
		{
			sTemp[iTemp] = pSrc1[iSrc1];
			iSrc1++;
		}
		else
		{
			sTemp[iTemp] = pSrc2[iSrc2];
			iSrc2++;
		}

		iTemp++;
	}

	//마지막 문자열 널값 넣기
	if (iTemp == nSize + 1) sTemp[nSize] = '\0';

	return sTemp;
}