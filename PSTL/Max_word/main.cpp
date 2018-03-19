#include "stdafx.h"
#include <memory>

#include "pstl\algorithm"
#include <iostream>
#include <fstream>//для файловых потоков
#include <string>//контейнер string
#include <vector>//контейнер vector

using namespace std;

string foo(string str)//функция поиска максимально длинного слова в строке
{
	int maxLen = 0;
	int maxWordStartIndex = 0;

	int len = 0;
	for (int i = 0; i < str.length(); ++i)
	{
		if ((str[i] != ' ') && (str[i] != '\n') &&( i<(str.length()-1)))
			len++;
		else
		{
			if (len > maxLen)
			{
				maxLen = len;
				maxWordStartIndex = i - maxLen;
			}
			len = 0;
		}
	}

	return str.substr(maxWordStartIndex, maxLen+1);
}
void increment(vector<string> *sVec, vector<string> *sVec_res) {
	
	transform(execution::par, sVec->begin(), sVec->end(), sVec_res->begin(),foo);
}
int main() {
	
	int ch = 0;  //Это переменная, в которую нужно считывать символы
	string str;  //Это строка, она в примере будет абзацем
	vector<string> sVec; //Вектор строк 
	vector<string> sVec_res; //Вектор строк 
	const char *FName = "test.txt";  //Путь к файлу	

	//Считаем текст с форматированием
	ifstream in(FName);     //открыли для чтения  файл
	if (!in)return 1;
	while ((ch = in.get()) != EOF) {  
		if ((char(ch) != '\n')&& (char(ch)!=',')) str = str + char(ch);  //Считываем символ из файла и сразу проверяем его на признак переноса строки. 
		else {
			if (!str.empty()) sVec.push_back(str); //Если строка не пуста, то заносим ее в вектор
			str.clear(); //Очищаем строку
			
		}
	} 	
	in.close(); //Закрываем файл
	sVec_res = sVec;
	increment(&sVec,&sVec_res);	
	copy(sVec_res.begin(), sVec_res.end(), std::ostream_iterator<string>(cout, "\n\n"));  //Вывод вектора на экран
	return 0;
}
