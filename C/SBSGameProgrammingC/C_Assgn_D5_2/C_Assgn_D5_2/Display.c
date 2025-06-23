#include <stdio.h>
#include "Display.h"

extern int nDesireNumber;

int Display()
{
	int i;
	for (i = 0; i < 9; i++)
		printf("%d X %d = %d\n", nDesireNumber, i + 1, nDesireNumber * (i + 1));

	return nDesireNumber * (i-1);
}