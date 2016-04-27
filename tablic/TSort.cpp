#include "TSort.h"
#include<string.h>
TSort::TSort()
{
}

int TSort::Bin_Search(TTable *T,char*  k)
{
	int F = 0, L = T->count;
	while ((L-F)>1)
	{
		int mid = (F + L) / 2;
		if (strcmp((*T)[mid].GetKey(), k) == 0)
			return mid;

		if ((strcmp((*T)[mid].GetKey(), k) < 0))
			F = mid;
		else
			L = mid;
	}
	return -1;
}

void TSort::Sort(TTable * T, int First,int Last)
{
	char* Mid;
	int F = First, L = Last;
	TRecord tmp;
	TRecord Rec = T->operator[]((F + L) / 2);
	Mid =Rec.GetKey();
	do
	{
		TRecord RecF = (*T)[F]; // T->operator[](F);
		TRecord RecL = T->operator[](L);
		while (strcmp(RecF.GetKey(), Mid) < 0)///////////////////////////////
		{
			F++;
			RecF = (*T)[F];
		}

		while (strcmp(RecL.GetKey(), Mid) > 0)///////////////////////////////
		{
			L--;
			RecL = T->operator[](L);
		}
		if (F <= L)
		{
			/*(TTable)count = T[F];
			T[F] = T[L];
			T[L] =(TTable) count;*/
			
			tmp = (*T)[F];
			(*T)[F] = (*T)[L];
			(*T)[L] = tmp;

			F++;
			L--;
		}
	} while (F <= L);

	if (First < L) Sort(T, First, L);
	if (F < Last) Sort(T, F, Last);
}



