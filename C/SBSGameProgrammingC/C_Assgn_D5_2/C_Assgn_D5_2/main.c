#include <stdio.h>
#include "Display.h"
#pragma warning ( disable : 4996 )

int nDesireNumber;

void main()
{
	printf("원하는 단의 숫자 입력 : ");
	scanf("%d", &nDesireNumber);

	printf("%d단의 마지막 전의 값 : %d", nDesireNumber, Display());

}