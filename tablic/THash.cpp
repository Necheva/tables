#include "THash.h"
#include<fstream>
#include<string>

THash::THash():TTable()
{
}

THash::THash(int H):TTable(H)
{
	Effectiv2 = 0;
}


THash::~THash()
{
}

int THash::hash(char * key)
{
	int sum = 0;
	for (int i = 0; key[i] != 0; i++)
		sum += key[i];
	return sum%Max_Size;
}

void THash::Put(TRecord *Q)
{
	if (count == Size)
		throw"FULL";
	int index = hash(Q->GetKey());
	if (table[index].IsEmpty())
		table[index] = *Q;
	else
	{
		index = Line_Prob(index+1);//линейное пробирование
		if (index != -1)
		{
			table[index] = *Q;
		}
	}
	count++;
}

int THash::Line_Prob(int ind)
{
	int step = 0;
	while (true)
	{
		if (table[ind].IsEmpty())
			return ind;
		ind = (ind + 1) % Max_Size ;
		step++;
		if (step == Max_Size)
			break;
	}

	return -1;
}

void THash::Print()
{
	for (int i = 0; i < Max_Size; i++)
	{
		if (!table[i].IsEmpty())
		{
			cout << "[" << hash(table[i].GetKey()) << "]";
		}
		table[i].Print(i);

	}

		
}
void THash::L_F_F(char *FileName)
{
	ifstream fin(FileName);
	string word;
	char buf[256];

	while (fin.good())
	{
		fin >> word;
		strcpy(buf, word.c_str());

		int T = Search(buf);
		if (T == -1)
		{
			TRecord* Rec = new TRecord(buf);
			Put(Rec);
		}
		else
		{
			table[T].Inc_Data();
		}
	}
	fin.close();

}
int THash::Search(char * key)
{

	int step = 0;
	int index = hash(key);
	for (int i = index; ; i = (i + 1) % Max_Size)
	{
		if (table[i].IsEmpty())
			//Effectiv2++;
			return -1;
		if (strcmp(table[i].GetKey(), key) == 0)
		{
			return i;
		}
		step++;
		//Effectiv2++;
		if (step == Max_Size)
			break;
		
	}
	return -1;
}
