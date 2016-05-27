#include"TTable.h"
#include"TSort.h"
#include<iostream>
#include<fstream>
#include<locale.h>
#include<string>
#include<map>
#include"THash.h"
#include"TTree.h"
using namespace std;

int main()
{
	//char A;
	//char key[80];
	//TTable Q(10);
	//for (int i = 0; i < 8; i++)
	//{
	//	int* Data=new int[5];
	//	cout << "input key= ";
	//	cin >> key;
	//	cout << "input data= ";
	//	cin >> *Data;
	//	Q.Put(new TRecord(key, Data));
	//}
	//Q.Print();
	//cout << "input key to delete: ";
	//cin >> key;
	//Q.Del(new TRecord(key));
	//Q.Print();
	//TSort::Sort(&Q, 0, Q.GetCount()-1);
	//cout << "sort the ";
	//Q.Print();
	//cout << "input searching element: ";
	//cin >> A;
	//cout<<TSort::Bin_Search(&Q, &A);
////////////////////////////////////////////////////////////////////////////
	setlocale(LC_ALL, "rus");
	int EF;
	int EF1;
	char A[100];
	char B[100];
	TTable T(100);
	TTable Q(100);
	Q.L_F_F("Text_Prog.txt");
	T.L_F_F("Text_Prog.txt");
	/*T.Print();
	cout << endl;
	cout << "������� ����, ����� �������� ������ ����������: ";
	cin >> B;
	int ind = TSort::Line_Search(&T, B);
	if (ind < 0)
		cout << "�� �������" << endl;
	else
	{
		cout << "������� � ����������������� ������� :" << ind << endl;
	}
	
	cout << "----------------------------------------------" << endl;
	TSort::Sort(&T, 0, T.GetCount() - 1);
	T.Print();
	cout << endl;
	cout << "������� ����, ����� �������� ������ ����������: ";
	cin >> A;
	int index =TSort::Bin_Search(&T,A);
	if (index < 0)
		cout<<"�� �������"<<endl;
	else
	{
		cout << "������� :" << index << endl;
	}
	cout << "----------------------------------------------" << endl;
	cout << "����������:" << endl;
	EF = T.GetEffect();
	cout << "������������� ������ � ��������������� �������: " << EF << endl;
	EF1 = T.GetEffect1();
	cout << "������������� ������ � ����������������� �������: " << EF1 << endl;*/ 
	int tmp=-1;
	while (tmp != 7)
	{
		cout << "================================"<<endl;
		cout << "��������� ��������:" << endl;
		cout << "1)������ ����� �� �����" << endl;
		cout << "2)������������� ������� " << endl;
		cout << "3)������� ��������������� �������" << endl;
		cout << "4)����� ����� � ����������������� �������" << endl;
		cout << "5)����� ����� � ��������������� �������" << endl;
		cout << "6)������� ����������" << endl;
		cout << "8)hash table"<<endl;
		cout << "9)tree table" << endl;
		cout << "7)�����" << endl;
		cin >> tmp;
		switch (tmp)
		{
		case 7:
		{
			break;
		}
		case 1:
		{
			Q.Print();
			break;
		}
		case 2:
		{
			TSort::Sort(&T, 0, T.GetCount() - 1);
			cout << "������� ��������������" << endl;
			break;
		}
		case 3:
		{
			T.Print();
			break;
		}
		case 4:
		{
			system("cls");
			Q.Print();
			cout << "������� ����, ����� �������� ������ ����������: ";
			cin >> B;
			int ind = TSort::Line_Search(&Q, B);
			if (ind < 0)
				cout << "�� �������" << endl;
			else
			{
				cout << "������� � ����������������� ������� :" << ind << endl;
			}
			break;
		}
		case 5:
		{
			system("cls");
			T.Print();
			cout << "������� ����, ����� �������� ������ ����������: ";
			cin >> A;
			int index = TSort::Bin_Search(&T, A);
			if (index < 0)
				cout << "�� �������" << endl;
			else
			{
				cout << "������� :" << index << endl;
			}
			break;
		}
		case 6:
		{
			cout << "����������:" << endl;
			EF = T.GetEffect();
			cout << "������������� ������ � ��������������� �������: " << EF << endl;
			EF1 = Q.GetEffect1();
			cout << "������������� ������ � ����������������� �������: " << EF1 << endl;
		}
		break;
		case 8:
		{
			char G[100];
			THash H(50);
			int EF2;
			H.L_F_F("Text_Prog.txt");
			H.Print();
			cout << "input ";
			cin >> G;
			cout<<H.Search(G)<<endl;
			EF2 = H.GetEffect2();
			cout << "stat: " << EF2<<endl;
		}
		break;
		case 9:
		{
			char G[100];
			TreeTable TR;
			TR.L_F_F("Text_Prog.txt");
			TR.Print();
			cout << "input ";
			cin >> G;
			TRecord *R = TR.Search(G);
			if (R != 0)
				R->Print(-1);
			else
				cout << "NOT FOUND" << endl;
		}
		break;
		}
	}
	return 0;
}