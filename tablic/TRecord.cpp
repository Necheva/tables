#include "TRecord.h"
#include<string.h>


TRecord::TRecord()
{
	key = 0;
	Data = 0;
	left = right = 0;
}

bool TRecord::IsEmpty()
{
	return key==0 && Data==0;
}

TRecord::TRecord(char * K, pointer D)
{
	key = new char[strlen(K) + 1];
	strcpy(key, K);
	Data = D;
	left = right = 0;
}

TRecord::TRecord(char * KEY)
{
	key = new char[strlen(KEY) + 1];
	strcpy(key, KEY);
	Data = new int[1];
	*Data = 1;
	left = right = 0; 
}

TRecord::TRecord(TRecord& Rec)
{
	key = new char[strlen(Rec.key) + 1];
	strcpy(key, Rec.key);
	Data = Rec.Data;
	left = right = 0;
}

TRecord& TRecord:: operator=(TRecord& Rec)
{
	if (key==0 || strlen(key) != strlen(Rec.key))
	{
		if(key!=0)
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

void TRecord::Print(int i)
{
		if (IsEmpty())
			cout << "FREE" << endl;
		else
		{
			if(i>=0)
				cout << "(" << i << ") ";
			cout <<key << " | " << *Data << endl;
		}
}

TRecord::~TRecord()
{
	delete[] key;
}