#include"employee.h"

Employee::Employee(int id, string name, int dId) {
	m_Id = id;
	m_Name = name;
	m_DeptId = dId;
}

void Employee::showInfo() {
	cout << "ְ����ţ�" << m_Id << "\t";
	cout << "ְ��������" << m_Name << "\t";
	cout << "��λ��" << getDeptName() << "\t";
	cout << "ְ��ְ����ɾ�����������" << endl;
}

string Employee::getDeptName() {
	return string("Ա��");
}