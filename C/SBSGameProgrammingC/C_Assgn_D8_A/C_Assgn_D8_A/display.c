#include <stdio.h>
#include <math.h> //ceilf 올림
#include "display.h"
#include "character.h"

void display(CHARACTER* arrCharacters, GAMESTATUS* gsGameStatus)
{
	int iRow;
	int iColumn;

	iRow = (int)ceilf((float)CHARACTERNUMBER / 5);
	iColumn = (int)ceilf((float)CHARACTERNUMBER / iRow);


	system("cls");

	printf("Turn : %d\n", gsGameStatus->nTurn);

	//캐릭터 출력
	for (int i = 0; i < iRow; i++)
	{
		for (int j = 0; j < iColumn; j++)
		{
			//생존 캐릭터 출력
			if (arrCharacters[i + j * iRow].bIsLive)
			{
				printf("[%d] Hit:[%d] Hp:[%d]\t", i + j * iRow, arrCharacters[i + j * iRow].nDamage,
					arrCharacters[i + j * iRow].nLife);
			}
			else
			{
				//죽은 캐릭터 출력
				printf("\033[0;31m[%d] Hit:[X] Hp:[♡]\033[0m\t", i + j * iRow);
			}
		}
		printf("\n");
	}

	printf("생존 캐릭터 : %d명\n", gsGameStatus->nAliveCharacters);
	printf("사망 캐릭터 : %d명\n", gsGameStatus->nDeadCharacters);
	printf("부활 캐릭터 : %d명\n", gsGameStatus->nRevivedCharacters);
	printf("이번 공격으로 죽은 캐릭터 : %d명\n", gsGameStatus->nTurnDeadCharacters);
	printf("이번 공격에 공격 받지 않은 캐릭터 : %d명\n", gsGameStatus->nTurnSafeCharacters);

	printf("Enter를 누르면 계속 진행됩니다.\n");

	//이 기능 아직 작동하지 않습니다.
	printf("저장하시려면 s키를 눌러주세요.\n");
	
}