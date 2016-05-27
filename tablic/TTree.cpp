#include "TTree.h"
#include<string.h>
#include<fstream>
#include<string>

TreeTable::TreeTable(): TTable()
{
}


TreeTable::~TreeTable()
{
	deleteTree(table);
	table = 0;
}

void TreeTable::deleteTree(TRecord *root)
{
	if (root->GetRight() != 0)
		deleteTree(root->GetRight());
	if (root->GetLeft() != 0)
		deleteTree(root->GetLeft());
	delete root;
	root = 0;
}

void TreeTable::Put(TRecord* Q)
{
	if (table == 0)
		table = Q;
	else
	{
		AddRecord(table, Q);
	}
}

void TreeTable::AddRecord(TRecord *root, TRecord *Q)
{
	if (strcmp(root->GetKey(), Q->GetKey()) == 0)//ключи совпадают
		root->Inc_Data();
	else
	{
		if (strcmp(root->GetKey(), Q->GetKey()) < 0)//добавляем вправо
		{
			if (root->GetRight() == 0)
			{
				root->SetRight(Q);
			}
			else
			{
				AddRecord(root->GetRight(), Q);
			}
		}
		else//добавляем влево
		{
			if (root->GetLeft() == 0)
			{
				root->SetLeft(Q);
			}
			else
			{
				AddRecord(root->GetLeft(), Q);
			}
		}
	}
}

void TreeTable::Print()
{
	int tab = 0;
	PrintTree(table, tab);
}

void TreeTable::PrintTree(TRecord * T, int tab)
{
	if (T->GetRight() != 0)
		PrintTree(T->GetRight(), tab + 8);
	for (int i = 0; i < tab; i++)
		cout << " ";
	T->Print(-1);//без печати номера
	if (T->GetLeft() != 0)
		PrintTree(T->GetLeft(), tab + 8);
}

void TreeTable::L_F_F(char * FileName)
{
	ifstream fin(FileName);
	string word;
	char buf[256];

	while (fin.good())
	{
		fin >> word;
		strcpy(buf, word.c_str());
		TRecord* Rec = new TRecord(buf);
		Put(Rec);
	}
	fin.close();
}

TRecord * TreeTable::Search(char * G)
{
	if (table == 0)
		return 0;
	else
	{
		return TreeSearch(table,G);
	}

	return nullptr;
}

TRecord * TreeTable::TreeSearch(TRecord* root,char *G)
{
	if (strcmp(root->GetKey(), G) == 0)
		return root;
	if (strcmp(root->GetKey(), G) < 0)//поиск справа
		if (root->GetRight() != 0)
			return TreeSearch(root->GetRight(), G);
		else
			return 0;
	else
		if (root->GetLeft() != 0)
			return TreeSearch(root->GetLeft(), G);
		else
			return 0;
}
