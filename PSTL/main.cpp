#include "stdafx.h"
#include <memory>
#include <cctype>
#include "pstl\algorithm"
#include <iostream>
#include <fstream>//для файловых потоков
#include <string>//контейнер string
#include <vector>

using namespace std;

static string test;

class Znak
{
public:
	Znak() {
		name = " ";
		zodiac = " ";
		
	}
	void udZnak(string a, string b) {
		this->name = a;
		this->zodiac = b;
	}
	//Znak(const Znak &object){}
	string u_name_Znak() {
		return name;
	}
	string u_zodiac_Znak() {
		return zodiac;
	}
	

	~Znak() {

	}
	
private:
	
	string name; // фамилия, имя
	string zodiac; // знак зодиака
	
};
Znak foo(Znak a)
{
	if (a.u_zodiac_Znak() != string(test))
	{
		a.udZnak("", "");
		return a;
	}
	else {
		return a;
	}
}

void increment(vector<Znak> *vec1, vector<Znak> *vec2) {
		
	transform(execution::par, vec1->begin(), vec1->end(),vec2->begin(), foo);
}



int main() {
	int menu = 0;
	Znak add;
	vector<Znak> vec1;
	vector<Znak> vec2;
	int ch;
	string str;
	string namePerson; // фамилия, имя
	string zodiacPerson; // знак зодиака
	int cnt = 0;
	string path = "book.txt";
	ifstream fin;
	ofstream fout;
	
	
	while (true)
	{
		
		cout << "1. Add new person" << endl;
		cout << "2. save to file"<< endl;
		cout << "3. load of file" << endl;
		cout << "4. find person with zodiak"<< endl;
		cout << "6. exit"<< endl;
		cout << "Enter number:   " << endl;
		cin >> menu;
		switch (menu)
		{
			case 1: //добавление новой персоны
			{
				cout << "Enter name of person:   "<< endl;
				cin >> namePerson;
				cout << "Enter znak of person:" << endl;
				cin >> zodiacPerson;
							
				add.udZnak(namePerson, zodiacPerson);
				vec1.push_back(add);
				menu = 0;
				continue;
			}

			case 2://сохранение данных в файл
			{
				fout.open(path, ofstream::app);
				if (!fout.is_open())
				{
					cout << "can't open this file" << "\n" << endl;
					menu = 0;
					continue;
				}
				else
				{
					for (auto it = vec1.begin(); it != vec1.end(); ++it)
					{
						fout << vec1[cnt].u_name_Znak()<< ';' << vec1[cnt].u_zodiac_Znak()<< endl;
						cnt++;
					}
					cnt = 0;
					fout.close();
					menu = 0;
					continue;
				}
			}
			case 3://загрузка из файла
			{
				vec1.clear();
				fin.open(path);
				
				if (!fin)return 1;
				while ((ch = fin.get()) != EOF) {
					if(char(ch) != '\n') {
						str += char(ch);
						if (char(ch) == ';') cnt = str.size();
					}
					else
					{
						cout << cnt << endl;
						namePerson=str.substr(0,cnt-1);
						zodiacPerson = str.substr(cnt+1,( str.length() - cnt - 1));
						add.udZnak(namePerson, zodiacPerson);
						vec1.push_back(add);
						str.clear();
						cnt = 0;
					}
				}
				fin.close(); //Закрываем файл
				menu = 0;
				continue;
			}
			case 4://поиск по задиаку
			{
				system("cls");
				cout << "Enter zodiac for find:   " << endl;
				cin >> test;
				vec2 = vec1;
				system("cls");
				
				increment(&vec1, &vec2);

				for (auto it = vec2.begin(); it != vec2.end(); ++it)
				{
					if (vec2[cnt].u_name_Znak() != "") {
						cout << vec2[cnt].u_name_Znak() << '\n' << endl;
						cout << vec2[cnt].u_zodiac_Znak() << '\n' << endl;
					}
					cnt++;
				}
				
				cnt = 0;
				menu = 0;
				continue;
			}
			case 10:
			{
				system("cls");
				for (auto it = vec1.begin(); it != vec1.end(); ++it)
				{
					cout << "*****************" << '\n' << endl;
					cout << vec1[cnt].u_name_Znak() << '\n' << endl;
					cout << vec1[cnt].u_zodiac_Znak() << '\n' << endl;
					cnt++;
				}
				cnt = 0;
				menu = 0;
				continue;
			}
			case 6:
			{
				return 0;
				break;
				
			}
		}
		
	}
	return 0;
}
