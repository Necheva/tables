#include "TSort.h"
#include<string.h>
#include<iostream>
using namespace std;
TSort::TSort()
{
}


int TSort::Bin_Search(TTable *T,char*  k)
{
	(*T).Effectiv = 0;
	int F = 0, L = T->count;
	int mid =0;
	while ((L-F)>1)
	{
		mid = (F + L) / 2;
		/*cout << k << endl;
		cout << (*T)[mid].GetKey() << endl;
		cout << strcmp((*T)[mid].GetKey(), k) << endl;*/
		if (strcmp(T->operator[](mid).GetKey(), k) == 0)
			return mid;

		if ((strcmp(T->operator[](mid).GetKey(), k) < 0))
			F = mid;
		else
			L = mid;
		(*T).Effectiv++;
	}
	return -1;
}

int TSort::Line_Search(TTable *T, char * k)
{
	(*T).Effectiv1 = 0;
	int Size = T->count;
	for (int i = 0; i < Size; i++)
	{
		if (strcmp(T->operator[](i).GetKey(), k)==0)
			return i;
		(*T).Effectiv1++;
	}
	return -1;
}

void TSort::Sort(TTable * T, int First,int Last)
{
	(*T).Effectiv = 0;
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
			(*T).Effectiv++;
			F++;
			L--;
		}
	} while (F <= L);

	if (First < L) Sort(T, First, L);
	if (F < Last) Sort(T, F, Last);
}



