#pragma once
#include<iostream>
#include"Point.h"
using namespace std;
class Circle {
public:
	void setR(int r);
	int getR();
	void setCenter(const Point& center);
	Point getCenter();
private:
	int m_R;//�뾶
	Point m_Center;//Բ��
};