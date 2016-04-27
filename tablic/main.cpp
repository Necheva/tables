#include"TTable.h"
#include"TSort.h"
#include<iostream>
using namespace std;
int main()
{
	char A;
	char key[80];
	TTable Q(10);
	for (int i = 0; i < 4; i++)
	{
		int* Data=new int[5];
		cout << "key= ";
		cin >> key;
		cout << "Data= ";
		cin >> *Data;
		Q.Put(new TRecord(key, Data));
	}
	Q.Print();
	cout << "input key to delete: ";
	cin >> key;
	Q.Del(new TRecord(key));
	Q.Print();

	TSort::Sort(&Q, 0, Q.GetCount()-1);
	Q.Print();
	cout << "input searching element: ";
	cin >> A;
	TSort::Bin_Search(&Q, &A);
	
	
}