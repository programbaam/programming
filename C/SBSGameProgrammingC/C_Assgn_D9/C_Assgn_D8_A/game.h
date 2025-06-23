#pragma once
#include "character.h"

void initGame(CHARACTER** arrCharacters,
	int* arrDeadCharacterIndex, GAMESTATUS* gsGameStatus);

void updateTurnStatus(CHARACTER** arrCharacters,
	int* arrDeadCharacterIndex, GAMESTATUS* gsGameStatus);

void cleanupGame(CHARACTER** arrCharacters);