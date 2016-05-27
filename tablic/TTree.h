#pragma once
#include"TTable.h"
class TreeTable: public TTable
{
public:
	TreeTable();
	~TreeTable();
	void deleteTree(TRecord*);
	void Put(TRecord* Q);
	void AddRecord(TRecord*, TRecord*);
	void Print();
	void PrintTree(TRecord*, int);
	void L_F_F(char *FileName);
	TRecord* Search(char *);
	TRecord* TreeSearch(TRecord*,char*);
};

