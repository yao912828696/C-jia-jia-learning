#include<iostream>
#include<string>
using namespace std;

const int N = 1e3 + 10;


//void quick_sort(int q[], int l, int r) {
//	if (l >= r) return;
//
//	int temp = r;
//	int mid = l + r >> 1;
//	int pivot = q[mid];
//	while (l > r) {
//		if (q[l] <= pivot) l++;
//		else if (q[r] >= pivot) r--;
//		else swap(q[l], q[r]);
//	}
//	quick_sort(q, 0, r);
//	quick_sort(q, l, r);
//}
void quick_sort(int q[], int l, int r)
{
	if (l >= r) return;

	int i = l - 1, j = r + 1, x = q[l + r >> 1];
	while (i < j)
	{
		do i++; while (q[i] < x);
		do j--; while (q[j] > x);
		if (i < j) swap(q[i], q[j]);
	}
	quick_sort(q, l, j), quick_sort(q, j + 1, r);
}
void quick_sort2(int q[], int l, int r) {
	if (l >= r) return;
	int pivot = q[l];
	int i = l, j = r;
	while (i < j) {
		if (q[j] > pivot) j--;
		else if (q[j] < pivot) q[i] = q[j];
		if (q[i] <= pivot) i++;
		else if (q[i] > pivot) q[j] = q[i];
	}
	q[i] = pivot;
	quick_sort2(q, l, i - 1);
	quick_sort2(q, i+1, r);
}
// quick_sort
void test01() {
	//10
	//	49 59 88 37 98 97 68 54 31 3
	int q[N] = { 49 ,59 ,88, 37 ,98, 97 ,68 ,54 ,31, 3 };
	for (int i = 0;i < 10;i++) printf("%d ", q[i]);
	cout << endl;
	quick_sort2(q, 0, 9);
	for (int i = 0;i < 10;i++) printf("%d ", q[i]);

}


// ����һ���ַ��� �����뵥��֮���ÿո����   �����������
void test02() {
	string str;
	// string ���� ֱ����cin����ʱ��ѿո���Ϊ�ַ���������־
	//cin >> str;
	// ��Ҫ�ѿո�Ҳ���ȥҪ��getline
	getline(cin, str);
	//cout << str.length() << endl;
	//cout << str;
	for (int i = 0, j = 0; i < str.length(); i++, j++) {
		while (j < i && j != ' ') j++;
		for (int k = i; k < j; k++) cout << str[k];
		i = j;
		cout << endl;
	}
}

int lowbit(int x) {
	return x & -x;
}
// ����lowbit ��һ������������1�ĸ���
void test03() {
	//int n = 10;  //  1010
	int n = 15;  //  1111
	int count = 0;
	while (n) {
		n -= lowbit(n);
		count++;
	}
	cout << count << endl;

}




int a[N] = {0, 1, 1, 2, 3, 5}, s[N];
// ����һ�������������� �������������������еĳ���
void test04() {

	// ��������  O(n^2)
	int res = 0;
	for (int i = 0;i < 6 ;i++) {
		for (int j = i;j > 0; j--) {
			if (a[j] == a[j - 1]) break;
			res = max(res, i - (j - 1) + 1);
		}
	}
	cout << res << endl;
	// ˫ָ��ѭ��  O(n)
	//int res = 0;
	//for (int i = 0, j = 0; i < 6; i++) {
	//	s[a[i]] ++;
	//	while (j <= i && s[a[i]] > 1) {
	//		s[a[j]]--;
	//		j++;
	//	}
	//	res = max(res, i - j + 1);
	//}
	//cout << res << endl;
	
}
//int main() {
//	//test01();
//
////test02();
//
//
////test03();
//
////test04();
//
//}



//#include<iostream>
//#include<string>
//using namespace std;
//#define PI 3.1415926
//
//class Base {
//public:
//	virtual void print() {
//		cout << "Base" << endl;
//	}
//};
//class Der1: public Base{
//public:
//	void print() {
//		cout << "Der1" << endl;
//	}
//};
//class Der2 : public Base {
//public:
//	void print() {
//		cout << "Der2" << endl;
//	}
//};
//
//class Shapes {
//protected:
//	double x, y, z;
//public:
//	void dShapes(double d, double w) {
//		x = d, y = w;
//	}
//	void rShapes(double r) {
//		z = r;
//	}
//	virtual void display() = 0;
//};
//class Square : public Shapes {
//	void display() {
//		cout << "���ε��ܳ�Ϊ��" << 2 * (x + y) << "\t���ε����Ϊ��" << x * y << endl;
//	}
//};
//class Circle : public Shapes {
//	void display() {
//		cout << "Բ���ܳ�Ϊ��" << 2 * PI * z << "\tԲ�����Ϊ��" << PI * z * z << endl;
//	}
//};
//
//class Person {
//public:
//	Person() {}
//	Person(string name, int age):name(name),age(age) {}
//	void show() {
//		cout << "Person���" << name << age << "��" << endl;
//	}
//	string name;
//	int age;
//
//
//};
//class Student: public Person {
//public:
//	int score;
//	
//	Student(string name, int age, int score) {
//		this->name = name;
//		this->age = age;
//		this->score = score;
//	}
//	void show() {
//		cout << "Stundent��" << age << "���" << name << "�ķ�����: " << score << endl;
//	}
//
//};
//class Worker : public Person {
//public:
//	double salary;
//
//	Worker(string name, int age, double salary) {
//		this->name = name;
//		this->age = age;
//		this->salary = salary;
//	}
//	void show() {
//		cout <<  "Worker��" << age << "���" << name << "��нˮ��: " << salary << endl;
//	}
//};
//
//
//
//
//void test1() {
//	Base base;
//	Der1 der1;
//	Der2 der2;
//
//	Base* pb = &base;
//	pb->print();
//	pb = &der1;
//	pb->print();
//	pb = &der2;
//	pb->print();
//}
//void test2() {
//	Shapes* ptr[2] = { NULL };
//	Square s1;
//	s1.dShapes(2.34, 5.23);
//	Circle c1;
//	c1.rShapes(6.66);
//
//	ptr[0] = &s1;
//	ptr[1] = &c1;
//	ptr[0]->display();
//	ptr[1]->display();
//
//}
//void test3() {
//	Person p1("����", 18);
//	Student p2("����", 19, 95);
//	Worker p3("����", 20, 16888.8);
//
//	p1.show();
//	p2.show();
//	p3.show();
//}
//int main() {
//
//	//�����⣺
//	cout << "������:" << endl;
//	test1();
//
//	//�����⣺
//	cout << endl << "������:" << endl;
//	test2();
//
//	//�����⣺
//	cout << endl << "������:" << endl;
//	test3();
//
//	return 0;
//}

#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nShowCmd) {
	MessageBox(NULL, L"a�緹��", L"d��", 0);
}