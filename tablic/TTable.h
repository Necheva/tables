#pragma once
#include"TRecord.h"
class TTable
{
	TRecord* table;
	int count;
	int Max_Size;
public:
	TTable();
	TTable(int Size);
	TTable(TTable&);
	~TTable();
	TTable& operator=(TTable&);
	void Put(TRecord*);
	void Del(TRecord*);
	int Search(TRecord*);
	void Print();
};

