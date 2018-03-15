#include "stdafx.h"
#include "Func.h"


void menu()
{
	setlocale(LC_ALL, "Russian");
	//system("cls");
	cout << "Меню" << endl;
	cout << "1 Добавить в словарь" << endl;
	cout << "2 Удаление слов из словаря" << endl;
	cout << "3 Перевод слова" << endl;
	cout << "4 Загрузить данные из файла" << endl;
	cout << "5 сохранить в файл" << endl;
	cout << "6 Выход" << endl;
}
vector<translete> addtrans(vector<translete>  &cont)
{
	string word;//переменная для записи промежуточных значений слов
	translete add;//структура для записи данных
	cout << "Введите слово: ";
	cin >> word;
	if (int(word[0]) < 0)
	{
		add.rusW = word;
	}
	else
	{
		add.engW = word;
	}
	cout << "Введите перевод: ";
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
	string word;//переменная для записи промежуточных значений слов
	
	int i = 0;
	cout << "введите слово для удаления: " << endl;
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
	string word;//переменная для записи промежуточных значений слов
	int i = 0;
	cout << "введите слово для поиска перевода: " << endl;
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
	translete add;//структура для записи данных
	string str;
	string path = "book.txt";//название файла хранилища результатов
	int ch,i=0;
	ifstream fin;//поток записи в файл
	cont.clear();
	fin.open(path);
	
	if (!fin)
	{
		cout << "can't open this file" << "\n" << endl;
	}
	while ((ch = fin.get()) != EOF) {//пока не конец файла
		if (char(ch) != '\n') {//пока не конец строки считываетм символы
			str += char(ch);
			if (char(ch) == ';') i = str.size();
		}
		else//записываем слова в вектор
		{

			add.rusW = str.substr(0, i - 1);
			add.engW = str.substr(i, (str.length() - i));
			cont.push_back(add);
			str.clear();
			i = 0;
		}
	}
	fin.close(); //Закрываем файл
	return cont;
}
vector<translete> loadIn_trans(vector<translete> &cont)
{
	ofstream fout;//поток считывания их файла
	string path = "book.txt";//название файла хранилища результатов
	int i = 0;
	ifstream fin;//поток записи в файл

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