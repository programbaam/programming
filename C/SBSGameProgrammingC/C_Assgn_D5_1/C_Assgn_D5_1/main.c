#include <stdio.h>
#include "Max.h"
#include "Min.h"
#include "Sum.h"
#include "FloatSum.h"

void main()
{
	int nA = 400;
	int nB = 300;

	printf("두 개의 매개변수 a = %d, b = %d\n", nA, nB);
	printf("두 개의 매개변수 중 큰 값 : %d\n", Max(nA, nB));
	printf("두 개의 매개변수 중 작은 값 : %d\n", Min(nA, nB));
	printf("두 개의 매개변수를 합한 값 : %d\n", Sum(nA, nB));

	float fA = 3.454f;
	float fB = 145.0561f;

	printf("두 개의 유리수 매개변수 a = %0.4f, b = %0.4f\n", fA, fB);
	printf("두 개의 유리수 매개변수를 합한 값 : %0.4f\n", FloatSum(fA, fB));


}