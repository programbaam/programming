#include <stdio.h>
#include <stdlib.h>
#include "character.h"



void initGame(CHARACTER** arrCharacters,
	int* arrDeadCharacterIndex, GAMESTATUS* gsGameStatus)
{
	//게임 상태초기화
	initGameStatus(gsGameStatus);

	//캐릭터 초기화
	for (int i = 0; i < CHARACTERNUMBER; i++)
	{
		arrCharacters[i] = initCharacter(arrCharacters[i]);
		if (arrCharacters[i] == NULL)
		{
			gsGameStatus->nDeadCharacters++;
			gsGameStatus->nAliveCharacters--;
		}

		//쓰레기 값을 캐릭터 전체 크기로 표현
		//최대 인덱스는 CHARACTERNUMBER - 1 이기 때문에
		//아직 죽은 캐릭터가 없기에 쓰레기 값으로 초기화
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

	//캐릭터 데미지
	for (int i = 0; i < CHARACTERNUMBER; i++)
	{
		//데미지 0 ~ 10
		int nDamage = rand() % 11;

		//takeDamage 함수는 죽을 경우 TRUE 반환
		if (takeDamage(&arrCharacters[i], nDamage))
		{
			//죽은 캐릭터 인덱스를 저장
			arrDeadCharacterIndex[gsGameStatus->nDeadCharacters] = i;

			//이번 턴 죽은 캐릭터 수 증가
			//사망 캐릭터 수 증가
			gsGameStatus->nDeadCharacters++;
			gsGameStatus->nTurnDeadCharacters++;
			gsGameStatus->nAliveCharacters--;
		}

		//데미지가 0일 경우 이번 공격에 공격 받지 않은 캐릭터 증가
		if (nDamage == 0)
			gsGameStatus->nTurnSafeCharacters++;
	}


	//캐릭터 부활
	reviveCharacters(arrCharacters, arrDeadCharacterIndex, gsGameStatus);


}

//메모리 할당 반납
void cleanupGame(CHARACTER** arrCharacters)
{
	//캐릭터 구조체만 메모리 할당하였기에 모든 캐릭터 메모리 반납
	for (int i = 0; i < CHARACTERNUMBER; i++)
	{
		if (arrCharacters[i] != NULL)
		{
			free(arrCharacters[i]);
			arrCharacters[i] = NULL;
		}
	}
}