#include"manager.h"

Manager::Manager(int id, string name, int dId) {
	m_Id = id;
	m_Name = name;
	m_DeptId = dId;
}

void Manager::showInfo() {
	cout << "ְ����ţ�" << m_Id << "\t";
	cout << "ְ��������" << m_Name << "\t";
	cout << "��λ��" << getDeptName() << "\t";
	cout << "ְ��ְ������ϰ彻�������񣬲��·������Ա��" << endl;
}

string Manager::getDeptName() {
	return string("����");
}