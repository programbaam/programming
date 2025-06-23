#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "RandMem.h"

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
