#include <stdio.h>
#include "Display.h"
#pragma warning ( disable : 4996 )

int nDesireNumber;

void main()
{
	printf("���ϴ� ���� ���� �Է� : ");
	scanf("%d", &nDesireNumber);

	printf("%d���� ������ ���� �� : %d", nDesireNumber, Display());

}