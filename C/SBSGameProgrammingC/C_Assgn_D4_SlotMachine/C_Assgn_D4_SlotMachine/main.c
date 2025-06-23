#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#pragma warning ( disable : 4996 )

#define ONE_SECOND 1000

void main()
{

	srand((unsigned)time(NULL));
	int nLeverPullCount = 0;
	int Score = 50;

	int nDisplaySlot1 = 0;
	int nDisplaySlot2 = 0;
	int nDisplaySlot3 = 0;

	int nRandomSlot1;
	int nRandomSlot2;
	int nRandomSlot3;



	printf("레버를 당기는 시간 입력한다: ");
	scanf("%d", &nLeverPullCount);

	system("cls");

	printf("  |-------------------|---|\n");
	printf("  |  | %d || %d || %d |  | o |\n", (nDisplaySlot1 + 2) % 10, (nDisplaySlot2 + 2) % 10, (nDisplaySlot3 + 2) % 10);
	printf("  |  | %d || %d || %d |  | | |\n", (nDisplaySlot1 + 1) % 10, (nDisplaySlot2 + 1) % 10, (nDisplaySlot3 + 1) % 10);
	printf("  |-------------------| | |\n");
	printf("  |  [ %d ][ %d ][ %d ]  | O |\n", nDisplaySlot1, nDisplaySlot2, nDisplaySlot3);
	printf("  |-------------------|   |\n");
	printf("  |  | %d || %d || %d |  |   |\n", (nDisplaySlot1 + 9) % 10, (nDisplaySlot2 + 9) % 10, (nDisplaySlot3 + 9) % 10);
	printf("  |  | %d || %d || %d |  |   |\n", (nDisplaySlot1 + 8) % 10, (nDisplaySlot2 + 8) % 10, (nDisplaySlot3 + 8) % 10);
	printf("  |-------------------|---|\n");

	printf("레버 남은 횟수 : %d\n", nLeverPullCount);
	printf("현재 스코어 : %d\n", Score);
	getch();


	while (nLeverPullCount > 0) 
	{
		nLeverPullCount--;

		nRandomSlot1 = rand() % 10;

		nRandomSlot2 = rand() % 10;

		nRandomSlot3 = rand() % 10;

		int nSlotCycle = 10;
		int bIsOneCycle = 1;

		while (nSlotCycle>0) {
			system("cls");

			printf("  |-------------------|---|\n");
			printf("  |  | %d || %d || %d |  |   |\n", (nDisplaySlot1 + 2) % 10, (nDisplaySlot2 + 2) % 10, (nDisplaySlot3 + 2) % 10);
			printf("  |  | %d || %d || %d |  |   |\n", (nDisplaySlot1 + 1) % 10, (nDisplaySlot2 + 1) % 10, (nDisplaySlot3 + 1) % 10);
			printf("  |-------------------|   |\n");
			printf("  |  [ %d ][ %d ][ %d ]  | O |\n", nDisplaySlot1, nDisplaySlot2, nDisplaySlot3);
			printf("  |-------------------| | |\n");
			printf("  |  | %d || %d || %d |  | | |\n", (nDisplaySlot1 + 9) % 10, (nDisplaySlot2 + 9) % 10, (nDisplaySlot3 + 9) % 10);
			printf("  |  | %d || %d || %d |  | o |\n", (nDisplaySlot1 + 8) % 10, (nDisplaySlot2 + 8) % 10, (nDisplaySlot3 + 8) % 10);
			printf("  |-------------------|---|\n");

			printf("레버 남은 횟수 : %d\n", nLeverPullCount);
			printf("현재 스코어 : %d\n", Score);

			
			if (bIsOneCycle == 1) 
			{
				nSlotCycle--;
				if (nSlotCycle < 1)
				{
					bIsOneCycle = 0;
					nSlotCycle = 1;
				}

				nDisplaySlot1 = (nDisplaySlot1 + 1) % 10;
				nDisplaySlot2 = (nDisplaySlot2 + 1) % 10;
				nDisplaySlot3 = (nDisplaySlot3 + 1) % 10;
			}
			else 
			{
				if ((nRandomSlot1 == nDisplaySlot1 && nRandomSlot2 == nDisplaySlot2) && nRandomSlot3 == nDisplaySlot3)
				{
					break;
				}

				if (nRandomSlot1 != nDisplaySlot1)
				{
					nDisplaySlot1 = (nDisplaySlot1 + 1) % 10;
					nDisplaySlot2 = (nDisplaySlot2 + 1) % 10;
					nDisplaySlot3 = (nDisplaySlot3 + 1) % 10;
				}
				else if (nRandomSlot2 != nDisplaySlot2)
				{
					nDisplaySlot2 = (nDisplaySlot2 + 1) % 10;
					nDisplaySlot3 = (nDisplaySlot3 + 1) % 10;
				}
				else
				{
					nDisplaySlot3 = (nDisplaySlot3 + 1) % 10;
				}
			}




			Sleep(ONE_SECOND / 8);
		}

		system("cls");

		printf("  |-------------------|---|\n");
		printf("  |  | %d || %d || %d |  | o |\n", (nDisplaySlot1 + 2) % 10, (nDisplaySlot2 + 2) % 10, (nDisplaySlot3 + 2) % 10);
		printf("  |  | %d || %d || %d |  | | |\n", (nDisplaySlot1 + 1) % 10, (nDisplaySlot2 + 1) % 10, (nDisplaySlot3 + 1) % 10);
		printf("  |-------------------| | |\n");
		printf("  |  [ %d ][ %d ][ %d ]  | O |\n", nDisplaySlot1, nDisplaySlot2, nDisplaySlot3);
		printf("  |-------------------|   |\n");
		printf("  |  | %d || %d || %d |  |   |\n", (nDisplaySlot1 + 9) % 10, (nDisplaySlot2 + 9) % 10, (nDisplaySlot3 + 9) % 10);
		printf("  |  | %d || %d || %d |  |   |\n", (nDisplaySlot1 + 8) % 10, (nDisplaySlot2 + 8) % 10, (nDisplaySlot3 + 8) % 10);
		printf("  |-------------------|---|\n");

		printf("레버 남은 횟수 : %d\n", nLeverPullCount);
		if ((nDisplaySlot1 == nDisplaySlot2 || nDisplaySlot1 == nDisplaySlot3) || nDisplaySlot2 == nDisplaySlot3)
		{
			if (nDisplaySlot1 == nDisplaySlot2 && nDisplaySlot1 == nDisplaySlot3)
			{
				if (nDisplaySlot1 == 7)
				{
					Score += 1000;
					printf("3개 맞았습니다. 7 7 7!! +1000~~!!\n");
				}
				else
				{
					printf("3개 맞았습니다. +100!!\n");
					Score += 100;
				}
			}
			else
			{
				printf("2개 맞았습니다. +10!\n");
				Score += 10;
			}
		}
		else
		{
			printf("꽝!\n");
			Score -= 1;
		}
		printf("현재 스코어 : %d\n", Score);

		getch();

		if (Score < 1) //게임오버
		{
			break;
		}
	}

	system("cls");

	printf("  |-------------------|---|\n");
	printf("  |  | %d || %d || %d |  | o |\n", (nDisplaySlot1 + 2) % 10, (nDisplaySlot2 + 2) % 10, (nDisplaySlot3 + 2) % 10);
	printf("  |  | %d || %d || %d |  | | |\n", (nDisplaySlot1 + 1) % 10, (nDisplaySlot2 + 1) % 10, (nDisplaySlot3 + 1) % 10);
	printf("  |-------------------| | |\n");
	printf("  |  [ %d ][ %d ][ %d ]  | O |\n", nDisplaySlot1, nDisplaySlot2, nDisplaySlot3);
	printf("  |-------------------|   |\n");
	printf("  |  | %d || %d || %d |  |   |\n", (nDisplaySlot1 + 9) % 10, (nDisplaySlot2 + 9) % 10, (nDisplaySlot3 + 9) % 10);
	printf("  |  | %d || %d || %d |  |   |\n", (nDisplaySlot1 + 8) % 10, (nDisplaySlot2 + 8) % 10, (nDisplaySlot3 + 8) % 10);
	printf("  |-------------------|---|\n");

	printf("레버 남은 횟수 : %d\n", nLeverPullCount);
	printf("현재 스코어 : %d\n", Score);
	if (Score < 1) //게임오버
	{
		printf("게임오버\n");
	}
	getch();
}