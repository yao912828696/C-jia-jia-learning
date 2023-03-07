#pragma once
#include <string>
#include <iostream>
using namespace std;



template <class T>
class MyArray {
public:

	//���캯��
	MyArray(int cap);

	//��������
	MyArray(MyArray& arr);
	
	//β�庯��
	void PushBack(const T);
	//βɾ����
	void PopBack();

	//���ز�����=
	MyArray<T>& operator=(MyArray& arr);

	//��������
	~MyArray();

public:
	T* m_p;
	int m_size;
	int m_cap;
};

template <class T>
MyArray<T>::MyArray(int cap) {
	//cout << "MyArray �Ĺ��캯������" << endl;
	this->m_cap = cap;
	this->m_p = new T[cap];
	this->m_size = 0;
}

template <class T>
MyArray<T>::MyArray(MyArray& arr) {
	//cout << "MyArray �Ŀ������캯������" << endl;
	this->m_cap = arr.m_cap;
	this->m_size = arr.m_size;
	this->m_p = new T[this->m_size];
	for (int i = 0;i < this->m_size;i++) {
		this->m_p[i] = arr.m_p[i];
	}
}

template <class T>
MyArray<T>::~MyArray() {
	//cout << "MyArray ��������������" << endl;
	this->m_cap = 0;
	delete[] this->m_p;
	this->m_p = NULL;
	this->m_size = 0;
}


template <class T>
void MyArray<T>::PushBack(const T value) {
	T* temp = m_p;
	if (m_size < m_cap) {
		m_size++;
		m_p = new T[m_size];
		for (int i = 0;i < m_size - 1;i++) 
			m_p[i] = temp[i];
		m_p[m_size - 1] = value;
		delete[] temp;
		//cout << "��ӳɹ���" << endl;
	}
	else
		cout << "��������" << endl;
}


template <class T>
void MyArray<T>::PopBack() {
	if (m_p)
		m_size--;
}

template <class T>
MyArray<T>& MyArray<T>::operator =(MyArray& arr) {
	if (this->m_p) {
		delete[] this->m_p;
		this->m_cap = 0;
		this->m_size = 0;
	}
	this->m_cap = arr.m_cap;
	this->m_size = arr.m_size;
	this->m_p = new T[this->m_size];
	for (int i = 0;i < this->m_size;i++) {
		this->m_p[i] = arr.m_p[i];
	}
	return *this;
}
