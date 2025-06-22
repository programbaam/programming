/* Ch02 Exercise 02. (c)
/* 원본 코드 */
/* 첫번째 프로그램 */

//#include <stdio.h>
//
//int Main(void)
//{
//	printf("Hello World!");
//	return 0;
//
//}

// LNK2019 함수에서 참조되는 확인할 수 없는 외부 기호
// LNL1120 확인할 수 없는 외부 참조
// 컴파일 오류

#include <stdio.h>

int main(void)
// 대문자 M -> m으로 수정
{
	printf("Hello World!");
	return 0;

}