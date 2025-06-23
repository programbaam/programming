#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "RandMem.h"

unsigned char* __randmem(int nSize)
{
	//�������� 4�� + 40��°���� ���� + ������ �� ��
	int nStrSize = nSize * 4 + nSize / 10 + 1;
	unsigned char* sRandmem = (char*)malloc(sizeof(char) * (nStrSize));
	int nRandom = 0;


	if (sRandmem == '\0') //�Ҵ� ������ �� ��ȯ
		return '\0';

	for (int i = 0; i < nStrSize; i++)
	{
		//4��° ���� ������ ����
		if (((i + 1) % 41) % 4 == 1)
			nRandom = rand() % ('Z' - 'A' + 1);

		sRandmem[i] = 'A' + nRandom;

		// 40��° ä��� newline
		if ((i + 1) % 41 == 0)
			sRandmem[i] = '\n';
	}

	sRandmem[nStrSize - 1] = '\0'; //������ ���ڿ� �ΰ�

	printf("%s\n", sRandmem);

	return sRandmem;
}
