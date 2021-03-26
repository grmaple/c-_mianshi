#pragma once
#include<iostream>
using namespace std;
#include"speaker.h"
#include<map>
#include<vector>

class SpeechManager {
public:
	SpeechManager();
	~SpeechManager();
	//�˵�����
	void show_Menu();
	//�˳�ϵͳ
	void exitSystem();
	//��ʼ������
	void initSpeech();
	//����ѡ��
	void createSpeaker();
	//��ʼ����
	void startSpeech();
	//��ǩ
	void speedDraw();
	//����
	void speechContest();
	//��ʾ����
	void showScore();
	//�����¼
	void saveRecord();
	//��ȡ��¼
	void loadRecord();
	//��ʾ����÷�
	void showRecord();
	//��ռ�¼
	void clearRecord();


	bool fileIsEmpty;//�ļ���־Ϊ�յı�־
	map<int,vector<string>> m_Record;//�����¼
	vector<int> v1;//����ѡ������ 12
	vector<int> v2;//�ڶ��ֱ���ѡ�� 6
	vector<int> vVictory;//����ǰ���� 3
	map<int, Speaker> m_Speaker;//��ű�ţ��Լ���Ӧѡ��
	int m_Index;//��¼��������
};
