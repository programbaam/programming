#include <stdio.h>
#pragma warning ( disable : 4996 )

void main() 
{
	srand((unsigned)time(NULL));
	int nLeverPullCount = 0;
	int Score = 50;
	int nSlot1, nSlot2, nSlot3;

	printf("������ ���� �ð� �Է��Ѵ�: ");
	scanf("%d", &nLeverPullCount);

	while(nLeverPullCount > 0)
	{

		nSlot1 = rand() % 10;		
		nSlot2 = rand() % 10;
		nSlot3 = rand() % 10;


		if ((nSlot1 == nSlot2 || nSlot1 == nSlot3) || nSlot2 == nSlot3)
		{
			if (nSlot1 == nSlot2 && nSlot1 == nSlot3)
			{
				if (nSlot1 == 7)
				{
					Score += 1000;
				}
				else 
				{
					Score += 100;
				}
			}
			else
			{
				Score += 10;
			}
		}
		else
		{
			Score -= 1;
		}

		nLeverPullCount--;

		printf("\r %d %d %d", nSlot1, nSlot2, nSlot3);

		getch();

		if (Score < 1)
		{
			printf("\n���ӿ���");
			break;
		}
	}

	printf("\n���� ��� : %d", Score);


}