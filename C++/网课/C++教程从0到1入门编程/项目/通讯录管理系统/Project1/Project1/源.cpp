/*************************************************************************
	> ����: grmaple
	> ���֣�ͨѶ¼����ϵͳ
	> ����: ��ʾ��ϵ��
	> ʱ��: 2020.9.2
 ************************************************************************/

#include<iostream>
using namespace std;
#include<string>
#define MAX 1000

void showMenu() {
	cout << "*************************" << endl;
	cout << "***** 1�������ϵ�� *****" << endl;
	cout << "***** 2����ʾ��ϵ�� *****" << endl;
	cout << "***** 3��ɾ����ϵ�� *****" << endl;
	cout << "***** 4��������ϵ�� *****" << endl;
	cout << "***** 5���޸���ϵ�� *****" << endl;
	cout << "***** 6�������ϵ�� *****" << endl;
	cout << "***** 0�����ͨѶ¼ *****" << endl;
	cout << "*************************" << endl;
}
struct Person {
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;
};
struct Addressbooks {
	struct Person personArray[MAX];
	int m_Size;
};
//�����ϵ��
void addPerson(Addressbooks& abs) {
	//���ж�ͨѶ¼��û����
	if (abs.m_Size == MAX) {
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else {
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs.personArray[abs.m_Size].m_Name = name;
		//�Ա�
		int sex = 0;
		cout << "�������Ա�(1:��,2:Ů)��" << endl;
		while (1) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs.personArray[abs.m_Size].m_Sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}
		//����
		int age = 0;
		cout << "���������䣺" << endl;
		while (1) {
			cin >> age;
			if (age >= 0 && age <= 100) {
				abs.personArray[abs.m_Size].m_Age = age;
				break;
			}
			cout << "������������������" << endl;
		}
		//��ϵ�绰
		string phone;
		cout << "��������ϵ�绰��" << endl;
		cin >> phone;
		abs.personArray[abs.m_Size].m_Phone = phone;
		//��ͥסַ
		string address;
		cout << "�������ͥסַ��" << endl;
		cin >> address;
		abs.personArray[abs.m_Size].m_Addr = address;
		//����ͨѶ¼����
		abs.m_Size++;
		cout << "��ӳɹ�" << endl;
		system("pause");//�����������
		system("cls");//����
	}
}
//��ʾ��ϵ��
void showPerson(Addressbooks& abs) {
	if (abs.m_Size == 0) {
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < abs.m_Size; i++) {
			cout << "������" << abs.personArray[i].m_Name << '\t';
			cout << "�Ա�" << (abs.personArray[i].m_Sex == 1 ? "��" : "Ů") << '\t';
			cout << "���䣺" << abs.personArray[i].m_Age << '\t';
			cout << "�绰��" << abs.personArray[i].m_Phone << '\t';
			cout << "סַ��" << abs.personArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}
int main() {
	int select = 0;
	Addressbooks abs;
	abs.m_Size = 0;

	string namee;
	cin >> namee;

	cout << namee;

	while (true) {
		showMenu();
		cin >> select;
		switch (select) {
		case 1://1�������ϵ��
			addPerson(abs);
			break;
		case 2://2����ʾ��ϵ��
			showPerson(abs);
			break;
		case 3://3��ɾ����ϵ��
			break;
		case 4://4��������ϵ��
			break;
		case 5://5���޸���ϵ��
			break;
		case 6://6�������ϵ��
			break;
		case 0://0�����ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			return 0;
		default:
			break;
		}
	}


	//system("pause");
	return 0;
}