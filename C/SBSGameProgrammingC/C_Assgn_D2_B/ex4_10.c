//수업과제1 : opEx4_10의 과정을 순서대로 나열. 주석을 사용하여 결과를 증명한다.  

#include <stdio.h> // 표준입출력(stdio)함수의 헤더파일(.h)을 컴파일에 포함시킨다

void main() //메인 함수 : 프로그램 최초의 진입점 (Entry Point)
{ // 항상 중괄호의 시작과 끝으로 표시
	int a, b, c, e, f; //int 데이터형 a, b, c, e, f라는 변수들을 선언

	a = 0; //int형 변수 a의 데이터 값 0으로 정의
	b = 5; //int형 변수 b의 데이터 값 5으로 정의
	c = 10; ////int형 변수 c의 데이터 값 10으로 정의

	//int형 변수 e의 정의 조건연산자
	// c가 b보다 크다면 e의 값은 수식 b * ++c - 10 * 2
	// c가 b보다 크지 않다면 e의 값은 수식 c-- * b + 10 * 2
	// 
	// c는 10이고 b는 5이기 때문에 c는 b보다 크기에
	// e의 값은 b * ++c -10 * 2 실행 - e = 5 * (c=1+10) - 10 * 2 
	// 
	// 증감연산자가 우선 c의 값이 11이 되고 * 연산이 다음 우선이기에 e = 5 * 11 - 10 * 2 = 55 - 20 = 35
	e = c > b ? b * ++c - 10 * 2 : c-- * b + 10 * 2;
	// a = 0, b = 5, c = 11, e = 35

	//f의 정의
	// 10과 c 가 같다면 f = b * ++c - 10 * 2
	// 10과 c 가 같지 않다면 f = c-- * b + 10 * 2
	// 
	// 지금 c의 값은 11로 10과 c는 같지 않기에
	// f = c-- * b + 10 * 2 실행
	// c-- 후위 증감 연산자기에 c 값이 대입 된 후에 감소한다.
	// f = 11 * 5 + 10 * 2 = 55 + 20 = 75
	f = 10 == c ? b * ++c - 10 * 2 : c-- * b + 10 * 2;
	// a = 0, b = 5, c = 10, e = 35, f = 75
	printf("e= %d\n", e); // e= 35 출력
	printf("f= %d\n", f); // f= 75 출력


	//수업과제2 : 정수형으로 2개의 배열을 선언, 배열의 크기는 4 ( ex: int nOP1[4], nOP2[4]; )
	//부동형으로 2개의 배열을 선언, 배열의 크기는 4 ( ex: float fOP1[4], fOP2[4]; )
	//각 배열의 요소 값을 전부 입력 받는다. (scanf)
	//연산결과는 각 데이터형에 맞는 변수에 저장한다. 

	int nOP1[4], nOP2[4];
	float fOP1[4], fOP2[4];

	scanf("%d %d %d %d", &nOP1[0], &nOP1[1], &nOP1[2], &nOP1[3]);
	scanf("%d %d %d %d", &nOP2[0], &nOP2[1], &nOP2[2], &nOP2[3]);
	scanf("%f %f %f %f", &fOP1[0], &fOP1[1], &fOP1[2], &fOP1[3]);
	scanf("%f %f %f %f", &fOP2[0], &fOP2[1], &fOP2[2], &fOP2[3]);

	// # 저장 방법은 두가지
	//첫번째. 새로운 배열을 만들어서 결과값을 집어넣는다.
	//두번째. 기존에 선언된 배열에 결과값을 집어넣는다

	int nResult[4];

	nResult[0] = nOP1[0] + nOP2[0];
	nOP2[0] = (int)fOP1[0] + (int)fOP2[0];
	nResult[1] = nOP1[1] - nOP2[1];
	nOP2[1] = (int)fOP1[1] - (int)fOP2[1];
	nResult[2] = nOP1[2] * nOP2[2];
	nOP2[2] = (int)fOP1[2] * (int)fOP2[2];
	nResult[3] = (int)(nOP1[3] / nOP2[3]);
	nOP2[3] = (int)((int)fOP1[3] / (int)fOP2[3]);

	printf("nResult 행렬 값\n");
	printf("%d %d %d %d\n", nResult[0], nResult[1], nResult[2], nResult[3]);
	printf("nOP2 행렬 값\n");
	printf("%d %d %d %d\n", nOP2[0], nOP2[1], nOP2[2], nOP2[3]);

	return;
}
