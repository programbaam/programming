#ifndef CHARACTER_H //형식 재정의로 인한 문제 발생
#define CHARACTER_H

#define TRUE	1
#define FALSE	0
#define CHARACTERNUMBER	100


typedef int BOOL;

typedef struct {
	int nDamage;	// 공격 받은 정도
	int nLife;		//생명
} CHARACTER;


typedef struct {
	int nTurn;
	int nDeadCharacters;
	int nAliveCharacters;
	int nRevivedCharacters;
	int nTurnDeadCharacters;
	int nTurnSafeCharacters;
} GAMESTATUS;

CHARACTER* initCharacter(CHARACTER* chrCharacter);
void initGameStatus(GAMESTATUS* gsGameStatus);
BOOL takeDamage(CHARACTER** chrCharacter, int nDamage);
void reviveCharacters(CHARACTER** arrCharacters, 
	int* arrDeadCharacterIndex, GAMESTATUS* gsGameStatus);

#endif