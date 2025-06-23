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

	//���ӻ���, ���� ĳ���� �ε��� �迭 ����
	fwrite(gsGameStatus, sizeof(GAMESTATUS), 1, pFileSaveData);
	fwrite(arrDeadCharacterIndex, sizeof(int) * CHARACTERNUMBER, 1, pFileSaveData);

	//���� ĳ���Ϳ� �ش��ϴ� �ε����� ���� ����Ű�⿡ ������ �� ����
	int iArrDeadChrIndex = 0;
	//���� ĳ���͵��� �ε��� �迭�� �����ϰ� �� �־� ������ �ѹ� ���ش�.
	quickSortIntArr(arrDeadCharacterIndex, 0, gsGameStatus->nDeadCharacters - 1);

	//���� ���� ĳ���͵��� ����
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

	//���ӻ���, ���� ĳ���� �ε��� �迭 �ҷ�����
	fread(gsGameStatus, sizeof(GAMESTATUS), 1, pFileLoadData);
	fread(arrDeadCharacterIndex, sizeof(int) * CHARACTERNUMBER, 1, pFileLoadData);

	//���� ĳ���Ϳ� �ش��ϴ� �ε����� ���� ����Ű�⿡ �ҷ��� �� ����
	int iArrDeadChrIndex = 0;
	//���� ĳ���͵��� �ε��� �迭�� �����ϰ� �� �־� ������ �ѹ� ���ش�.
	quickSortIntArr(arrDeadCharacterIndex, 0, gsGameStatus->nDeadCharacters - 1);
	
	// ���� ���� ĳ���͵��� �ҷ�����
	// ���� ����� �� ���� ĳ���Ϳ� �Ҵ�� �޸� �ݳ� �� �޸� �Ҵ��Ѵ�.
	for (int i = 0; i < CHARACTERNUMBER; i++)
	{
		// ���� ĳ���ʹ� ���� ����Ŵ
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