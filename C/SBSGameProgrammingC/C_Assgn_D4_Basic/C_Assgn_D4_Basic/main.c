#include <stdio.h>
#pragma warning ( disable : 4996 )

void main()
{
	srand((unsigned)time(NULL));
	//1. ������

	int nMenuSelection = 0;
	int nDesireNumber = 0;

	//- �޴��� ���
	//1. ������ ��� ��� ( ���η� 3�ܾ� , ��: 2�� 3�� 4�� )
	//     printf("%d x %d = %d",  ����1, ����2, ����3); <- �̷������� printf�� �ѹ��� ����ؼ� ����ؾ��Ѵ�.
	//2. ���ϴ� �������� �Է��ؼ� ��� ( ��: 7�� )
	//3. ����� �ٽ� �޴���� ( �������� )
	//  ex) ���ϴ� �޴��� �Է��ϼ��� 
	//       1. ������ ��� ��� 2. ���ϴ� ��������� 3. ���� :     
	do {
		printf("���ϴ� �޴��� �Է��ϼ���.\n");
		printf("1. ������ ��� ��� 2. ���ϴ� ������ ��� 3. ���� : ");

		scanf("%d", &nMenuSelection);


		if (nMenuSelection == 1) //������ ��� ���
		{
			for (int nSet = 1; nSet < 4; nSet++) //3�ܾ� ���еǴ� ��Ʈ ���
			{
				for (int nColumn = 1; nColumn < 10; nColumn++) //�������� ���ڿ� ����
				{
					for (int nRow = 1; nRow < 4; nRow++) //���η� 3�ܾ� ���
					{
						if ((nRow + (nSet - 1) * 3 + 1) == 10)
							continue;
						printf(" %2d x %2d = %2d ", nRow + (nSet - 1) * 3 + 1 , nColumn, (nRow + (nSet - 1) * 3 + 1) * nColumn);
					}
					printf("\n");
				}
				printf("\n");
			}

		}
		else if (nMenuSelection == 2) //���ϴ� ������ ���
		{
			printf("���ϴ� �������� �Է� : ");
			scanf("%d", &nDesireNumber);

			for (int nColumn = 1; nColumn < 10; nColumn++) //�������� ���ڿ� ����
			{
				printf(" %2d x %2d = %2d\n", nDesireNumber, nColumn, nDesireNumber * nColumn);
			}

		}


	} while (nMenuSelection != 3);

	//exit(0);


	//2. ���� ���߱� ���Ӹ����
	//   - 1~10 ������ ������ ���ߴ� ����
	//   - �Է��� ���� �������� �۰ų� ū ��� ��Ʈ�� �˷��ش�
	//   - ��: ������ 3
	//         �Է��� ���� 5
	//         5���� �۽��ϴ�

	int nRandomNumber;
	int nGuessNumber;
	int nQuizCount = 0;
	int nQuizScore = 0;


	while (nQuizCount < 3) //   - �õ� Ƚ���� 3ȸ, 3ȸ�� ������ ���ϸ� ����
	{
		if (nQuizCount == 0)
		{
			nRandomNumber = rand() % 10 + 1;
		}

		printf("(���� ��ȸ : %d) �Է��� ���� ", 3-nQuizCount);

		scanf("%d", &nGuessNumber);

		if (nRandomNumber == nGuessNumber)
		{
			nQuizCount = 0; //   - ��ȸ Ƚ���� ������ ���� ��� �õ� Ƚ���� �ʱ�ȭ �ȴ�.
			nQuizScore += 10; //  - ���� ������ �ξ� ���⶧���� 10���� ����
			printf("����! ���� ���ھ� : %d\n", nQuizScore);
			continue;
		}
		else if (nRandomNumber == nGuessNumber - 1 || nRandomNumber == nGuessNumber + 1)
		{
			//   - ���� ��Ʈ�� ���� �� ���� ��Ʈ�� ����.
			//   - ��: ������ 1
			//         �Է��� ���� 2
		}
		else if (nRandomNumber > nGuessNumber)
		{
			printf("%d���� Ů�ϴ�.\n", nGuessNumber);
		}
		else if (nRandomNumber < nGuessNumber) 
		{
			printf("%d���� �۽��ϴ�.\n", nGuessNumber);
		}

		nQuizCount++;

	}
}