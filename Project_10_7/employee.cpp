#include "employee.h"
//���캯��
//Employee::Employee(){}

Employee::Employee(int id, string name) {
	m_id = id;
	m_name = name;
	m_did = 1;

}

// ��д�麯��
void Employee::showInfo() {
	cout << m_id << "\t\t " << m_name << "\t\t " << getDeptName() << endl;
}

string Employee::getDeptName() {
	return string("Ա��");
}