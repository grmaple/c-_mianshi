#include"boss.h"

Boss::Boss(int id, string name, int dId) {
	m_Id = id;
	m_Name = name;
	m_DeptId = dId;
}

void Boss::showInfo() {
	cout << "ְ����ţ�" << m_Id << "\t";
	cout << "ְ��������" << m_Name << "\t";
	cout << "��λ��" << getDeptName() << "\t";
	cout << "ְ��ְ�𣺹���˾��������" << endl;
}

string Boss::getDeptName() {
	return string("�ϰ�");
}