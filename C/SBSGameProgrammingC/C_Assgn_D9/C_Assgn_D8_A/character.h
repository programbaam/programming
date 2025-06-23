#ifndef CHARACTER_H //���� �����Ƿ� ���� ���� �߻�
#define CHARACTER_H

#define TRUE	1
#define FALSE	0
#define CHARACTERNUMBER	100


typedef int BOOL;

typedef struct {
	int nDamage;	// ���� ���� ����
	int nLife;		//����
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