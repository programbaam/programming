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

	//�Ҵ� ������ �� ��ȯ
	if (sTemp == '\0') 
		return '\0';

	//�� ��Ʈ���� �ش��ϴ� �ε���
	int iTemp = 0;
	int iSrc1 = 0;
	int iSrc2 = 0;

	// �����ϸ鼭 ����
	while (iTemp < nSize + 1)
	{
		// �Ѵ� �ΰ��̸� �극��ũ
		if (pSrc1[iSrc1] == '\0' || pSrc2[iSrc2] == '\0')
			break;

		//�ε����� Ȧ���̳� ¦���̳� ���� �����ư��� ����
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

	//�� �� �ϳ��� ���� ���
	while (iTemp < nSize + 1)
	{
		//�Ѵ� ���̸� ������ �η� ä��, �ϳ��� ���̸� ������ �� �״�� ����
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

	//������ ���ڿ� �ΰ� �ֱ�
	if (iTemp == nSize + 1) sTemp[nSize] = '\0';

	return sTemp;
}

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
