#pragma once
#include"TTable.h"
static class TSort
{

public:
	TSort();
	static int Bin_Search(TTable* ,char* k);
	static void Sort(TTable *T, int First, int Last);
	~TSort()
	{}
};

