#include "TRecord.h"
#include<string.h>


TRecord::TRecord(char * K, pointer D)
{
	key = new char[strlen(K) + 1];
	strcpy(key, K);
	Data = D;
}

TRecord::TRecord(char * KEY)
{
	key = new char[strlen(KEY) + 1];
	strcpy(key, KEY);
	Data = new int[1];
	*Data = 1;
}

TRecord::TRecord(TRecord& Rec)
{
	key = new char[strlen(Rec.key) + 1];
	strcpy(key, Rec.key);
	Data = Rec.Data;
}

TRecord& TRecord:: operator=(TRecord& Rec)
{
	if (strlen(key) != strlen(Rec.key))
	{
		delete[]key;
		key = new char[strlen(Rec.key) + 1];
	}
	strcpy(key, Rec.key);
	Data = Rec.Data;
	return *this;
}

char * TRecord::GetKey()
{
	return key;
}

void TRecord::Inc_Data()
{
	*Data += 1;
}

TRecord::~TRecord()
{
	delete[] key;
}