#pragma once
#include "sorting_functions.h"

void quickSortIntArr(int* arrNumber, int iLeft, int iRight)
{
	if (iLeft < iRight)
	{
		int nPivot, nTemp;
		nPivot = arrNumber[iLeft];

		int iPivotLeft = iLeft + 1;
		int iPivotRight = iRight;
		while (iPivotLeft <= iPivotRight)
		{
			while (arrNumber[iPivotLeft] >= nPivot)
			{
				if (iPivotLeft > iPivotRight) break;
				nTemp = arrNumber[iPivotLeft];
				arrNumber[iPivotLeft] = arrNumber[iPivotRight];
				arrNumber[iPivotRight] = nTemp;
				iPivotRight--;
			}
			if (arrNumber[iPivotLeft] < nPivot)
				iPivotLeft++;
		}

		nTemp = arrNumber[iLeft];
		arrNumber[iLeft] = arrNumber[iPivotRight];
		arrNumber[iPivotRight] = nTemp;


		quickSortIntArr(arrNumber, iLeft, iPivotRight - 1);
		quickSortIntArr(arrNumber, iPivotRight + 1, iRight);
	}
}