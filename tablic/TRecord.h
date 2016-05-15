#pragma once
typedef int* pointer;
class TRecord
{
	char *key;
	pointer Data;
public:
	//TRecord();
	TRecord(char * K, pointer Data);
	TRecord(char * KEY = "");
	TRecord(TRecord&);
	TRecord& operator=(TRecord& Rec);
	char* GetKey();
	void Inc_Data();
	~TRecord();
	friend class TTable;
	friend class TSort;
};
