#pragma once
typedef int* pointer ;
class TRecord
{
	char *key;
	pointer Data;
public:
	//TRecord();
	TRecord(char * K = "", pointer Data = 0);
	TRecord(TRecord&);
	TRecord& operator=(TRecord& Rec);
	char* GetKey();
	~TRecord();
	friend class TTable;
	friend class TSort;
};

