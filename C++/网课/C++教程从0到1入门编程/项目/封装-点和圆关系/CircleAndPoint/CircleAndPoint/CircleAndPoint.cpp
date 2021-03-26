/*************************************************************************
	> ����: grmaple
	> ���֣����Բ�Ĺ�ϵ
	> ����: ���Բ��͵��࣬������Բ��ϵ
	> ʱ��: 2020.9.2
 ************************************************************************/

#include<iostream>
using namespace std;
#include <cmath>
#include"Point.h"
#include"Circle.h"

void isInCircle(Circle& c, Point& p) {
	//��������֮�����ƽ��
	int distance =
		pow((c.getCenter().getX() - p.getX()), 2) +
		pow((c.getCenter().getY() - p.getY()), 2);
	//����뾶ƽ��
	int r_distance = pow(c.getR(), 2);
	//�жϹ�ϵ
	if (distance == r_distance) { cout << "����Բ��" << endl; }
	else if (distance > r_distance) { cout << "����Բ��" << endl; }
	else { cout << "����Բ��" << endl; }
}
int main() {
	Circle c;
	c.setR(10);
	Point center;
	center.setX(10);
	center.setY(0);
	c.setCenter(center);

	Point p;
	p.setX(10);
	p.setY(11);

	isInCircle(c, p);
	system("pause");
	return 0;
}