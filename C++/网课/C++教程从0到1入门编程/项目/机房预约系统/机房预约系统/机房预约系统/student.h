#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"identity.h"
#include"computerRoom.h"
#include<vector>
class Student :public Identity {
public:
	Student();
	~Student();
	Student(int id, string name, string pwd);
	//�˵�����
	virtual void operMenu();
	//����ԤԼ
	void applyOrder();
	//�鿴�ҵ�ԤԼ
	void showMyOrder();
	//�鿴����ԤԼ
	void showAllOrder();
	//ȡ��ԤԼ
	void cancelOrder();

	int m_Id;//ѧ��ѧ��
	vector<ComputerRoom> vCom;//��������
};