#include "stdafx.h"
#include "Func.h"


void menu()
{
	setlocale(LC_ALL, "Russian");
	//system("cls");
	cout << "����" << endl;
	cout << "1 �������� � �������" << endl;
	cout << "2 �������� ���� �� �������" << endl;
	cout << "3 ������� �����" << endl;
	cout << "4 ��������� ������ �� �����" << endl;
	cout << "5 ��������� � ����" << endl;
	cout << "6 �����" << endl;
}
vector<translete> addtrans(vector<translete>  &cont)
{
	string word;//���������� ��� ������ ������������� �������� ����
	translete add;//��������� ��� ������ ������
	cout << "������� �����: ";
	cin >> word;
	if (int(word[0]) < 0)
	{
		add.rusW = word;
	}
	else
	{
		add.engW = word;
	}
	cout << "������� �������: ";
	cin >> word;
	if (int(word[0]) < 0)
	{
		add.rusW = word;
	}
	else
	{
		add.engW = word;
	}

	cont.push_back(add);
	
	return cont;
}
vector<translete> deltrans(vector<translete> &cont)
{
	string word;//���������� ��� ������ ������������� �������� ����
	
	int i = 0;
	cout << "������� ����� ��� ��������: " << endl;
	cin >> word;
	for (auto it = cont.begin(); it != cont.end(); ++it)
	{
		
		if (cont[i].rusW == word) cont.erase(cont.begin() +i);
		if (cont[i].engW == word) cont.erase(cont.begin() +i);
		i++;
	}
	return cont;
}
void findtrans(vector<translete> &cont)
{
	string word;//���������� ��� ������ ������������� �������� ����
	int i = 0;
	cout << "������� ����� ��� ������ ��������: " << endl;
	cin >> word;
	for (auto it = cont.begin(); it != cont.end(); ++it)
	{
		if (cont[i].rusW == word)
		{
			cout << cont[i].engW << '\n' << endl;
		}
		
		if (cont[i].engW == word)
		{
			cout << cont[i].rusW << '\n' << endl;
		}
		i++;
	}

}

vector<translete> loadOf_trans(vector<translete> &cont)
{
	translete add;//��������� ��� ������ ������
	string str;
	string path = "book.txt";//�������� ����� ��������� �����������
	int ch,i=0;
	ifstream fin;//����� ������ � ����
	cont.clear();
	fin.open(path);
	
	if (!fin)
	{
		cout << "can't open this file" << "\n" << endl;
	}
	while ((ch = fin.get()) != EOF) {//���� �� ����� �����
		if (char(ch) != '\n') {//���� �� ����� ������ ���������� �������
			str += char(ch);
			if (char(ch) == ';') i = str.size();
		}
		else//���������� ����� � ������
		{

			add.rusW = str.substr(0, i - 1);
			add.engW = str.substr(i, (str.length() - i));
			cont.push_back(add);
			str.clear();
			i = 0;
		}
	}
	fin.close(); //��������� ����
	return cont;
}
vector<translete> loadIn_trans(vector<translete> &cont)
{
	ofstream fout;//����� ���������� �� �����
	string path = "book.txt";//�������� ����� ��������� �����������
	int i = 0;
	ifstream fin;//����� ������ � ����

	fout.open(path, ofstream::app);
	if (!fout.is_open())
	{
		cout << "can't open this file" << "\n" << endl;
		
	}
	else
	{
		for (auto it = cont.begin(); it != cont.end(); ++it)
		{

			fout << cont[i].rusW << ';' << cont[i].engW << endl;
			i++;
		}
		i = 0;
		fout.close();
	}
	return cont;
}