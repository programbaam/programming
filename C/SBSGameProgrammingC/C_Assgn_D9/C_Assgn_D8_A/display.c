#include <stdio.h>
#include <stdlib.h> //system("cls");
#include <math.h> //ceilf �ø�
#include "display.h"
#include "character.h"

void menuDisplay()
{
	system("cls");

	printf("1. ���� �����ϱ�\n");
	printf("2. �ҷ�����\n");
	printf("3. ����\n");
	printf("���� : ");
}

void saveMenuDisplay()
{
	system("cls");

	printf("1. ����ϱ�\n");
	printf("2. �����ϱ�\n");
	printf("3. �ҷ�����\n");
	printf("4. �޴��� ������\n");
	printf("5. ����\n");
	printf("���� : ");
}

void display(CHARACTER** arrCharacters, GAMESTATUS* gsGameStatus)
{
	int iRow;
	int iColumn;

	iRow = (int)ceilf((float)CHARACTERNUMBER / 5);
	iColumn = (int)ceilf((float)CHARACTERNUMBER / iRow);


	system("cls");

	printf("Turn : %d\n", gsGameStatus->nTurn);

	//ĳ���� ���
	for (int i = 0; i < iRow; i++)
	{
		for (int j = 0; j < iColumn; j++)
		{
			//���� ĳ���� ���
			if (arrCharacters[i + j * iRow] != NULL)
			{
				printf("[%d] Hit:[%d] Hp:[%d]\t", i + j * iRow, arrCharacters[i + j * iRow]->nDamage,
					arrCharacters[i + j * iRow]->nLife);
			}
			else
			{
				//���� ĳ���� ���
				printf("\033[0;31m[%d] Hit:[X] Hp:[��]\033[0m\t", i + j * iRow);
			}
		}
		printf("\n");
	}

	printf("���� ĳ���� : %d��\n", gsGameStatus->nAliveCharacters);
	printf("��� ĳ���� : %d��\n", gsGameStatus->nDeadCharacters);
	printf("��Ȱ ĳ���� : %d��\n", gsGameStatus->nRevivedCharacters);
	printf("�̹� �������� ���� ĳ���� : %d��\n", gsGameStatus->nTurnDeadCharacters);
	printf("�̹� ���ݿ� ���� ���� ���� ĳ���� : %d��\n", gsGameStatus->nTurnSafeCharacters);

	printf("Enter�� ������ ��� ����˴ϴ�.\n");
	printf("�����Ͻ÷��� sŰ�� �����ּ���.\n");
	
}