#pragma once
#include<iostream>
using namespace std;
#include "worker.h"


class Boss :public Worker {
public:
	//���캯��
	Boss();

	Boss(int id, string name);

	// ��д�麯��
	virtual void showInfo();

	virtual string getDeptName();
};
