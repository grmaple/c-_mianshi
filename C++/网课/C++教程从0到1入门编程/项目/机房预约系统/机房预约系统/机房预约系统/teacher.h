#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"identity.h"

class Teacher :public Identity {
public:
	Teacher();
	~Teacher();
	Teacher(int id, string name, string pwd);
	//�˵�����
	virtual void operMenu();
	//�鿴����ԤԼ
	void showAllOrder();
	//���ԤԼ
	void validOrder();

	int m_EmpID;//��ʦ���
};