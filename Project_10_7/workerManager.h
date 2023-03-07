#pragma once
#include <iostream>
#include <string>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include <fstream>

#define FILEPATH "./data.txt"

using namespace std;



// �ܵĹ��ܴ���


class WorkerManager {
public:

	//���캯��
	WorkerManager();

	void showMenu();
	void exitSystem();
	void showWorker();
	void addWorker();
	void save();
	int isExsit(int id);
	void deleteWorker();
	void updateWorker();
	void findWorker();
	void clean();
	int getNum();
	void init();
	void sort();
	


	//��������
	~WorkerManager();
public:
	int m_cap;   // ά����   Woker* ���� ������ĳ���
	Worker** m_p;	// ά����ָ�� ָ�����Woker* ���� ������
	bool m_fileIsEmpty;   //�ж��ļ��Ƿ�Ϊ��
};