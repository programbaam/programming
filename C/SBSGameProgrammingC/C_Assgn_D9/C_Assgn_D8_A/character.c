#include <stdlib.h>
#include "character.h"

//ĳ���� ����ü �ʱ�ȭ
CHARACTER* initCharacter(CHARACTER* chrCharacter)
{
	if (chrCharacter != NULL)
	{
		free(chrCharacter);
		chrCharacter = NULL;
	}

	chrCharacter = (CHARACTER*)malloc(sizeof(CHARACTER));
	
	if (chrCharacter == NULL) return  NULL;

	chrCharacter->nLife = rand() % 51 + 50;
	chrCharacter->nDamage = 0;

	return chrCharacter;
}

//���ӻ��� �ʱ�ȭ
void initGameStatus(GAMESTATUS* gsGameStatus)
{
	gsGameStatus->nTurn = 0;
	gsGameStatus->nDeadCharacters = 0;
	gsGameStatus->nAliveCharacters = CHARACTERNUMBER;
	gsGameStatus->nRevivedCharacters = 0;
	gsGameStatus->nTurnDeadCharacters = 0;
	gsGameStatus->nTurnSafeCharacters = 0;
}

//������ �޴� �Լ�
BOOL takeDamage(CHARACTER** chrCharacter, int nDamage)
{
	// �̹� �Ͽ� �׾��� �� ���� �˱����� BOOL ��ȯ
	if (*chrCharacter == NULL) // �̹� ���� ��� false ��ȯ
		return FALSE;

	(*chrCharacter)->nDamage = nDamage;
	(*chrCharacter)->nLife -= nDamage;

	if ((*chrCharacter)->nLife <= 0)
	{
		free(*chrCharacter);
		*chrCharacter = NULL;
		return TRUE; // ���� ��� true ��ȯ
	}

	// �� �׾��⿡ false ��ȯ
	return FALSE;
}

//ĳ���� ��Ȱ �Լ�
void reviveCharacters(CHARACTER** arrCharacters,
	int* arrDeadCharacterIndex, GAMESTATUS* gsGameStatus)
{
	//���� ĳ������ 10�ۼ�Ʈ ����
	gsGameStatus->nRevivedCharacters = gsGameStatus->nDeadCharacters / 10;

	//����� �� ĳ���� ���� ���ٸ� ����
	if (gsGameStatus->nRevivedCharacters == 0) return;

	//��Ȱ�� ĳ���� �� ��ŭ �ݺ�
	int iRevieIterator = gsGameStatus->nRevivedCharacters;
	for (int i = 0; i < iRevieIterator; i++)
	{
		//iRevive(���� ĳ���� �ε��� ������ �迭�� �ε���) = ���� ĳ������ ��
		//��� ĳ���Ͱ� �׾��ٸ� �ִ�� - 1 �Ѵ�.
		int iReviveIndex = gsGameStatus->nDeadCharacters;
		if (iReviveIndex == CHARACTERNUMBER)
			iReviveIndex = CHARACTERNUMBER - 1;


		//������ ���� ����ִٸ� �̹� ��Ȱ��Ų �ε����̱⿡ �ٽ� ������ ������.
		while (arrDeadCharacterIndex[iReviveIndex] == CHARACTERNUMBER)
		{
			iReviveIndex = rand() % gsGameStatus->nDeadCharacters;
		}

		//�ش� �ε��� ĳ���� ��Ȱ��Ű�� ���� ĳ���� �ε��� �迭�� ������ �� ����
		arrCharacters[arrDeadCharacterIndex[iReviveIndex]] = initCharacter(arrCharacters[arrDeadCharacterIndex[iReviveIndex]]);
		arrDeadCharacterIndex[iReviveIndex] = CHARACTERNUMBER;

		//���ӻ��� ��Ȱ�� ĳ���� ��, ����ִ� ĳ���� �� ����
		gsGameStatus->nAliveCharacters++;
	}

	// ���� ĳ���� �ε��� �迭 - ������ ���� �����
	// �տ� �ִ� ������ ���� �˻� �� ���� �ڿ� �ִ� ������ ä���.
	int iStart = 0;
	int iEndIndex = gsGameStatus->nDeadCharacters - 1;
	for (iStart = 0; iStart < iEndIndex; iStart++)
	{
		if (arrDeadCharacterIndex[iStart] == CHARACTERNUMBER)
		{
			while (arrDeadCharacterIndex[iEndIndex] == CHARACTERNUMBER)
			{
				iEndIndex--;
			}
			if (iStart > iEndIndex) break;

			// �� �ε��� ������ ���� ���� �ڿ� �ִ� ������ ����
			arrDeadCharacterIndex[iStart] = arrDeadCharacterIndex[iEndIndex];
			arrDeadCharacterIndex[iEndIndex] = CHARACTERNUMBER;
			iEndIndex--;

		}
	}

	//���� ĳ���� ������ ��Ȱ�� ĳ���� ���� ����.
	gsGameStatus->nDeadCharacters -= gsGameStatus->nRevivedCharacters;
}