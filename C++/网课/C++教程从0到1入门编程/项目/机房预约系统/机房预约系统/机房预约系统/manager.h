#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"identity.h"
#include"student.h"
#include"teacher.h"
#include<vector>
#include"computerRoom.h"
class Manager :public Identity {
public:
	Manager();
	~Manager();
	Manager(string name, string pwd);
	//�˵�����
	virtual void operMenu();
	//����˺�
	void addPerson();
	//�鿴�˺�
	void showPerson();
	//�鿴������Ϣ
	void showComputer();
	//���ԤԼ��¼
	void cleanFile();
	//��ʼ������
	void initVector();
	//ȥ�غ���
	bool checkRepeat(int id, int type);

	vector<Student> vStu;//ѧ������
	vector<Teacher> vTea;//��ʦ����
	vector<ComputerRoom> vCom;//��������
};