#include <stdio.h>
#include "Max.h"
#include "Min.h"
#include "Sum.h"
#include "FloatSum.h"

void main()
{
	int nA = 400;
	int nB = 300;

	printf("�� ���� �Ű����� a = %d, b = %d\n", nA, nB);
	printf("�� ���� �Ű����� �� ū �� : %d\n", Max(nA, nB));
	printf("�� ���� �Ű����� �� ���� �� : %d\n", Min(nA, nB));
	printf("�� ���� �Ű������� ���� �� : %d\n", Sum(nA, nB));

	float fA = 3.454f;
	float fB = 145.0561f;

	printf("�� ���� ������ �Ű����� a = %0.4f, b = %0.4f\n", fA, fB);
	printf("�� ���� ������ �Ű������� ���� �� : %0.4f\n", FloatSum(fA, fB));


}