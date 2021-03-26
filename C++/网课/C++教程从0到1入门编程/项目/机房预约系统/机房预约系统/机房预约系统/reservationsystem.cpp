#include<iostream>
using namespace std;
#include<fstream>
#include<string>
#include"identity.h"
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"

void LoginIn(string fileName, int type);
void managerMenu(Identity* &manager);
void studentMenu(Identity* &student);
void teacherMenu(Identity* &teacter);

//��¼����
void LoginIn(string fileName, int type) {
	Identity* person = NULL;
	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ�������" << endl;
		ifs.close();
		return ;
	}
	int id = 0;
	string name;
	string pwd;
	if (type == 1) {
		cout << "���������ѧ��" << endl;
		cin >> id;
	}
	else if (type == 2) {
		cout << "���������ְ����" << endl;
		cin >> id;
	}
	cout << "�������û�����" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;
	if (type == 1) {
		//ѧ����¼��֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (id == fId && name == fName && pwd == fPwd) {
				cout << "ѧ����֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//����ѧ����ݵ��Ӳ˵�
				studentMenu(person);
				return ;
			}
		}
	}
	else if (type == 2) {
		//��ʦ��¼��֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (id == fId && name == fName && pwd == fPwd) {
				cout << "��ʦ��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//�����ʦ��ݵ��Ӳ˵�
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3) {
		//����Ա��¼��֤
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd) {
			if (name == fName && pwd == fPwd) {
				cout << "��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//�������Ա��ݵ��Ӳ˵�
				managerMenu(person);
				return;
			}
		}
	}
	cout << "��֤��¼ʧ�ܣ�" << endl;
	system("pause");
	system("cls");
	return ;
}
//����Ա�˵�
void managerMenu(Identity* &manager) {
	while (true) {
		manager->operMenu();
		Manager* man = (Manager*)manager;
		int select = 0;
		cin >> select;
		switch (select) {
		case 1://����˺�
			cout << "����˺�" << endl;
			man->addPerson();
			break;
		case 2://�鿴�˺�
			cout << "�鿴�˺�" << endl;
			man->showPerson();
			break;
		case 3://�鿴����
			cout << "�鿴����" << endl;
			man->showComputer();
			break;
		case 4://���ԤԼ
			cout << "���ԤԼ" << endl;
			man->cleanFile();
			break;
		default:
			delete manager;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return ;
		}
	}
}
//ѧ���˵�
void studentMenu(Identity* &student) {
	while (true) {
		student->operMenu();
		Student* stu = (Student*)student;
		int select = 0;
		cin >> select;
		switch (select) {
		case 1://����ԤԼ
			cout << "����ԤԼ" << endl;
			stu->applyOrder();
			break;
		case 2://�鿴�ҵ�ԤԼ
			cout << "�鿴�ҵ�ԤԼ" << endl;
			stu->showMyOrder();
			break;
		case 3://�鿴����ԤԼ
			cout << "�鿴����ԤԼ" << endl;
			stu->showAllOrder();
			break;
		case 4:///ȡ��ԤԼ
			cout << "ȡ��ԤԼ" << endl;
			stu->cancelOrder();
			break;
		default:
			delete student;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//��ʦ�˵�
void teacherMenu(Identity* &teacter) {
	while (true) {
		teacter->operMenu();
		Teacher* man = (Teacher*)teacter;
		int select = 0;
		cin >> select;
		switch (select) {
		case 1://�鿴����ԤԼ
			cout << "�鿴����ԤԼ" << endl;
			man->showAllOrder();
			break;
		case 2://���ԤԼ
			cout << "���ԤԼ" << endl;
			man->validOrder();
			break;
		default:
			delete teacter;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
int main() {
	int select = 0;

	while (true) {
		cout << "=====================��ӭ��������ԤԼϵͳ=====================" << endl;
		cout << "������������" << endl;
		cout << "\t\t ------------------------------" << endl;
		cout << "\t\t|                              |" << endl;
		cout << "\t\t|          1.ѧ������          |" << endl;
		cout << "\t\t|                              |" << endl;
		cout << "\t\t|          2.��    ʦ          |" << endl;
		cout << "\t\t|                              |" << endl;
		cout << "\t\t|          3.�� �� Ա          |" << endl;
		cout << "\t\t|                              |" << endl;
		cout << "\t\t|          0.��    ��          |" << endl;
		cout << "\t\t|                              |" << endl;
		cout << "\t\t ------------------------------" << endl;
		cout << " �������ѡ��" << endl;

		cin >> select;
		switch (select) {
		case 1://ѧ�����
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2://��ʦ���
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://����Ա���
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0://�˳�ϵͳ
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			exit(0);
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}