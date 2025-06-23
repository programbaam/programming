#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // ��� ����
#include <time.h>
#include "character.h"
#include "game.h"
#include "save_load.h"
#include "display.h"

#pragma warning (disable : 4996)


void main()
{
	srand((unsigned int)time(NULL));

	// ĳ���� ����ü �迭
	// ���� ĳ������ �ε����� �����ϴ� �迭
	// ���ӿ��� ĳ���͵��� ��Ȳ�� �����ϴ� ����ü
	CHARACTER* arrCharacters[CHARACTERNUMBER];
	int arrDeadCharacterIndex[CHARACTERNUMBER];
	GAMESTATUS gsGameStatus;
	char nMenuSelection = '\0';

	//ĳ���� ������ �迭 �η� �ʱ�ȭ
	for (int i = 0; i < CHARACTERNUMBER; i++)
	{
		arrCharacters[i] = NULL;
	}
	
	
	while (1)
	{
		if (nMenuSelection == 's') //���̺� �޴� â
		{
			while (!(nMenuSelection == '1' || nMenuSelection == '2' || 
				nMenuSelection == '3' || nMenuSelection == '4')) // 1, 2, 3 - ��������, 4 �ʱ� �޴�â
			{
				saveMenuDisplay();
				nMenuSelection = getch();
				switch (nMenuSelection)
				{
				case '1': //�ϴ� �������� ���ư�
					break;
				case '2': //���� �����ϰ� �ϴ� �������� ���ư�
					saveGame(arrCharacters, arrDeadCharacterIndex, &gsGameStatus);
					break;
				case '3': // ���� �ҷ�����
					if (loadGame(arrCharacters, arrDeadCharacterIndex, &gsGameStatus))
						break;
					else
					{
						printf("�ε� ����!\n");
						getch();
						nMenuSelection = 's';
						continue;
					}
				case '4': // �ʱ� �޴�â
					break;
				case '5': // ���� ����
					cleanupGame(arrCharacters); // �Ҵ�� �޸� �ݳ�
					return;
				default: // ���� �� �Է½� �޴�â �ٽ� ���
					continue;
				}
			}
			if (nMenuSelection == '4') continue; //�ʱ� �޴�â
		}
		else //�ʱ� �޴� â 
		{
			while (!(nMenuSelection == '1' || nMenuSelection == '2')) // 1, 2 - ���� ����
			{
				menuDisplay();
				nMenuSelection = getch();
				switch (nMenuSelection)
				{
				case '1': // ���� ���� �����ϱ�
					initGame(arrCharacters, arrDeadCharacterIndex, &gsGameStatus);
					break;
				case '2': // ���� �ҷ�����
					if (loadGame(arrCharacters, arrDeadCharacterIndex, &gsGameStatus))
						break;
					else
					{
						printf("�ε� ����!\n");
						getch();
						nMenuSelection = '4';
						continue;
					}
				case '3': // ���� ����
					cleanupGame(arrCharacters); //�Ҵ�� �޸� �ݳ�
					return;
				default: // ���� �� �Է½� �޴�â �ٽ� ���
					continue;
				}
			}
		}
		
		do // �� ����, �ε�, ���� �簳�ϰ� ù ���� â ����
		{
			display(arrCharacters, &gsGameStatus);
			nMenuSelection = getch();
		} while (!(nMenuSelection == '\r' || nMenuSelection == 's')); // �����̳� �� �ѱ� ���ϸ� �ٽ� â ���

		while (nMenuSelection != 's')  // ������ �ؾ� ��������
		{
			if(nMenuSelection == '\r') // �� �ѱ� Ű(����Ű)�� �Է��ؾ� ���� �Ѿ
				updateTurnStatus(arrCharacters, arrDeadCharacterIndex, &gsGameStatus);
			display(arrCharacters, &gsGameStatus);
			nMenuSelection = getch();
		}
	}

}

