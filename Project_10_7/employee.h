#pragma once 
#include<iostream>
using namespace std;
#include "worker.h"

class Employee :public Worker
{
public:

	//���캯��
	Employee(int id, string name);

	//��ʾ������Ϣ
	virtual void showInfo();

	//��ȡְ����λ����
	virtual string getDeptName();
};