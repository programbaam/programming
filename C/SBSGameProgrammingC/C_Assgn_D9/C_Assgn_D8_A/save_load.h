#ifndef SAVE_LOAD_H 
#define SAVE_LOAD_H 

#include "character.h"

#define SAVE_FILE_NAME "charinfo.bin"

void saveGame(CHARACTER** arrCharacters,
	int* arrDeadCharacterIndex, GAMESTATUS* gsGameStatus);

BOOL loadGame(CHARACTER** arrCharacters,
	int* arrDeadCharacterIndex, GAMESTATUS* gsGameStatus);



#endif