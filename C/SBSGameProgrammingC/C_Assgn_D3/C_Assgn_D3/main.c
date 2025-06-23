#include <stdio.h>
#include <stdlib.h> // rand() �Լ�
#include <conio.h>  // getch() �Լ�
#include <time.h>   // time() �Լ�
#pragma warning ( disable : 4996 )

void main() {
	//1. ���̰��� �����
	float fFirstNum;
	float fSecondNum;
	char chOperator;
	float fResult = 0.0f;

	int bIsArithmeticOperation = 1;

	//- ��Ģ�����ڸ� �̿��ؼ� �ε������� 2���� ���� �Է¹ް� ����� ����Ѵ�.
	//- �Է��Լ��� scanf(), �����ڿ� ���� ������ �Ǵ��ؼ� ������ ����Ѵ�
	//- if���� �̿��� ��
	//- ��: ������ �Է��� �ּ��� :
	printf("������ �Է��� �ּ��� : ");
	scanf("%f %c %f", &fFirstNum, &chOperator, &fSecondNum);

	//�����
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

	//��º�
	if (bIsArithmeticOperation)
	{
		printf("��� ���� %0.4f �Դϴ�.\n", fResult);
	}
	else
	{
		puts("����� �� ���� ���� �����ϴ�.");
	}


	fFirstNum = 0.0f;
	fSecondNum = 0.0f;
	fResult = 0.0f;
	chOperator = '\0';
	bIsArithmeticOperation = 1;
	//2. switch�� �̿��ؼ� 1���� ���� ���α׷��� �ۼ��� ��
	printf("(switch)������ �Է��� �ּ��� : ");
	scanf("%f %c %f", &fFirstNum, &chOperator, &fSecondNum);

	//�����
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

	//��º�
	if (bIsArithmeticOperation)
	{
		printf("��� ���� %0.4f �Դϴ�.\n", fResult);
	}
	else
	{
		puts("����� �� ���� ���� �����ϴ�.");
	}


	//3. 14�� �������� ����Ű�� �ƴ� Ű�� �Է��ϸ� ���α׷��� �ƹ��͵� ��µ��� �ʰ� ���� �ǰ� ������.

	char chInput;
	int  nRandom;

	srand((unsigned)time(NULL));


	printf(">> ����Ű�� ������ ������ �߻��մϴ� ( 0 ~ 7 ) << ");
	chInput = getch();

	if (chInput == '\r')
	{
		puts("ĳ���� ���� �� ����");
	}
	else
	{
		//return; 
		exit(0);
	}

	nRandom = rand() % 8;

	switch (nRandom)
	{
	case 0:	printf("������ 0�Դϴ� \n");
		break;
	case 1:
		printf("������ 1�Դϴ� \n");
		break;
	case 2:
		printf("������ 2�Դϴ� \n");
		break;
	case 3:
		printf("������ 3�Դϴ� \n");
		break;
	case 4:
	case 5:
		printf("������ 4 ~ 5�Դϴ� \n");
		break;
	default:
		printf("������ 6 ~ 7�Դϴ� \n");
	}

}