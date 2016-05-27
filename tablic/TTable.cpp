#include "TTable.h"
#include<string.h>
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
TTable::TTable()
{
	table = 0;
	count = 0;
	Max_Size = 0;
}

TTable::TTable(int Size)
{
	Max_Size = Size;
	table = new TRecord[Max_Size];
	count = 0;
}

TTable::TTable(TTable& Tab)
{
	Max_Size = Tab.Max_Size;
	table = new TRecord[Max_Size];
	count = Tab.count;
	for (int i = 0; i < count; i++)
	{
		table[i] = TRecord(Tab.table[i].key);
	}
}

int TTable::GetCount()
{
	return count;
}

TTable& TTable:: operator=(TTable& Tab)
{
	if (Max_Size != Tab.Max_Size)
	{
		delete[]table;
		Max_Size = Tab.Max_Size;
		table = new TRecord[Max_Size];
	}
	count = Tab.count;
	for (int i = 0; i < count; i++)
	{
		table[i] = TRecord(Tab.table[i].key);
	}
	return *this;
}

void TTable::Put(TRecord* Q)
{
	if (count == Max_Size)
		throw "Table is full";
	table[count] = *Q;
	count++;
}

int TTable::Search(TRecord* Q)
{
	return Search(Q->key);
}

int TTable::Search(char * key)
{
	for (int i = 0; i < count; i++)
	{
		if (strcmp(table[i].key, key) == 0)
		{
			return i;
		}
	}
	return -1;
}

TRecord & TTable::operator[](int i)
{
	return table[i];
}

void TTable::Del(TRecord* Q)
{
	int W = Search(Q);
	if (W == -1)
		throw "can't delete not existing element";
	for (int i = W; i < count - 1; i++)
	{
		table[i] = table[i + 1];
	}
	count--;
}

void TTable::Print()
{
	cout << " table" << endl;
	for (int i = 0; i < count; i++)
	{
		table[i].Print(i);
	}
}

TTable::~TTable()
{
	if (table != 0)
		delete[]table;
}

void TTable::L_F_F(char *FileName)
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
