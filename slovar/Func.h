#pragma once
#include "stdafx.h"
#include <iostream>
#include <fstream>//��� �������� �������
#include <string>//��������� string
#include<vector>
using namespace std;
struct translete
{
	string rusW;//������� �����
	string engW;//������� �� ����������
};
void menu();
vector<translete> addtrans(vector<translete> &cont);//�������� � �������
vector<translete> deltrans(vector<translete> &cont);//������� �� �������
void findtrans(vector<translete> &cont);//����� � �������
vector<translete> loadOf_trans(vector<translete> &cont);//��������� �� �����
vector<translete> loadIn_trans(vector<translete> &cont);//��������� � ����