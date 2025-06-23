#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

#include "CrossMemCpy.h"
#include "RandMem.h"

void main()
{
	srand((unsigned int)time(NULL));

	unsigned char* (*fnStrMem)();

	char sCrossmemcpy1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char sCrossmemcpy2[] = "ZXYWVUTSRQPONMLKJIHGFEDCBA";
	char* sCrossmemcpy3 = '\0';

	fnStrMem = __crossmemcpy;

	sCrossmemcpy3 = fnStrMem(sCrossmemcpy2, sCrossmemcpy1, 40);

	printf("%s\n", sCrossmemcpy1);
	printf("%s\n", sCrossmemcpy2);
	printf("%s\n", sCrossmemcpy3);

	free(sCrossmemcpy3);

	char sCrossmemcpy4[] = "ABCD";
	char sCrossmemcpy5[] = "EFGHIJK";
	char* sCrossmemcpy6 = '\0';

	sCrossmemcpy6 = fnStrMem(sCrossmemcpy5, sCrossmemcpy4, 40);

	printf("%s\n", sCrossmemcpy4);
	printf("%s\n", sCrossmemcpy5);
	printf("%s\n", sCrossmemcpy6);

	free(sCrossmemcpy6);


	fnStrMem = __randmem;



	free(fnStrMem(14));

}


