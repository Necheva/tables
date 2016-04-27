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
	int GetCount();
	~TTable();
	TTable& operator=(TTable&);
	void Put(TRecord*);
	void Del(TRecord*);
	int Search(TRecord*);
	TRecord& operator[](int);
	void Print();
	friend class TSort;
};

