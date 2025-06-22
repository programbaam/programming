/* 첫 번째 프로그램 */
#include <stdio.h>

int main(void)
{
	print("Hello World!\n");
	// printf이여야 함.
	// C4013 경고 print 정의되지 않음.
	// LNK2019 확인할 수 없는 외부 기호
	// LNK1120 확인할 수 없는 외부 참조 
	// 라이브러리를 연결하는 링커에서 함수를 찾을 수 없다
	// unresolved external symbol 링커가 해결할 수 없는 외부 기호 이름

	return 0;
}