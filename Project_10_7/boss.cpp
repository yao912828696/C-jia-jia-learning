#include "boss.h"
//���캯��
Boss::Boss() {}

Boss::Boss(int id, string name) {
	m_id = id;
	m_name = name;
	m_did = 3;
}

// ��д�麯��
void Boss::showInfo() {
	cout << m_id << "\t\t " << m_name << "\t\t " << getDeptName() << endl;
}

string Boss::getDeptName() {
	return string("�ϰ�");
}