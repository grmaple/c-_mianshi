#pragma once
#include<iostream>
using namespace std;
#include<map>
#include"globalFile.h"
#include<string>
class OrderFile {
public:
	OrderFile();
	~OrderFile();
	//����ԤԼ��¼
	void updateOrder();
	//map<string, string> key�������ԣ�value����ʵֵ
	//map<int, map<string, string>> key�����¼����
	map<int, map<string, string>> m_orderData;//��¼������
	int m_Size;//ԤԼ��¼����
};