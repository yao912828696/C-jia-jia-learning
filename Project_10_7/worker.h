#pragma once
#include<iostream>
#include<string>
using namespace std;

//ְ���������
class Worker
{
public:

	//��ʾ������Ϣ
	virtual void showInfo() = 0;
	//��ȡ��λ����
	virtual string getDeptName() = 0;

	int m_id; //ְ�����
	string m_name; //ְ������
	int m_did;      //��λ  1-----Ա��    2-----����    3-----�ϰ�   �����ļ�����ʱ��λ���ж�
};