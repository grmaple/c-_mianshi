#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
#include<fstream>
#define FILENAME "empFile.txt"
class WorkerManager {
public:
	WorkerManager();
	~WorkerManager();
	//չʾ�˵�
	void Show_Menu();
	//�˳�����
	void exitSystem();
	//����ְ��
	void Add_Emp();
	//�����ļ�
	void save();
	//ͳ���ļ�������
	int get_EmpNum();
	//��ʼ��Ա��
	void init_Emp();
	//��ʾְ��
	void Show_Emp();
	//����ְ������ж�ְ���Ƿ����
	int IsExist(int id);
	//ɾ��ְ��
	void Del_Emp();
	//�޸�ְ��
	void Mod_Emp();
	//����ְ��
	void Find_Emp();
	//����ְ��
	void Sort_Emp();
	//����ļ�
	void Clean_File();

	int m_EmpNum;//��¼�ļ��е�����
	Worker** m_EmpArray;//Ա�������ָ��
	bool m_FileIsEmpty;//��־�ļ��Ƿ�Ϊ��
};
