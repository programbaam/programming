#include <stdio.h>

void main(void)
{
	int nArray[4] = { 1, 2, 3, 4 };

	//��������1 : arrEx2�� �ʱ�ȭ ����� char, float �ڷ������� �����ؼ� 
	//�׿� �°� ���� ���� �� �� �׿� �´� ���� �����ڸ� �̿��Ͽ� printf�� ��� �غ���
	char chArray[4] = { 'a', 'b', 'c', 'd' };
	float fArray[4] = { 1.1f, 2.2f, 3.3f, 4.4f };

	printf("%c %c %c %c\n", chArray[0], chArray[1], chArray[2], chArray[3]);
	printf("%0.1f %0.1f %0.1f %0.1f\n", fArray[0], fArray[1], fArray[2], fArray[3]);

	//��������2 : int, float�� �迭�� char���� '��'(ex 'a') ���� ����־�����
	//int �� float �� ���������ڸ� �̿��Ͽ� printf�� ��� �غ���

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

