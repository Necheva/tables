#pragma once
#include"TRecord.h"
class TTable
{
	TRecord* table;
	int count;
	int Max_Size;
	int Effectiv;
	int Effectiv1;
public:
	TTable();
	TTable(int Size);
	TTable(TTable&);
	int GetCount();
	~TTable();
	void L_F_F(char *);
	TTable& operator=(TTable&);
	void Put(TRecord*);
	void Del(TRecord*);
	int Search(TRecord*);
	int GetEffect()
	{
		return Effectiv;
	};
	int GetEffect1()
	{
		return Effectiv1;
	};
	int Search(char*); 
	TRecord& operator[](int);
	void Print();
	friend class TSort;
};
