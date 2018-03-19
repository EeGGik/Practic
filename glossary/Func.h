#pragma once
#include "stdafx.h"
#include <iostream>
#include <fstream>//для файловых потоков
#include <string>//контейнер string
#include<vector>
using namespace std;
struct translete
{
	string rusW;//русское слово
	string engW;//перевод на английский
};
void menu();
vector<translete> addtrans(vector<translete> &cont);//добавить в словарь
vector<translete> deltrans(vector<translete> &cont);//удалить из словаря
void findtrans(vector<translete> &cont);//найти в словаре
vector<translete> loadOf_trans(vector<translete> &cont);//загрузить из файла
vector<translete> loadIn_trans(vector<translete> &cont);//загрузить в файл