#include "manager.h"
//���캯��
//Manager::Manager() {}

Manager::Manager(int id, string name) {
	m_id = id;
	m_name = name;
	m_did = 2;

}

// ��д�麯��
void Manager::showInfo() {
	cout << m_id << "\t\t " << m_name << "\t\t " << getDeptName() << endl;
}
string Manager::getDeptName() {
	return string("����");
}