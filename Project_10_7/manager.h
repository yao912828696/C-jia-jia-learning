#pragma once
#include<iostream>
using namespace std;
#include "worker.h"


class Manager :public Worker {
public:
	//���캯��
	//Manager();

	Manager(int id, string name);

	// ��д�麯��
	virtual void showInfo();

	virtual string getDeptName();
};
