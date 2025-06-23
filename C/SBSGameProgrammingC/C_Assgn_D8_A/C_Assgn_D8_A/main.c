#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "character.h"
#include "display.h"


void main()
{
	srand((unsigned int)time(NULL));

	// ĳ���� ����ü �迭
	// ���� ĳ������ �ε����� �����ϴ� �迭
	// ���ӿ��� ĳ���͵��� ��Ȳ�� �����ϴ� ����ü
	CHARACTER arrCharacters[CHARACTERNUMBER];
	int arrDeadCharacterIndex[CHARACTERNUMBER];
	GAMESTATUS gsGameStatus;

	//���� �����ʱ�ȭ
	initGameStatus(&gsGameStatus);

	//ĳ���� �ʱ�ȭ
	for (int i = 0; i < CHARACTERNUMBER; i++)
	{
		initCharacter(&arrCharacters[i]);

		//������ ���� ĳ���� ��ü ũ��� ǥ��
		//�ִ� �ε����� CHARACTERNUMBER - 1 �̱� ������
		//���� ���� ĳ���Ͱ� ���⿡ ������ ������ �ʱ�ȭ
		arrDeadCharacterIndex[i] = CHARACTERNUMBER;
	}

	
	while (1)
	{
		//ĳ���� ������
		for (int i = 0; i < CHARACTERNUMBER; i++)
		{
			//������ 0 ~ 10
			int nDamage = rand() % 11;

			//takeDamage �Լ��� ���� ��� TRUE ��ȯ
			if (takeDamage(&arrCharacters[i], nDamage))
			{
				//���� ĳ���� �ε����� ����
				arrDeadCharacterIndex[gsGameStatus.nDeadCharacters] = i;

				//�̹� �� ���� ĳ���� �� ����
				//��� ĳ���� �� ����
				gsGameStatus.nDeadCharacters++;
				gsGameStatus.nTurnDeadCharacters++;
				gsGameStatus.nAliveCharacters--;
			}

			//�������� 0�� ��� �̹� ���ݿ� ���� ���� ���� ĳ���� ����
			if (nDamage == 0)
				gsGameStatus.nTurnSafeCharacters++;
		}


		//ĳ���� ��Ȱ
		reviveCharacters(arrCharacters, arrDeadCharacterIndex, &gsGameStatus);

		//ȭ�� ���
		display(arrCharacters, &gsGameStatus);

		if(getch() == '\\') break;

		gsGameStatus.nTurn++;
		gsGameStatus.nTurnDeadCharacters = 0;
		gsGameStatus.nTurnSafeCharacters = 0;
		gsGameStatus.nRevivedCharacters = 0;
	}

}

