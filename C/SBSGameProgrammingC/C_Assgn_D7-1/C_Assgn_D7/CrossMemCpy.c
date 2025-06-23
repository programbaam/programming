#include <malloc.h>
#include "CrossMemCpy.h"

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

	while (iTemp < nSize + 1)
	{
		// �����ϴ� ���ڿ� �� �ϳ��� �ΰ��̸�
		if (pSrc1[iSrc1] == '\0' || pSrc2[iSrc2] == '\0')
		{
			if (pSrc1[iSrc1] == '\0' && pSrc2[iSrc2] == '\0') // �� �� ���̸� ������ ���ڿ� �η� ä��
			{
				sTemp[iTemp] = '\0';
			}
			else if (pSrc1[iSrc1] == '\0') //pSrc1�� ���̸� pSrc2 ������ ����
			{
				sTemp[iTemp] = pSrc2[iSrc2];
				iSrc2++;
			}
			else if (pSrc2[iSrc2] == '\0') //pSrc2�� ���̸� pSrc1 ������ ����
			{
				sTemp[iTemp] = pSrc1[iSrc1];
				iSrc1++;
			}
			iTemp++;
			continue;
		}

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

	//������ ���ڿ� �ΰ� �ֱ�
	if (iTemp == nSize + 1) sTemp[nSize] = '\0';

	return sTemp;
}