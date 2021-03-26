#include"workerManager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

WorkerManager::WorkerManager(){
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//�ļ�������
	if (!ifs.is_open()) {
		cout << "�ļ�������" << endl;
		m_EmpNum = 0;
		m_FileIsEmpty = true;
		m_EmpArray = NULL;
		ifs.close();
		return ;
	}
	//�ļ����ڣ�����û�м�¼
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "�ļ�Ϊ��" << endl;
		m_EmpNum = 0;
		m_FileIsEmpty = true;
		m_EmpArray = NULL;
		ifs.close();
		return;
	}
	//�ļ����ڣ������м�¼
	int num = get_EmpNum();
	//cout << "ְ������Ϊ��" << num << endl;
	m_EmpNum = num;
	m_EmpArray = new Worker*[m_EmpNum];
	init_Emp();
	//for (int i = 0; i < m_EmpNum; i++) {
	//	cout << m_EmpArray[i]->m_Id << " "
	//		<< m_EmpArray[i]->m_Name << " "
	//		<< m_EmpArray[i]->m_DeptId << endl;
	//}
}
WorkerManager::~WorkerManager(){
	if (m_EmpArray != NULL) {
		for (int i = 0; i < m_EmpNum; i++) {
			if (m_EmpArray[i] != NULL) {
				delete m_EmpArray[i];
			}
		}
		//m_EmpNum = 0;
		delete[] m_EmpArray;
		m_EmpArray = NULL;
		//m_FileIsEmpty = true;
	}
}
void WorkerManager::Show_Menu() {
	cout << "*********************************" << endl;
	cout << "***** ��ӭʹ��ְ������ϵͳ! *****" << endl;
	cout << "******** 0���˳�������� ********" << endl;
	cout << "******** 1������ְ����Ϣ ********" << endl;
	cout << "******** 2����ʾְ����Ϣ ********" << endl;
	cout << "******** 3��ɾ����ְְ�� ********" << endl;
	cout << "******** 4���޸�ְ����Ϣ ********" << endl;
	cout << "******** 5������ְ����Ϣ ********" << endl;
	cout << "******** 6�����ձ������ ********" << endl;
	cout << "******** 7����������ĵ� ********" << endl;
	cout << "*********************************" << endl;
	cout << endl;
}
void WorkerManager::exitSystem() {
	cout << "��ӭ�´�ʹ��" <<endl;
	system("pause");
	exit(0);
}
void WorkerManager::Add_Emp() {
	cout << "����������ְ������" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0) {
		//�����¿ռ��С
		int newSize = m_EmpNum + addNum;
		//�����¿ռ�
		Worker** newSpace = new Worker*[newSize];
		//��ԭ�ռ������ݴ�ŵ��¿ռ���
		if (m_EmpArray != NULL) {
			for (int i = 0; i < m_EmpNum; i++) {
				newSpace[i] = m_EmpArray[i];
			}
		}
		//����������
		for (int i = 0; i < addNum; i++) {
			int id;
			string name;
			int dSelect;
			cout << "�������" << i+1 << "����ְ�����" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "����ְ������" << endl;
			cin >> name;
			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect){
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			newSpace[m_EmpNum + i] = worker;
		}
		//�ͷ�ԭ�пռ�
		delete[] m_EmpArray;
		//�����¿ռ��ָ��
		m_EmpArray = newSpace;
		//�����µ�ְ������
		m_EmpNum = newSize;
		//����ְ����Ϊ�ձ�־
		m_FileIsEmpty = false;
		//��ʾ��ӳɹ�
		cout << "�ɹ����" << addNum << "����ְ����" <<endl;
		//���浽�ļ���
		save();
	}
	else {
		cout << "��������" <<endl;
	}
	system("pause");
	system("cls");
}
void WorkerManager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < m_EmpNum; i++) {
		ofs << m_EmpArray[i]->m_Id << " "
			<< m_EmpArray[i]->m_Name << " "
			<< m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}
