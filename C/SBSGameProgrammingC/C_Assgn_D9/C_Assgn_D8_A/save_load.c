#include <stdio.h>
#include <stdlib.h>
#include "character.h"
#include "sorting_functions.h"

#pragma warning (disable : 4996)

#define SAVE_FILE_NAME "charinfo.bin"

void saveGame(CHARACTER** arrCharacters,
	int* arrDeadCharacterIndex, GAMESTATUS* gsGameStatus)
{
	FILE* pFileSaveData;
	pFileSaveData = fopen(SAVE_FILE_NAME, "wb");

	//게임상태, 죽은 캐릭터 인덱스 배열 저장
	fwrite(gsGameStatus, sizeof(GAMESTATUS), 1, pFileSaveData);
	fwrite(arrDeadCharacterIndex, sizeof(int) * CHARACTERNUMBER, 1, pFileSaveData);

	//죽은 캐릭터에 해당하는 인덱스는 널을 가르키기에 저장할 때 생략
	int iArrDeadChrIndex = 0;
	//죽은 캐릭터들의 인덱스 배열은 랜덤하게 들어가 있어 정렬을 한번 해준다.
	quickSortIntArr(arrDeadCharacterIndex, 0, gsGameStatus->nDeadCharacters - 1);

	//죽지 않은 캐릭터들을 저장
	for (int i = 0; i < CHARACTERNUMBER; i++)
	{
		if (i == arrDeadCharacterIndex[iArrDeadChrIndex])
		{
			iArrDeadChrIndex++;
		}
		else
		{
			fwrite(arrCharacters[i], sizeof(CHARACTER), 1, pFileSaveData);
		}
	}

	fclose(pFileSaveData);
}

BOOL loadGame(CHARACTER** arrCharacters,
	int* arrDeadCharacterIndex, GAMESTATUS* gsGameStatus)
{
	FILE* pFileLoadData = fopen(SAVE_FILE_NAME, "rb");
	
	if (pFileLoadData == NULL)
		return FALSE;

	//게임상태, 죽은 캐릭터 인덱스 배열 불러오기
	fread(gsGameStatus, sizeof(GAMESTATUS), 1, pFileLoadData);
	fread(arrDeadCharacterIndex, sizeof(int) * CHARACTERNUMBER, 1, pFileLoadData);

	//죽은 캐릭터에 해당하는 인덱스는 널을 가르키기에 불러올 때 생략
	int iArrDeadChrIndex = 0;
	//죽은 캐릭터들의 인덱스 배열은 랜덤하게 들어가 있어 정렬을 한번 해준다.
	quickSortIntArr(arrDeadCharacterIndex, 0, gsGameStatus->nDeadCharacters - 1);
	
	// 죽지 않은 캐릭터들을 불러오기
	// 덮어 씌우기 전 기존 캐릭터에 할당된 메모리 반납 후 메모리 할당한다.
	for (int i = 0; i < CHARACTERNUMBER; i++)
	{
		// 죽은 캐릭터는 널을 가르킴
		if (i == arrDeadCharacterIndex[iArrDeadChrIndex])
		{
			iArrDeadChrIndex++;
			free(arrCharacters[i]);
			arrCharacters[i] = NULL;
		}
		else
		{
			if (arrCharacters[i] != NULL)
			{
				free(arrCharacters[i]);
				arrCharacters[i] = NULL;
			}
			
			arrCharacters[i] = (CHARACTER*)malloc(sizeof(CHARACTER));
			if (arrCharacters[i] != NULL)
				fread(arrCharacters[i], sizeof(CHARACTER), 1, pFileLoadData);
		}
	}

	fclose(pFileLoadData);

	return TRUE;
}