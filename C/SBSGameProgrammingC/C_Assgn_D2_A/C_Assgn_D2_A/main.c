#include <stdio.h>

void main(void)
{
	int nArray[4] = { 1, 2, 3, 4 };

	//수업과제1 : arrEx2의 초기화 방식을 char, float 자료형으로 선언해서 
	//그에 맞게 값을 대입 한 뒤 그에 맞는 서식 지정자를 이용하여 printf로 출력 해볼것
	char chArray[4] = { 'a', 'b', 'c', 'd' };
	float fArray[4] = { 1.1f, 2.2f, 3.3f, 4.4f };

	printf("%c %c %c %c\n", chArray[0], chArray[1], chArray[2], chArray[3]);
	printf("%0.1f %0.1f %0.1f %0.1f\n", fArray[0], fArray[1], fArray[2], fArray[3]);

	//수업과제2 : int, float형 배열을 char형의 '값'(ex 'a') 으로 집어넣었을때
	//int 와 float 의 서식지정자를 이용하여 printf로 출력 해볼것

	nArray[0] = chArray[0];
	nArray[1] = chArray[1];
	nArray[2] = chArray[2];
	nArray[3] = chArray[3];


	fArray[0] = chArray[0];
	fArray[1] = chArray[1];
	fArray[2] = chArray[2];
	fArray[3] = chArray[3];

	printf("%d %d %d %d\n", nArray[0], nArray[1], nArray[2], nArray[3]);
	printf("%f %f %f %f\n", fArray[0], fArray[1], fArray[2], fArray[3]);

}

