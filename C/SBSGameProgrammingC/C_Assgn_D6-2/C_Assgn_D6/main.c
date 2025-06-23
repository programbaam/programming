#include <stdio.h>
#include "Strlen.h"
#include "Strcpy.h"
#include "Strcat.h"
#include "Strrot.h"

void main()
{
	//문자열 길이
	char* sStrlen1 = "123456";

	printf("%s라는 문자열의 길이는 : %d\n", 
		sStrlen1, __strlen(sStrlen1));

	//문자열 복사
	char sStrcpy1[6] = "ABCDE";
	char sStrcpy2[3] = "DE";
	printf("복사 전 사이즈 %d, %d\n", sizeof(sStrcpy1), sizeof(sStrcpy2));
	printf("복사 전 문자열 1 : %s, 문자열 2 : %s\n", 
		sStrcpy1, sStrcpy2);

	__strcpy(sStrcpy1, sStrcpy2);

	printf("복사 후 문자열 1 : %s, 문자열 2 : %s\n",
		sStrcpy1, sStrcpy2);

	//문자열 결합
	char sStrcat1[10] = "12345";
	char sStrcat2[5] = "6789";

	printf("결합 전 문자열 1 : %s, 문자열 2 : %s\n", 
		sStrcat1, sStrcat2);

	__strcat(sStrcat1, sStrcat2);

	printf("결합 후 문자열 1 : %s, 문자열 2 : %s\n",
		sStrcat1, sStrcat2);

	//문자열 회전 함수
	char sStrrot[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	printf("문자열 회전 : %s\n", sStrrot);

	for (int i = 0; i < __strlen(sStrrot); i++)
	{
		__strrot(sStrrot);
		printf("%s\n", sStrrot);
	}
}