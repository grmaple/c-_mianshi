#include"manager.h"
#include"globalFile.h"
#include<fstream>
#include<algorithm>
Manager::Manager() {

}
Manager::~Manager() {

}
Manager::Manager(string name, string pwd) {
	m_Name = name;
	m_Pwd = pwd;
	//��ʼ������
	initVector();
	//��ȡ������Ϣ����Ϊ��������Ķ���ֻ��һ������û�з�װ�ɺ���
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum) {
		vCom.push_back(c);
	}
	cout << "��ǰ��������Ϊ��" << vCom.size() << endl;
	ifs.close();
}
//�˵�����
void Manager::operMenu() {
	cout << "��ӭ����Ա��" << m_Name << "��¼��" << endl;
	cout << "\t\t ------------------------------" << endl;
	cout << "\t\t|                              |" << endl;
	cout << "\t\t|          1.����˺�          |" << endl;
	cout << "\t\t|                              |" << endl;
	cout << "\t\t|          2.�鿴�˺�          |" << endl;
	cout << "\t\t|                              |" << endl;
	cout << "\t\t|          3.�鿴����          |" << endl;
	cout << "\t\t|                              |" << endl;
	cout << "\t\t|          4.��ռ�¼          |" << endl;
	cout << "\t\t|                              |" << endl;
	cout << "\t\t|          0.ע����¼          |" << endl;
	cout << "\t\t|                              |" << endl;
	cout << "\t\t ------------------------------" << endl;
	cout << " �������ѡ��" << endl;
}
//����˺�
void Manager::addPerson() {
	cout << "����������˺ŵ����ͣ�" << endl;
	cout << "1�����ѧ��" << endl;
	cout << "2����ӽ�ʦ" << endl;
	string fileName;
	string tip;
	ofstream ofs;
	string errorTip;
	int select = 0;
	cin >> select;
	if (select == 1) {
		fileName = STUDENT_FILE;
		tip = "������ѧ��";
		errorTip = "ѧ���ظ�������������";
	}
	else {
		fileName = TEACHER_FILE;
		tip = "������ְ�����";
		errorTip = "ְ�����ظ�������������";
	}
	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	cout << tip << endl;
	while (true) {
		cin >> id;
		bool ret = checkRepeat(id, select);
		if (ret) {
			cout << errorTip << endl;
		}
		else {
			break;
		}
	}
	cout << "������������" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ�" << endl;
	system("pause");
	system("cls");
	ofs.close();
	//ÿ������꣬Ҫ��������
	initVector();
}
void printStudent(Student& s) {
	cout << "ѧ�ţ�" << s.m_Id << "\t" << "������" << s.m_Name << "\t" << "���룺" << s.m_Pwd << endl;
}
void printTeacher(Teacher& t) {
	cout << "ְ����" << t.m_EmpID << "\t" << "������" << t.m_Name << "\t" << "���룺" << t.m_Pwd << endl;
}
//�鿴�˺�
void Manager::showPerson() {
	cout << "��ѡ��鿴�����ݣ�" << endl;
	cout << "1���鿴����ѧ��" << endl;
	cout << "2���鿴���н�ʦ" << endl;
	int select = 0;
	cin >> select;
	if (select == 1) {
		cout << "����ѧ����Ϣ���£�" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else if (select == 2) {
		cout << "���н�ʦ��Ϣ���£�" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}
//�鿴������Ϣ
void Manager::showComputer() {
	cout << "������Ϣ���£�" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++) {
		cout << "������ţ�" << it->m_ComId << "\t�����������" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}
//���ԤԼ��¼
void Manager::cleanFile() {
	ofstream ofs(ORDER_FILE,ios::trunc);
	ofs.close();
	cout << "��ճɹ���" << endl;
	system("pause");
	system("cls");
}
void Manager::initVector() {
	//��ȡѧ���ļ���Ϣ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ�������" << endl;
		return;
	}
	vStu.clear();
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd) {
		vStu.push_back(s);
	}
	cout << "��ǰѧ������Ϊ��" << vStu.size() << endl;
	ifs.close();
	//��ȡ��ʦ�ļ���Ϣ
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ�������" << endl;
		return;
	}
	vTea.clear();
	Teacher t;
	while (ifs >> t.m_EmpID && ifs >> t.m_Name && ifs >> t.m_Pwd) {
		vTea.push_back(t);
	}
	cout << "��ǰ��ʦ����Ϊ��" << vTea.size() << endl;
	ifs.close();
}

bool Manager::checkRepeat(int id, int type) {
	if (type == 1) {
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++) {
			if (id == it->m_Id) {
				return true;
			}
		}
	}
	else {
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++) {
			if (id == it->m_EmpID) {
				return true;
			}
		}
	}
	return false;
}