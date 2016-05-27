#pragma once
#include"TTable.h"
#include<iostream>
using namespace std;
class THash: public TTable
{
	
	int Effectiv2;

public:
	THash();
	THash(int);
	~THash();
	int hash(char * key);
	void Put(TRecord*);
	int Line_Prob(int);
	void Print();
	void L_F_F(char *FileName);
	int Search(char * key);
	int GetEffect2()
	{
		return Effectiv2;
	};
};

