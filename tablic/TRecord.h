#pragma once
#include<iostream>
using namespace std;
typedef int* pointer;
class TRecord
{
	char *key;
	pointer Data;
	TRecord *left;
	TRecord *right;
public:
	TRecord();
	bool IsEmpty();
	TRecord* GetLeft() { return left; }
	TRecord* GetRight() { return right; }
	void SetLeft(TRecord* P) { left = P; }
	void SetRight(TRecord* R) { right = R; }
	TRecord(char * K, pointer Data);
	TRecord(char * KEY);
	TRecord(TRecord&);
	TRecord& operator=(TRecord& Rec);
	char* GetKey();
	void Inc_Data();
	void Print(int);
	~TRecord();
	friend class TTable;
	friend class TSort;
};
