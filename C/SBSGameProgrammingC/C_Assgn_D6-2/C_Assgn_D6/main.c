#include <stdio.h>
#include "Strlen.h"
#include "Strcpy.h"
#include "Strcat.h"
#include "Strrot.h"

void main()
{
	//���ڿ� ����
	char* sStrlen1 = "123456";

	printf("%s��� ���ڿ��� ���̴� : %d\n", 
		sStrlen1, __strlen(sStrlen1));

	//���ڿ� ����
	char sStrcpy1[6] = "ABCDE";
	char sStrcpy2[3] = "DE";
	printf("���� �� ������ %d, %d\n", sizeof(sStrcpy1), sizeof(sStrcpy2));
	printf("���� �� ���ڿ� 1 : %s, ���ڿ� 2 : %s\n", 
		sStrcpy1, sStrcpy2);

	__strcpy(sStrcpy1, sStrcpy2);

	printf("���� �� ���ڿ� 1 : %s, ���ڿ� 2 : %s\n",
		sStrcpy1, sStrcpy2);

	//���ڿ� ����
	char sStrcat1[10] = "12345";
	char sStrcat2[5] = "6789";

	printf("���� �� ���ڿ� 1 : %s, ���ڿ� 2 : %s\n", 
		sStrcat1, sStrcat2);

	__strcat(sStrcat1, sStrcat2);

	printf("���� �� ���ڿ� 1 : %s, ���ڿ� 2 : %s\n",
		sStrcat1, sStrcat2);

	//���ڿ� ȸ�� �Լ�
	char sStrrot[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	printf("���ڿ� ȸ�� : %s\n", sStrrot);

	for (int i = 0; i < __strlen(sStrrot); i++)
	{
		__strrot(sStrrot);
		printf("%s\n", sStrrot);
	}
}