int WorkerManager::get_EmpNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {
		//����һ�����ݣ�����+1
		num++;
	}
	ifs.close();
	return num;
}
void WorkerManager::init_Emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {
		Worker* worker = NULL;
		if (dId == 1) {
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2) {
			worker = new Manager(id, name, dId);
		}
		else {
			worker = new Boss(id, name, dId);
		}
		//�����������
		m_EmpArray[index] = worker;
		index++;
	}
}
void WorkerManager::Show_Emp() {
	if (m_FileIsEmpty) {
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
	}
	else {
		for (int i = 0; i < m_EmpNum; i++) {
			//���ö�̬���ýӿ�
			m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

int WorkerManager::IsExist(int id) {
	int index = -1;
	for (int i = 0; i < m_EmpNum; i++) {
		if (m_EmpArray[i]->m_Id == id) {
			index = i;
			break;
		}
	}
	return index;
}
void WorkerManager::Del_Emp() {
	if (m_FileIsEmpty) {
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
	}
	else {
		cout << "��������Ҫɾ����ְ���ţ�" << endl;
		int id = 0;
		cin >> id;
		int index = IsExist(id);
		if (index != -1) {
			for (int i = index; i < m_EmpNum; i++) {
				m_EmpArray[i] = m_EmpArray[i + 1];
			}
			m_EmpNum--;
			save();
			cout << "ɾ���ɹ�" << endl;
		}
		else {
			cout << "ɾ��ʧ�ܣ����޴��ˣ�" << endl;
		}
	}
	system("pause");
	system("cls");
}
void WorkerManager::Mod_Emp() {
	if (m_FileIsEmpty) {
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
	}
	else {
		cout << "��������Ҫ�޸ĵ�ְ���ţ�" << endl;
		int id = 0;
		cin >> id;
		int index = IsExist(id);
		if (index != -1) {
			delete m_EmpArray[index];
			int newId = 0;
			string newName = "";
			int dSelect = 0;
			cout << "�鵽��" << id << "��ְ������������ְ���ţ�" << endl;
			cin >> newId;
			cout << "��������������" << endl;
			cin >> newName;
			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect) {
			case 1:
				worker = new Employee(newId, newName, 1);
				break;
			case 2:
				worker = new Manager(newId, newName, 2);
				break;
			case 3:
				worker = new Boss(newId, newName, 3);
				break;
			default:
				break;
			}
			//�������ݵ�������
			m_EmpArray[index] = worker;
			cout << "�޸ĳɹ�" << m_EmpArray[index]->m_DeptId << endl;
			//���浽�ļ�
			save();
		}
		else {
			cout << "�޸�ʧ�ܣ����޴��ˣ�" << endl;
		}
	}
	system("pause");
	system("cls");
}
void WorkerManager::Find_Emp() {
	if (m_FileIsEmpty) {
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
	}
	else {
		cout << "��������ҷ�ʽ��" << endl;
		cout << "1����ְ����Ų���" << endl;
		cout << "2������������" << endl;
		int select = 0;
		cin >> select;
		if (select == 1) {
			int id;
			cout << "��������Ҫ���ҵ�ְ���ţ�" << endl;
			cin >> id;
			int index = IsExist(id);
			if (index != -1) {
				cout << "���ҳɹ�!��ְ����Ϣ���£�" << endl;
				m_EmpArray[index]->showInfo();
			}
			else {
				cout << "����ʧ�ܣ����޴��ˣ�" << endl;
			}
		}
		else if (select == 2) {
			string name;
			cout << "��������Ҫ���ҵ�ְ��������" << endl;
			cin >> name;
			bool flag = false;//���ҵ��ı�־
			for (int i = 0; i < m_EmpNum; i++) {
				if (m_EmpArray[i]->m_Name == name) {
					cout << "���ҳɹ�,��ְ�����Ϊ��" << m_EmpArray[i]->m_Id << ",����Ϣ���£�" << endl;
					flag = true;
					m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false) {
				cout << "����ʧ�ܣ����޴��ˣ�" << endl;
			}
		}
		else {
			cout << "����ѡ������" << endl;
		}
	}
	system("pause");
	system("cls");
}
void WorkerManager::Sort_Emp() {
	if (m_FileIsEmpty) {
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "����������ʽ��" << endl;
		cout << "1����ְ����Ž�������" << endl;
		cout << "2����ְ����Ž��н���" << endl;
		int select = 0;
		cin >> select;
		//ѡ������
		for (int i = 0; i < m_EmpNum; i++) {
			int minOrMax = i;
			for (int j = i + 1; j < m_EmpNum; j++) {
				if (select == 1) {//����
					if (m_EmpArray[minOrMax]->m_Id > m_EmpArray[j]->m_Id) {
						minOrMax = j;
					}
				}
				else {//����
					if (m_EmpArray[minOrMax]->m_Id < m_EmpArray[j]->m_Id) {
						minOrMax = j;
					}
				}
			}
			if (i != minOrMax) {
				Worker* temp = m_EmpArray[i];
				m_EmpArray[i] = m_EmpArray[minOrMax];
				m_EmpArray[minOrMax] = temp;
			}
		}
		cout << "����ɹ����������Ϊ��" << endl;
		save();
		Show_Emp();
	}
}
void WorkerManager::Clean_File() {
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;
	int select = 0;
	cin >> select;
	if (select == 1) {
		//��ģʽ�����������ɾ���ļ������´���
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		if (m_EmpArray != NULL) {
			for (int i = 0; i < m_EmpNum; i++) {
				if (m_EmpArray[i] != NULL) {
					delete m_EmpArray[i];
				}
			}
			m_EmpNum = 0;
			delete[] m_EmpArray;
			m_EmpArray = NULL;
			m_FileIsEmpty = true;
		}
		cout << "��ճɹ���" << endl;
	}
	system("pause");
	system("cls");
}

int main() {
	WorkerManager wm;
	int choice = 0;
	while (true) {
		wm.Show_Menu();
		cout << "���������ѡ��" <<endl;
		cin >> choice;
		switch (choice){
		case 0://�˳�ϵͳ
			wm.exitSystem();
			break;
		case 1://���ְ��
			wm.Add_Emp();
			break;
		case 2://��ʾְ��
			wm.Show_Emp();
			break;
		case 3://ɾ��ְ��
			wm.Del_Emp();
			break;
		case 4://�޸�ְ��
			wm.Mod_Emp();
			break;
		case 5://����ְ��
			wm.Find_Emp();
			break;
		case 6://����ְ��
			wm.Sort_Emp();
			break;
		case 7://����ļ�
			wm.Clean_File();
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}