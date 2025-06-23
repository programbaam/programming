#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>


unsigned char* __crossmemcpy(const unsigned char* pSrc2, const unsigned char* pSrc1, int nSize);
unsigned char* __randmem(int nSize);


void main()
{
	srand((unsigned int)time(NULL));

	unsigned char* (*fnStrMem)();

	char sCrossmemcpy1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char sCrossmemcpy2[] = "ZXYWVUTSRQPONMLKJIHGFEDCBA";
	char* sCrossmemcpy3 = '\0';

	fnStrMem = __crossmemcpy;

	sCrossmemcpy3 = fnStrMem(sCrossmemcpy2, sCrossmemcpy1, 40);

	printf("%s\n", sCrossmemcpy1);
	printf("%s\n", sCrossmemcpy2);
	printf("%s\n", sCrossmemcpy3);

	free(sCrossmemcpy3);

	char sCrossmemcpy4[] = "ABCD";
	char sCrossmemcpy5[] = "EFGHIJK";
	char* sCrossmemcpy6 = '\0';

	sCrossmemcpy6 = fnStrMem(sCrossmemcpy5, sCrossmemcpy4, 40);

	printf("%s\n", sCrossmemcpy4);
	printf("%s\n", sCrossmemcpy5);
	printf("%s\n", sCrossmemcpy6);

	free(sCrossmemcpy6);


	fnStrMem = __randmem;



	free(fnStrMem(14));

}



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

	// 교차하면서 복사
	while (iTemp < nSize + 1)
	{
		// 둘다 널값이면 브레이크
		if (pSrc1[iSrc1] == '\0' || pSrc2[iSrc2] == '\0')
			break;

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

	//둘 중 하나가 널일 경우
	while (iTemp < nSize + 1)
	{
		//둘다 널이면 나머지 널로 채움, 하나면 널이면 나머지 값 그대로 복사
		if (pSrc1[iSrc1] == '\0' && pSrc2[iSrc2] == '\0')
		{
			sTemp[iTemp] = '\0';
		}
		else if (pSrc1[iSrc1] == '\0') 
		{
			sTemp[iTemp] = pSrc2[iSrc2];
			iSrc2++;
		}
		else if (pSrc2[iSrc2] == '\0')
		{
			sTemp[iTemp] = pSrc1[iSrc1];
			iSrc1++;
		}

		iTemp++;
	}

	//마지막 문자열 널값 넣기
	if (iTemp == nSize + 1) sTemp[nSize] = '\0';

	return sTemp;
}

unsigned char* __randmem(int nSize)
{
	//사이즈의 4배 + 40번째마다 개행 + 마지막 널 값
	int nStrSize = nSize * 4 + nSize / 10 + 1;
	unsigned char* sRandmem = (char*)malloc(sizeof(char) * (nStrSize));
	int nRandom = 0;
	

	if (sRandmem == '\0') //할당 못받음 널 반환
		return '\0';

	for (int i = 0; i < nStrSize; i++)
	{
		//4번째 마다 랜덤수 추출
		if (((i + 1) % 41) % 4 == 1) 
			nRandom = rand() % ('Z' - 'A' + 1);

		sRandmem[i] = 'A' + nRandom;

		// 40번째 채우면 newline
		if ((i + 1) % 41 == 0)
			sRandmem[i] = '\n';
	}

	sRandmem[nStrSize - 1] = '\0'; //마지막 문자열 널값

	printf("%s\n", sRandmem);

	return sRandmem;
}
