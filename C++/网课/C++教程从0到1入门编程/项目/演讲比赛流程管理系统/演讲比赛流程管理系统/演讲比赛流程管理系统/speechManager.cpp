#include<iostream>
using namespace std;
#include"speechManager.h"
#include<string>
#include<algorithm>
#include<deque>
#include<numeric>
#include<map>
#include<fstream>
#include<ctime>
SpeechManager::SpeechManager() {
	initSpeech();
	createSpeaker();
	loadRecord();
}
SpeechManager::~SpeechManager() {

}
void SpeechManager::show_Menu() {
	cout << "****************************" << endl;
	cout << "***** ��ӭ�μ��ݽ����� *****" << endl;
	cout << "***** 1����ʼ�ݽ����� ******" << endl;
	cout << "***** 2���鿴�����¼ ******" << endl;
	cout << "***** 3����ձ�����¼ ******" << endl;
	cout << "***** 0���˳��������� ******" << endl;
	cout << "****************************" << endl;
	cout << endl;
}
void SpeechManager::exitSystem() {
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}
void SpeechManager::initSpeech() {
	v1.clear();
	v2.clear();
	vVictory.clear();
	m_Speaker.clear();
	m_Index = 1;
	m_Record.clear();
}
void SpeechManager::createSpeaker() {
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++) {
		string name = "ѡ��";
		name += nameSeed[i];
		Speaker sp;
		sp.m_Name = name;
		for (int i = 0; i < 2; i++) {
			sp.m_Score[i] = 0;
		}
		//12��ѡ�ֱ��
		v1.push_back(i + 10001);
		//ѡ�ֱ���Լ���Ӧѡ�֣���ŵ�map��
		m_Speaker.insert(make_pair(i + 10001, sp));
	}
}
void SpeechManager::startSpeech() {
	//��һ�ֱ���
	//1.��ǩ
	speedDraw();
	//2.����
	speechContest();
	//3.��ʾ�������
	showScore();
	//�ڶ��ֱ���
	m_Index++;
	//1.��ǩ
	speedDraw();
	//2.����
	speechContest();
	//3.��ʾ���ս��
	showScore();
	//4.�������
	saveRecord();
	//���ñ���,��ȡ��¼
	initSpeech();
	createSpeaker();
	loadRecord();

	cout << "���������ϣ�" << endl;
	system("pause");
	system("cls");
}
void SpeechManager::speedDraw() {
	cout << "��<<" << m_Index << ">>�ֱ���ѡ�����ڳ�ǩ" << endl;
	cout << "-------------------" << endl;
	cout << "��ǩ���ݽ�˳�����£�" << endl;
	if (m_Index == 1) {//��һ�ֱ���
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
			cout<<*it<<" ";
		}
		cout << endl;
	}
	else {//�ڶ��ֱ���
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "-------------------" << endl;
	system("pause");
	cout << endl;
}
void SpeechManager::speechContest() {
	cout << "------------��<<" << m_Index << ">>�ֱ�����ʽ��ʼ------------" << endl;
	//��ʱ���������С��ɼ���keyΪ�ɼ���valueΪ��ţ�
	//greater<double>Ϊ�Ӵ�С����
	multimap<double, int, greater<double>> groupScore;
	int num = 0;//��¼��Ա��
	vector<int> v_Src;//������Ա����
	if (m_Index == 1) {
		v_Src = v1;
	}
	else {
		v_Src = v2;
	}
	//�������в���ѡ��
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++) {
		num++;
		//���
		deque<double> d;
		for (int i = 0; i < 10; i++) {
			double score = (rand() % 401 + 600) / 10.f;
			d.push_back(score);
		}
		//��ƽ����
		sort(d.begin(), d.end(), greater<double>());
		d.pop_front();
		d.pop_back();
		double sum = accumulate(d.begin(), d.end(), 0.0f);
		double avg = sum / (double)d.size();
		//��ƽ���ַŽ�map
		m_Speaker[*it].m_Score[m_Index - 1] = avg;
		//�����Ž���ʱС��groupScore
		groupScore.insert(make_pair(avg, *it));
		//ÿ6��ȡǰ����
		if (num % 6 == 0) {
			cout << "��" << num / 6 << "С���������" << endl;
			for (multimap<double, int, Speaker>::iterator it = groupScore.begin(); it != groupScore.end(); it++) {
				cout << "��ţ�" << it->second << "\t";
				cout << "������" << m_Speaker[it->second].m_Name << "\t";
				cout << "�ɼ���" << m_Speaker[it->second].m_Score[m_Index-1] << endl;
			}
			int count = 0;
			//ȡǰ����
			for (multimap<double, int, Speaker>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++, count++) {
				if (m_Index == 1) {
					v2.push_back((*it).second);
				}
				else {
					vVictory.push_back((*it).second);
				}
			}
			groupScore.clear();
			cout << endl;
		}
	}
	cout << "------------��<<" << m_Index << ">>�ֱ������------------" << endl;
	system("pause");
}
void SpeechManager::showScore() {
	cout << "------------��<<" << m_Index << ">>�ֽ���ѡ����Ϣ���£�------------" << endl;
	vector<int> v;//������Ա����
	if (m_Index == 1) {
		v = v2;
	}
	else {
		v = vVictory;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "��ţ�" << *it << "\t";
		cout << "������" << m_Speaker[*it].m_Name << "\t";
		cout << "�ɼ���" << m_Speaker[*it].m_Score[m_Index - 1] << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
	show_Menu();
}
void SpeechManager::saveRecord() {
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++) {
		ofs << *it << "," << m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << endl;
	ofs.close();
	cout << "��¼�Ѿ�����" << endl;
	//�м�¼�ˣ��ļ���Ϊ��
	fileIsEmpty = false;
}
void SpeechManager::loadRecord() {
	ifstream ifs("speech.csv", ios::in);
	if (!ifs.is_open()) {
		fileIsEmpty = true;
		//cout << "�ļ������ڣ�" << endl;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		//cout << "�ļ�Ϊ��" << endl;
		fileIsEmpty = true;
		ifs.close();
		return;
	}
	//�ļ����ڣ������м�¼
	fileIsEmpty = false;
	ifs.putback(ch);
	string data;
	int index = 0;//�ڼ���
	while (ifs >> data) {
		vector<string> v;//�������string�ַ���
		int pos = -1;//�鵽����λ�õı���
		int start = 0;//���ҵ���ʼλ��
		while (true) {
			pos = data.find(",", start);
			if (pos == -1) {
				break;
			}
			string tmp = data.substr(start, pos - start);
			//cout << tmp << endl;
			v.push_back(tmp);
			start = pos + 1;
		}
		m_Record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();
	//for (map<int, vector<string>>::iterator it = m_Record.begin(); it != m_Record.end(); it++) {
	//	cout << it->first << it->second[0] << it->second[1] << endl;
	//}
}
void SpeechManager::showRecord() {
	if (fileIsEmpty) {
		cout << "�ļ������ڣ����¼Ϊ�գ�" << endl;
	}
	else {
		for (int i = 0; i < m_Record.size(); i++) {
			cout << "��" << i + 1 << "��" <<
				"�ھ���ţ�" << m_Record[i][0] << "�÷֣�" << m_Record[i][1] << " "
				"�Ǿ���ţ�" << m_Record[i][2] << "�÷֣�" << m_Record[i][3] << " "
				"������ţ�" << m_Record[i][4] << "�÷֣�" << m_Record[i][5] << endl;
		}
	}
	
	system("pause");
	system("cls");
}
void SpeechManager::clearRecord() {
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;
	int select = 0;
	cin >> select;
	if (select == 1) {
		//��ģʽ�����������ɾ���ļ������´���
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();
		//��������
		initSpeech();
		createSpeaker();
		loadRecord();
		cout << "��ճɹ���" << endl;
	}
	system("pause");
	system("cls");
}



int main() {
	srand(time(NULL));//�������
	SpeechManager sm;
	int choice = 0;
	while (true) {
		sm.show_Menu();
		cout << "���������ѡ��" << endl;
		cin >> choice;
		switch (choice) {
		case 1://��ʼ����
			sm.startSpeech();
			break;
		case 2://�鿴��¼
			sm.showRecord();
			break;
		case 3://��ռ�¼
			sm.clearRecord();
			break;
		case 0://�˳�ϵͳ
			sm.exitSystem();
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}