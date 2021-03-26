#include"teacher.h"
#include<string>
#include"orderFile.h"
#include<vector>
Teacher::Teacher() {

}
Teacher::~Teacher() {

}
Teacher::Teacher(int id, string name, string pwd) {
	m_EmpID = id;
	m_Name = name;
	m_Pwd = pwd;
}
//�˵�����
void Teacher::operMenu() {
	cout << "��ӭ��ʦ��" << m_Name << "��¼��" << endl;
	cout << "\t\t ------------------------------" << endl;
	cout << "\t\t|                              |" << endl;
	cout << "\t\t|          1.�鿴����ԤԼ      |" << endl;
	cout << "\t\t|                              |" << endl;
	cout << "\t\t|          2.���ԤԼ          |" << endl;
	cout << "\t\t|                              |" << endl;
	cout << "\t\t|          0.ע����¼          |" << endl;
	cout << "\t\t|                              |" << endl;
	cout << "\t\t ------------------------------" << endl;
	cout << " �������ѡ��" << endl;
}
//�鿴����ԤԼ
void Teacher::showAllOrder() {
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++) {
		cout << i + 1 << "�� ";
		cout << "ԤԼ����:��" << of.m_orderData[i]["date"] << "\t";
		cout << "ʱ��:" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����") << "\t";
		cout << "ѧ��:" << of.m_orderData[i]["stuId"] << "\t";
		cout << "����:" << of.m_orderData[i]["stuName"] << "\t";
		cout << "����:" << of.m_orderData[i]["roomId"] << "\t";
		string status = "״̬:";//0ȡ����ԤԼ��1����У�2��ԤԼ��3ԤԼʧ��
		if (of.m_orderData[i]["status"] == "1") {
			status += "�����";
		}
		else if (of.m_orderData[i]["status"] == "2") {
			status += "ԤԼ�ɹ�";
		}
		else if (of.m_orderData[i]["status"] == "3") {
			status += "���δͨ����ԤԼʧ��";
		}
		else {
			status += "ԤԼ��ȡ��";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}
//����˵�ԤԼ��¼
int toBeReviewed() {
	OrderFile of;
	vector<int> v;//��ŷ��������ļ�¼
	int index = 0;
	for (int i = 0; i < of.m_Size; i++) {
		if (of.m_orderData[i]["status"] == "1") {
			v.push_back(i);
		}
	}
	return v.size();
}
//���ԤԼ
void Teacher::validOrder() {
	OrderFile of;
	int n = toBeReviewed();
	if (of.m_Size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	if (n == 0) {
		cout << "����Ҫ��˵�ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����˵�ԤԼ��¼���£�" << endl;
	vector<int> v;//��ŷ��������ļ�¼
	int index =0;
	for (int i = 0; i < of.m_Size; i++) {
		if (of.m_orderData[i]["status"] == "1") {
			v.push_back(i);
			cout << ++index << "�� ";
			cout << "ԤԼ����:��" << of.m_orderData[i]["date"] << "\t";
			cout << "ʱ��:" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����") << "\t";
			cout << "����:" << of.m_orderData[i]["roomId"] << "\t";
			string status = "״̬:";//0ȡ����ԤԼ��1����У�2��ԤԼ��-1ԤԼʧ��
			if (of.m_orderData[i]["status"] == "1") {
				status += "�����";
			}
			cout << status << endl;
		}
	}
	cout << "��������˵�ԤԼ��¼��0��ʾ����" << endl;
	int select = 0;
	int ret = 0;
	while (true) {
		cin >> select;
		if (select >= 0 && select <= v.size()) {
			if (select == 0) {
				break;
			}
			else {
				cout << "��������˽��" << endl;
				cout << "1��ͨ��" << endl;
				cout << "2����ͨ��" << endl;
				cin >> ret;
				if (ret == 1) {
					of.m_orderData[v[select - 1]]["status"] = "2";
				}
				else if (ret == 2) {
					of.m_orderData[v[select - 1]]["status"] = "-1";
				}
				of.updateOrder();
				cout << "�����ϣ�" << endl;
				break;
			}
		}
		cout << "������������������" << endl;
	}
	system("pause");
	system("cls");
}