#include <stdio.h>
#pragma warning ( disable : 4996 )

void main()
{
	srand((unsigned)time(NULL));
	//1. 구구단

	int nMenuSelection = 0;
	int nDesireNumber = 0;

	//- 메뉴가 출력
	//1. 구구단 모두 출력 ( 가로로 3단씩 , 예: 2단 3단 4단 )
	//     printf("%d x %d = %d",  변수1, 변수2, 변수3); <- 이런식으로 printf를 한번만 사용해서 출력해야한다.
	//2. 원하는 구구단을 입력해서 출력 ( 예: 7단 )
	//3. 출력후 다시 메뉴출력 ( 루프구현 )
	//  ex) 원하는 메뉴를 입력하세요 
	//       1. 구구단 모두 출력 2. 원하는 구구단출력 3. 종료 :     
	do {
		printf("원하는 메뉴를 입력하세요.\n");
		printf("1. 구구단 모두 출력 2. 원하는 구구단 출력 3. 종료 : ");

		scanf("%d", &nMenuSelection);


		if (nMenuSelection == 1) //구구단 모두 출력
		{
			for (int nSet = 1; nSet < 4; nSet++) //3단씩 구분되는 세트 담당
			{
				for (int nColumn = 1; nColumn < 10; nColumn++) //곱해지는 숫자와 행담당
				{
					for (int nRow = 1; nRow < 4; nRow++) //가로로 3단씩 출력
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
		else if (nMenuSelection == 2) //원하는 구구단 출력
		{
			printf("원하는 구구단을 입력 : ");
			scanf("%d", &nDesireNumber);

			for (int nColumn = 1; nColumn < 10; nColumn++) //곱해지는 숫자와 행담당
			{
				printf(" %2d x %2d = %2d\n", nDesireNumber, nColumn, nDesireNumber * nColumn);
			}

		}


	} while (nMenuSelection != 3);

	//exit(0);


	//2. 숫자 맞추기 게임만들기
	//   - 1~10 사이의 난수를 맞추는 게임
	//   - 입력한 수를 기준으로 작거나 큰 경우 힌트를 알려준다
	//   - 예: 난수는 3
	//         입력한 수는 5
	//         5보다 작습니다

	int nRandomNumber;
	int nGuessNumber;
	int nQuizCount = 0;
	int nQuizScore = 0;


	while (nQuizCount < 3) //   - 시도 횟수는 3회, 3회에 맞추지 못하면 종료
	{
		if (nQuizCount == 0)
		{
			nRandomNumber = rand() % 10 + 1;
		}

		printf("(남은 기회 : %d) 입력한 수는 ", 3-nQuizCount);

		scanf("%d", &nGuessNumber);

		if (nRandomNumber == nGuessNumber)
		{
			nQuizCount = 0; //   - 시회 횟수내 정답을 맞출 경우 시도 횟수가 초기화 된다.
			nQuizScore += 10; //  - 점수 변수를 두어 맞출때마다 10점씩 증가
			printf("정답! 현재 스코어 : %d\n", nQuizScore);
			continue;
		}
		else if (nRandomNumber == nGuessNumber - 1 || nRandomNumber == nGuessNumber + 1)
		{
			//   - 만약 힌트가 답이 될 경우는 힌트가 없다.
			//   - 예: 난수는 1
			//         입력한 수는 2
		}
		else if (nRandomNumber > nGuessNumber)
		{
			printf("%d보다 큽니다.\n", nGuessNumber);
		}
		else if (nRandomNumber < nGuessNumber) 
		{
			printf("%d보다 작습니다.\n", nGuessNumber);
		}

		nQuizCount++;

	}
}