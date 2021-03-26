/*************************************************************************
	> 作者: grmaple
	> 名字：演讲比赛流程管理系统
	> 功能: 演讲比赛流程管理系统
	> 时间: 2020.9.4
 ************************************************************************/
#include<iostream>
using namespace std;
#include<string>
#include<algorithm>
#include<deque>
#include<numeric>
#include<map>
#include<fstream>
#include<ctime>
#include<vector>
#include<functional>
class Speaker {
public:
	string m_Name;//姓名
	double m_Score[2];//分数
};
class SpeechManager {
public:
	SpeechManager();
	~SpeechManager();
	//菜单界面
	void show_Menu();
	//退出系统
	void exitSystem();
	//初始化属性
	void initSpeech();
	//创建选手
	void createSpeaker();
	//开始比赛
	void startSpeech();
	//抽签
	void speedDraw();
	//比赛
	void speechContest();
	//显示分数
	void showScore();
	//保存记录
	void saveRecord();
	//读取记录
	void loadRecord();
	//显示往届得分
	void showRecord();
	//清空记录
	void clearRecord();

	bool fileIsEmpty;//文件标志为空的标志
	map<int, vector<string>> m_Record;//往届记录
	vector<int> v1;//比赛选手总数 12
	vector<int> v2;//第二轮比赛选手 6
	vector<int> vVictory;//决赛前三名 3
	map<int, Speaker> m_Speaker;//存放编号，以及对应选手
	int m_Index;//记录比赛轮数
};
SpeechManager::SpeechManager() {
	initSpeech();
	createSpeaker();
	loadRecord();
}
SpeechManager::~SpeechManager() {

}
void SpeechManager::show_Menu() {
	cout << "****************************" << endl;
	cout << "***** 欢迎参加演讲比赛 *****" << endl;
	cout << "***** 1、开始演讲比赛 ******" << endl;
	cout << "***** 2、查看往届记录 ******" << endl;
	cout << "***** 3、清空比赛记录 ******" << endl;
	cout << "***** 0、退出比赛程序 ******" << endl;
	cout << "****************************" << endl;
	cout << endl;
}
void SpeechManager::exitSystem() {
	cout << "欢迎下次使用" << endl;
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
		string name = "选手";
		name += nameSeed[i];
		Speaker sp;
		sp.m_Name = name;
		for (int i = 0; i < 2; i++) {
			sp.m_Score[i] = 0;
		}
		//12名选手编号
		v1.push_back(i + 10001);
		//选手编号以及对应选手，存放到map中
		m_Speaker.insert(make_pair(i + 10001, sp));
	}
}
void SpeechManager::startSpeech() {
	//第一轮比赛
	//1.抽签
	speedDraw();
	//2.比赛
	speechContest();
	//3.显示晋级结果
	showScore();
	//第二轮比赛
	m_Index++;
	//1.抽签
	speedDraw();
	//2.比赛
	speechContest();
	//3.显示最终结果
	showScore();
	//4.保存分数
	saveRecord();
	//重置比赛,获取记录
	initSpeech();
	createSpeaker();
	loadRecord();

	cout << "本届比赛完毕！" << endl;
	system("pause");
	system("cls");
}
void SpeechManager::speedDraw() {
	cout << "第<<" << m_Index << ">>轮比赛选手正在抽签" << endl;
	cout << "-------------------" << endl;
	cout << "抽签后演讲顺序如下：" << endl;
	if (m_Index == 1) {//第一轮比赛
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}
	else {//第二轮比赛
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
	cout << "------------第<<" << m_Index << ">>轮比赛正式开始------------" << endl;
	//临时容器，存放小组成绩，key为成绩，value为编号，
	//greater<double>为从大到小排序
	multimap<double, int, greater<double>> groupScore;
	int num = 0;//记录人员数
	vector<int> v_Src;//比赛人员数组
	if (m_Index == 1) {
		v_Src = v1;
	}
	else {
		v_Src = v2;
	}
	//遍历所有参赛选手
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++) {
		num++;
		//打分
		deque<double> d;
		for (int i = 0; i < 10; i++) {
			double score = (rand() % 401 + 600) / 10.f;
			d.push_back(score);
		}
		//求平均分
		sort(d.begin(), d.end(), greater<double>());
		d.pop_front();
		d.pop_back();
		double sum = accumulate(d.begin(), d.end(), 0.0f);
		double avg = sum / (double)d.size();
		//将平均分放进map
		m_Speaker[*it].m_Score[m_Index - 1] = avg;
		//分数放进临时小组groupScore
		groupScore.insert(make_pair(avg, *it));
		//每6人取前三名
		if (num % 6 == 0) {
			cout << "第" << num / 6 << "小组比赛名次" << endl;
			for (multimap<double, int, Speaker>::iterator it = groupScore.begin(); it != groupScore.end(); it++) {
				cout << "编号：" << it->second << "\t";
				cout << "姓名：" << m_Speaker[it->second].m_Name << "\t";
				cout << "成绩：" << m_Speaker[it->second].m_Score[m_Index - 1] << endl;
			}
			int count = 0;
			//取前三名
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
	cout << "------------第<<" << m_Index << ">>轮比赛完毕------------" << endl;
	system("pause");
}
void SpeechManager::showScore() {
	cout << "------------第<<" << m_Index << ">>轮晋级选手信息如下：------------" << endl;
	vector<int> v;//比赛人员数组
	if (m_Index == 1) {
		v = v2;
	}
	else {
		v = vVictory;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "编号：" << *it << "\t";
		cout << "姓名：" << m_Speaker[*it].m_Name << "\t";
		cout << "成绩：" << m_Speaker[*it].m_Score[m_Index - 1] << endl;
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
	cout << "记录已经保存" << endl;
	//有记录了，文件不为空
	fileIsEmpty = false;
}
void SpeechManager::loadRecord() {
	ifstream ifs("speech.csv", ios::in);
	if (!ifs.is_open()) {
		fileIsEmpty = true;
		//cout << "文件不存在！" << endl;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		//cout << "文件为空" << endl;
		fileIsEmpty = true;
		ifs.close();
		return;
	}
	//文件存在，并且有记录
	fileIsEmpty = false;
	ifs.putback(ch);
	string data;
	int index = 0;//第几届
	while (ifs >> data) {
		vector<string> v;//存放六个string字符串
		int pos = -1;//查到逗号位置的变量
		int start = 0;//查找的起始位置
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
		cout << "文件不存在，或记录为空！" << endl;
	}
	else {
		for (int i = 0; i < m_Record.size(); i++) {
			cout << "第" << i + 1 << "届" <<
				"冠军编号：" << m_Record[i][0] << "得分：" << m_Record[i][1] << " "
				"亚军编号：" << m_Record[i][2] << "得分：" << m_Record[i][3] << " "
				"季军编号：" << m_Record[i][4] << "得分：" << m_Record[i][5] << endl;
		}
	}

	system("pause");
	system("cls");
}
void SpeechManager::clearRecord() {
	cout << "确定清空？" << endl;
	cout << "1、确定" << endl;
	cout << "2、返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1) {
		//打开模式，如果存在则删除文件并重新创建
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();
		//重置数据
		initSpeech();
		createSpeaker();
		loadRecord();
		cout << "清空成功！" << endl;
	}
	system("pause");
	system("cls");
}

int main() {
	srand((unsigned int)time(NULL));//随机种子
	SpeechManager sm;
	int choice = 0;
	while (true) {
		sm.show_Menu();
		cout << "请输入你的选择：" << endl;
		cin >> choice;
		switch (choice) {
		case 1://开始比赛
			sm.startSpeech();
			break;
		case 2://查看记录
			sm.showRecord();
			break;
		case 3://清空记录
			sm.clearRecord();
			break;
		case 0://退出系统
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