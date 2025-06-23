#include <stdio.h>
#pragma warning ( disable : 4996 )

void main()
{
	// 수업과제1
	char cFirst;
	int nSecond;
	short shThird;
	long lFourth;
	float fFifth;
	double dSixth;
	unsigned char ucSeventh;
	unsigned int uiEighth;
	unsigned short ushNinth;
	unsigned long ulTenth;

	scanf("%c %d %hd %ld %f ", &cFirst, &nSecond, &shThird, &lFourth, &fFifth);
	scanf("%lf %c %d %hd %d", &dSixth, &ucSeventh, &uiEighth, &ushNinth, &ulTenth);

	// 수업과제2

	printf("%10d %10d %10d %10d %10d\n", cFirst, nSecond, shThird, lFourth, fFifth);
	printf("%10d %10d %10d %10d %10d\n", dSixth, ucSeventh, uiEighth, ushNinth, ulTenth);

	printf("%-10x %-10x %-10x %-10x %-10x\n", cFirst, nSecond, shThird, lFourth, fFifth);
	printf("%-10x %-10x %-10x %-10x %-10x\n", dSixth, ucSeventh, uiEighth, ushNinth, ulTenth);

	return;
}