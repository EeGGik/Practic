// ConsoleApplication3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

#include "Func.h"
using namespace std;
int main()
{
	string word;
	translete add;//структура для записи данных
	vector<translete> cont;//вектор хранения словаря
	string path = "book.txt";//название файла хранилища результатов
	string str;
	int ch, cnt = 0, imenu=0;

	while (true)
	{
		menu();
		cin >> imenu;
		switch (imenu)
		{
			case 1://добавить слово в словарь
			{
				addtrans(cont);
				imenu = 0;
				continue;
			}
			case 2://удаление слова из словаря
			{
				
				deltrans(cont);
				imenu = 0;
				continue;
			}
			case 3://перевод слова
			{
				findtrans(cont);
				imenu = 0;
				continue;
			}
			case 4://Загрузить данные из файла
			{
				loadOf_trans(cont);
				imenu = 0;
				continue;
			}
			case 5://Загрузить данные в файл
			{
					imenu = 0;
					continue;
			}
			case 6://выход из программы
			{
				return 0;
			}
			case 10://проверка содержания вектора
			{

				cnt = 0;
				system("cls");
				for (auto it = cont.begin(); it != cont.end(); it++)
				{
					word = cont[cnt].rusW;
					ch = int(word[0]);
					cout << ch << endl;
					if (ch >0)
					{
						cout << "eng" << endl;
					}
					else
					{
						cout << "rus" << endl;
					}
					cout << cont[cnt].rusW << '\n' << endl;
					cout << cont[cnt].engW << '\n' << endl;
					cnt++;
				}
				cnt = 0;
				imenu = 0;
				continue;
			}
		}

	}
    return 0;
}
