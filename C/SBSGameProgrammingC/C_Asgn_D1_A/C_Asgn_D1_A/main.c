#include <stdio.h>

void main()
{
	// 수업과제1
	char cFirst = 'A';
	int nSecond = -2;
	short shThird = -3;
	long lFourth = -4;
	float fFifth = -5.0f;
	double dSixth = -6.0;
	unsigned char ucSeventh = '\n';
	unsigned int uiEighth = 8;
	unsigned short ushNinth = 9;	
	unsigned long ulTenth = 10;

	// 수업과제2 디버깅 F5 - F10

	// 수업과제 3
	cFirst = -50;
	fFifth = 5.0f;
	dSixth = 0.006;
	ucSeventh = cFirst;
	uiEighth = nSecond;
	ushNinth = shThird;
	ulTenth = lFourth;
	nSecond = 2;
	shThird = 3;
	lFourth = 4;

	// 수업과제4

	unsigned char ucFirst='G';
	unsigned char ucSecond = 'A';
	unsigned char ucThird = 'M';
	unsigned char ucFourth = 'E';

	printf("%c = %d, ", ucFirst, ucFirst);
	printf("%c = %d, ", ucSecond, ucSecond);
	printf("%c = %d, ", ucThird, ucThird);
	printf("%c = %d", ucFourth, ucFourth);

	return;
}