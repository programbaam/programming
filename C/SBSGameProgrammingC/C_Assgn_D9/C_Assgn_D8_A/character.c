#include <stdlib.h>
#include "character.h"

//캐릭터 구조체 초기화
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

//게임상태 초기화
void initGameStatus(GAMESTATUS* gsGameStatus)
{
	gsGameStatus->nTurn = 0;
	gsGameStatus->nDeadCharacters = 0;
	gsGameStatus->nAliveCharacters = CHARACTERNUMBER;
	gsGameStatus->nRevivedCharacters = 0;
	gsGameStatus->nTurnDeadCharacters = 0;
	gsGameStatus->nTurnSafeCharacters = 0;
}

//데미지 받는 함수
BOOL takeDamage(CHARACTER** chrCharacter, int nDamage)
{
	// 이번 턴에 죽었는 지 여부 알기위해 BOOL 반환
	if (*chrCharacter == NULL) // 이미 죽은 경우 false 반환
		return FALSE;

	(*chrCharacter)->nDamage = nDamage;
	(*chrCharacter)->nLife -= nDamage;

	if ((*chrCharacter)->nLife <= 0)
	{
		free(*chrCharacter);
		*chrCharacter = NULL;
		return TRUE; // 죽은 경우 true 반환
	}

	// 안 죽었기에 false 반환
	return FALSE;
}

//캐릭터 부활 함수
void reviveCharacters(CHARACTER** arrCharacters,
	int* arrDeadCharacterIndex, GAMESTATUS* gsGameStatus)
{
	//죽은 캐릭터의 10퍼센트 지정
	gsGameStatus->nRevivedCharacters = gsGameStatus->nDeadCharacters / 10;

	//살려야 할 캐릭터 수가 없다면 리턴
	if (gsGameStatus->nRevivedCharacters == 0) return;

	//부활할 캐릭터 수 만큼 반복
	int iRevieIterator = gsGameStatus->nRevivedCharacters;
	for (int i = 0; i < iRevieIterator; i++)
	{
		//iRevive(죽은 캐릭터 인덱스 저장한 배열의 인덱스) = 죽은 캐릭터의 수
		//모든 캐릭터가 죽었다면 최대수 - 1 한다.
		int iReviveIndex = gsGameStatus->nDeadCharacters;
		if (iReviveIndex == CHARACTERNUMBER)
			iReviveIndex = CHARACTERNUMBER - 1;


		//쓰레기 값이 들어있다면 이미 부활시킨 인덱스이기에 다시 랜덤을 돌린다.
		while (arrDeadCharacterIndex[iReviveIndex] == CHARACTERNUMBER)
		{
			iReviveIndex = rand() % gsGameStatus->nDeadCharacters;
		}

		//해당 인덱스 캐릭터 부활시키고 죽은 캐릭터 인덱스 배열의 쓰레기 값 저장
		arrCharacters[arrDeadCharacterIndex[iReviveIndex]] = initCharacter(arrCharacters[arrDeadCharacterIndex[iReviveIndex]]);
		arrDeadCharacterIndex[iReviveIndex] = CHARACTERNUMBER;

		//게임상태 부활한 캐릭터 수, 살아있는 캐릭터 수 증가
		gsGameStatus->nAliveCharacters++;
	}

	// 죽은 캐릭터 인덱스 배열 - 쓰레기 값을 지우기
	// 앞에 있는 쓰레기 값을 검사 후 가장 뒤에 있는 값으로 채운다.
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

			// 앞 인덱스 쓰레기 값을 가장 뒤에 있는 값으로 변경
			arrDeadCharacterIndex[iStart] = arrDeadCharacterIndex[iEndIndex];
			arrDeadCharacterIndex[iEndIndex] = CHARACTERNUMBER;
			iEndIndex--;

		}
	}

	//죽은 캐릭터 수에서 부활한 캐릭터 수를 뺀다.
	gsGameStatus->nDeadCharacters -= gsGameStatus->nRevivedCharacters;
}