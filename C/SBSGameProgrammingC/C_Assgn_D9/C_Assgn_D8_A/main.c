#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // 헤더 파일
#include <time.h>
#include "character.h"
#include "game.h"
#include "save_load.h"
#include "display.h"

#pragma warning (disable : 4996)


void main()
{
	srand((unsigned int)time(NULL));

	// 캐릭터 구조체 배열
	// 죽은 캐릭터의 인덱스를 저장하는 배열
	// 게임에서 캐릭터들의 상황을 저장하는 구조체
	CHARACTER* arrCharacters[CHARACTERNUMBER];
	int arrDeadCharacterIndex[CHARACTERNUMBER];
	GAMESTATUS gsGameStatus;
	char nMenuSelection = '\0';

	//캐릭터 포인터 배열 널로 초기화
	for (int i = 0; i < CHARACTERNUMBER; i++)
	{
		arrCharacters[i] = NULL;
	}
	
	
	while (1)
	{
		if (nMenuSelection == 's') //세이브 메뉴 창
		{
			while (!(nMenuSelection == '1' || nMenuSelection == '2' || 
				nMenuSelection == '3' || nMenuSelection == '4')) // 1, 2, 3 - 게임진행, 4 초기 메뉴창
			{
				saveMenuDisplay();
				nMenuSelection = getch();
				switch (nMenuSelection)
				{
				case '1': //하던 게임으로 돌아감
					break;
				case '2': //게임 저장하고 하던 게임으로 돌아감
					saveGame(arrCharacters, arrDeadCharacterIndex, &gsGameStatus);
					break;
				case '3': // 게임 불러오기
					if (loadGame(arrCharacters, arrDeadCharacterIndex, &gsGameStatus))
						break;
					else
					{
						printf("로드 실패!\n");
						getch();
						nMenuSelection = 's';
						continue;
					}
				case '4': // 초기 메뉴창
					break;
				case '5': // 게임 종료
					cleanupGame(arrCharacters); // 할당된 메모리 반납
					return;
				default: // 없는 값 입력시 메뉴창 다시 띄움
					continue;
				}
			}
			if (nMenuSelection == '4') continue; //초기 메뉴창
		}
		else //초기 메뉴 창 
		{
			while (!(nMenuSelection == '1' || nMenuSelection == '2')) // 1, 2 - 게임 진행
			{
				menuDisplay();
				nMenuSelection = getch();
				switch (nMenuSelection)
				{
				case '1': // 게임 새로 시작하기
					initGame(arrCharacters, arrDeadCharacterIndex, &gsGameStatus);
					break;
				case '2': // 게임 불러오기
					if (loadGame(arrCharacters, arrDeadCharacterIndex, &gsGameStatus))
						break;
					else
					{
						printf("로드 실패!\n");
						getch();
						nMenuSelection = '4';
						continue;
					}
				case '3': // 게임 종료
					cleanupGame(arrCharacters); //할당된 메모리 반납
					return;
				default: // 없는 값 입력시 메뉴창 다시 띄움
					continue;
				}
			}
		}
		
		do // 새 게임, 로드, 게임 재개하고 첫 게임 창 실행
		{
			display(arrCharacters, &gsGameStatus);
			nMenuSelection = getch();
		} while (!(nMenuSelection == '\r' || nMenuSelection == 's')); // 저장이나 턴 넘김 안하면 다시 창 띄움

		while (nMenuSelection != 's')  // 저장을 해야 빠져나감
		{
			if(nMenuSelection == '\r') // 턴 넘김 키(엔터키)를 입력해야 턴이 넘어감
				updateTurnStatus(arrCharacters, arrDeadCharacterIndex, &gsGameStatus);
			display(arrCharacters, &gsGameStatus);
			nMenuSelection = getch();
		}
	}

}

