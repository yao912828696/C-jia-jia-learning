#pragma once
#include <iostream>
#include <string>

#define PI 3.14f
using namespace std;

class Circle1 {
	//Ȩ��
public:
	//����
	float radius;
	//��Ϊ ��������
	float calculate();
};

class Student {
public:
	string name;
	int num;

	void show_info();
};

class Test {
public:
	// ���캯��  ��������ʱ ���������Զ�ִ���������  û��дĬ��ִ�п�
	// ���캯�������в���  ���Է�������
	Test() {
		cout << "���ǹ��캯��" << endl;
	}
	// ��������  �ڶ�������ʱ ���������Զ�ִ���������  û��дĬ��ִ�п�
	// �������������в���  �����Է�������
	~Test() {
		cout << "������������" << endl;
	}
};