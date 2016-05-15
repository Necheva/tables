#include"TTable.h"
#include"TSort.h"
#include<iostream>
#include<fstream>
#include<locale.h>
#include<string>
#include<map>
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
	cout << "введите ключ, номер которого хотите определить: ";
	cin >> B;
	int ind = TSort::Line_Search(&T, B);
	if (ind < 0)
		cout << "не найдено" << endl;
	else
	{
		cout << "позици€ в неотсортированной таблице :" << ind << endl;
	}
	
	cout << "----------------------------------------------" << endl;
	TSort::Sort(&T, 0, T.GetCount() - 1);
	T.Print();
	cout << endl;
	cout << "введите ключ, номер которого хотите определить: ";
	cin >> A;
	int index =TSort::Bin_Search(&T,A);
	if (index < 0)
		cout<<"не найдено"<<endl;
	else
	{
		cout << "позици€ :" << index << endl;
	}
	cout << "----------------------------------------------" << endl;
	cout << "—татистика:" << endl;
	EF = T.GetEffect();
	cout << "Ёффективность работы в отсортированной таблице: " << EF << endl;
	EF1 = T.GetEffect1();
	cout << "Ёффективность работы в неотсортированной таблице: " << EF1 << endl;*/
	int tmp=-1;
	while (tmp != 7)
	{
		cout << "ввыберите действие:" << endl;
		cout << "1)вывести текст из файла" << endl;
		cout << "2)отсортировать таблицу " << endl;
		cout << "3)вывести отсортированную таблицу" << endl;
		cout << "4)поиск ключа в неотсортированной таблице" << endl;
		cout << "5)поиск ключа в отсортированной таблице" << endl;
		cout << "6)вывести статистику" << endl;
		cout << "7)выход" << endl;
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
			cout << "таблица отсортированна" << endl;
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
			cout << "введите ключ, номер которого хотите определить: ";
			cin >> B;
			int ind = TSort::Line_Search(&Q, B);
			if (ind < 0)
				cout << "не найдено" << endl;
			else
			{
				cout << "позици€ в неотсортированной таблице :" << ind << endl;
			}
			break;
		}
		case 5:
		{
			system("cls");
			T.Print();
			cout << "введите ключ, номер которого хотите определить: ";
			cin >> A;
			int index = TSort::Bin_Search(&T, A);
			if (index < 0)
				cout << "не найдено" << endl;
			else
			{
				cout << "позици€ :" << index << endl;
			}
			break;
		}
		case 6:
		{
			cout << "—татистика:" << endl;
			EF = T.GetEffect();
			cout << "Ёффективность работы в отсортированной таблице: " << EF << endl;
			EF1 = Q.GetEffect1();
			cout << "Ёффективность работы в неотсортированной таблице: " << EF1 << endl;
		}
		}
	}
	return 0;
}