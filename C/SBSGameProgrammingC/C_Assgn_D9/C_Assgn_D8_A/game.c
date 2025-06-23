#include <stdio.h>
#include <stdlib.h>
#include "character.h"



void initGame(CHARACTER** arrCharacters,
	int* arrDeadCharacterIndex, GAMESTATUS* gsGameStatus)
{
	//���� �����ʱ�ȭ
	initGameStatus(gsGameStatus);

	//ĳ���� �ʱ�ȭ
	for (int i = 0; i < CHARACTERNUMBER; i++)
	{
		arrCharacters[i] = initCharacter(arrCharacters[i]);
		if (arrCharacters[i] == NULL)
		{
			gsGameStatus->nDeadCharacters++;
			gsGameStatus->nAliveCharacters--;
		}

		//������ ���� ĳ���� ��ü ũ��� ǥ��
		//�ִ� �ε����� CHARACTERNUMBER - 1 �̱� ������
		//���� ���� ĳ���Ͱ� ���⿡ ������ ������ �ʱ�ȭ
		arrDeadCharacterIndex[i] = CHARACTERNUMBER;
	}
}

void updateTurnStatus(CHARACTER** arrCharacters,
	int* arrDeadCharacterIndex, GAMESTATUS* gsGameStatus)
{
	gsGameStatus->nTurn++;
	gsGameStatus->nTurnDeadCharacters = 0;
	gsGameStatus->nTurnSafeCharacters = 0;
	gsGameStatus->nRevivedCharacters = 0;

	//ĳ���� ������
	for (int i = 0; i < CHARACTERNUMBER; i++)
	{
		//������ 0 ~ 10
		int nDamage = rand() % 11;

		//takeDamage �Լ��� ���� ��� TRUE ��ȯ
		if (takeDamage(&arrCharacters[i], nDamage))
		{
			//���� ĳ���� �ε����� ����
			arrDeadCharacterIndex[gsGameStatus->nDeadCharacters] = i;

			//�̹� �� ���� ĳ���� �� ����
			//��� ĳ���� �� ����
			gsGameStatus->nDeadCharacters++;
			gsGameStatus->nTurnDeadCharacters++;
			gsGameStatus->nAliveCharacters--;
		}

		//�������� 0�� ��� �̹� ���ݿ� ���� ���� ���� ĳ���� ����
		if (nDamage == 0)
			gsGameStatus->nTurnSafeCharacters++;
	}


	//ĳ���� ��Ȱ
	reviveCharacters(arrCharacters, arrDeadCharacterIndex, gsGameStatus);


}

//�޸� �Ҵ� �ݳ�
void cleanupGame(CHARACTER** arrCharacters)
{
	//ĳ���� ����ü�� �޸� �Ҵ��Ͽ��⿡ ��� ĳ���� �޸� �ݳ�
	for (int i = 0; i < CHARACTERNUMBER; i++)
	{
		if (arrCharacters[i] != NULL)
		{
			free(arrCharacters[i]);
			arrCharacters[i] = NULL;
		}
	}
}