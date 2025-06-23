#include <stdio.h>
#include <stdlib.h> // rand() 함수
#include <conio.h>  // getch() 함수
#include <time.h>   // time() 함수
#pragma warning ( disable : 4996 )

void main() {
	//1. 간이계산기 만들기
	float fFirstNum;
	float fSecondNum;
	char chOperator;
	float fResult = 0.0f;

	int bIsArithmeticOperation = 1;

	//- 사칙연산자를 이용해서 부동형으로 2개의 수를 입력받고 결과를 출력한다.
	//- 입력함수는 scanf(), 연산자에 따라 조건을 판단해서 계산식을 출력한다
	//- if문을 이용할 것
	//- 예: 계산식을 입력해 주세요 :
	printf("계산식을 입력해 주세요 : ");
	scanf("%f %c %f", &fFirstNum, &chOperator, &fSecondNum);

	//연산부
	if (chOperator == '+')
	{
		fResult = fFirstNum + fSecondNum;
	}
	else if (chOperator == '-')
	{
		fResult = fFirstNum - fSecondNum;
	}
	else if (chOperator == '*')
	{
		fResult = fFirstNum * fSecondNum;
	}
	else if (chOperator == '/')
	{
		fResult = fFirstNum / fSecondNum;
	}
	else
	{
		bIsArithmeticOperation = 0;
	}

	//출력부
	if (bIsArithmeticOperation)
	{
		printf("결과 값은 %0.4f 입니다.\n", fResult);
	}
	else
	{
		puts("계산할 수 없는 값이 들어갔습니다.");
	}


	fFirstNum = 0.0f;
	fSecondNum = 0.0f;
	fResult = 0.0f;
	chOperator = '\0';
	bIsArithmeticOperation = 1;
	//2. switch를 이용해서 1번과 같은 프로그램을 작성할 것
	printf("(switch)계산식을 입력해 주세요 : ");
	scanf("%f %c %f", &fFirstNum, &chOperator, &fSecondNum);

	//연산부
	switch (chOperator)
	{
	case '+':
		fResult = fFirstNum + fSecondNum;
		break;
	case '-':
		fResult = fFirstNum - fSecondNum;
		break;
	case '*':
		fResult = fFirstNum * fSecondNum;
		break;
	case '/':
		fResult = fFirstNum / fSecondNum;
		break;
	default:
		bIsArithmeticOperation = 0;
	}

	//출력부
	if (bIsArithmeticOperation)
	{
		printf("결과 값은 %0.4f 입니다.\n", fResult);
	}
	else
	{
		puts("계산할 수 없는 값이 들어갔습니다.");
	}


	//3. 14번 예제에서 리턴키가 아닌 키를 입력하면 프로그램이 아무것도 출력되지 않고 종료 되게 만들어본다.

	char chInput;
	int  nRandom;

	srand((unsigned)time(NULL));


	printf(">> 리턴키를 누르면 난수가 발생합니다 ( 0 ~ 7 ) << ");
	chInput = getch();

	if (chInput == '\r')
	{
		puts("캐리지 리턴 값 받음");
	}
	else
	{
		//return; 
		exit(0);
	}

	nRandom = rand() % 8;

	switch (nRandom)
	{
	case 0:	printf("난수는 0입니다 \n");
		break;
	case 1:
		printf("난수는 1입니다 \n");
		break;
	case 2:
		printf("난수는 2입니다 \n");
		break;
	case 3:
		printf("난수는 3입니다 \n");
		break;
	case 4:
	case 5:
		printf("난수는 4 ~ 5입니다 \n");
		break;
	default:
		printf("난수는 6 ~ 7입니다 \n");
	}

}