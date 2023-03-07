#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <ctime>
#include <numeric>
using namespace std;
//��ͨ����
void myPrint1() {       
	cout << "test1" << endl;
}

void Test1(void (*f_p)() ) {    //��ͨ����ͨ�����뺯���������ú���ָ�룩�ķ�ʽ����Test1 �е��øú���
	f_p();						//���õķ�ʽ���� �ú���ָ��(������) �� ()
}
// α��������
class MyPrint2 { 
public:
	void operator()() {
		cout << "test2" << endl;
	}
}; 

void Test2(MyPrint2 mp) {  //α����ͨ�����뺯������(����α����) �ķ�ʽ����Test2 �е��ø�α����
	mp();					//���õķ�ʽ���� ��α����(������) �� ()
}

template<class T>
void Test3(T fn) {
	fn();				
}

void test01() {
	Test1(myPrint1);
	Test2(MyPrint2());
	Test3(myPrint1);
	Test3(MyPrint2());
}

void my_print(int value) {
	cout << value << " ";
}
class MyPrint {
public:
	void operator()(int value) {
		cout << value << " ";
	}
};

void test02() {
	vector<int> v;
	for (int i = 0;i < 10;i++)
		v.push_back(i);
	// for_each��Ѵ��������������ȡ�������� (*it) �����������Ĵ����� ���������ʲô���� �ͻ��ʲô
	for_each(v.begin(), v.end(), my_print);  // ���뺯����    ����  ����α��������  ��������ֱ�Ӽ�()���ܵ��õ��Ǹ�
	for_each(v.begin(), v.end(), MyPrint());// ���뺯����    ����  ����α��������  ��������ֱ�Ӽ�()���ܵ��õ��Ǹ�

}
class Person {
public:
	Person(){
		this->name = "";
		this->age = 0;
	}
	Person(string name, int age) {
		this->name = name;
		this->age = age;
	}
	// ʹ��find���� ����Զ����������ݵ����� 
	// ����Ҫ ���� == �Ա�find�ж� �Ƿ����
	bool operator==(const Person& p) {
		return this->name == p.name && this->age == p.age;
	}
	int operator+(const Person& p) {
		return this->age + p.age;
	}
	string name;
	int age;
};
void test03() {
	Person p1("ybq", 19);
	Person p2("asadgf", 29);
	Person p3("ghsd", 786);
	Person p4("qert", 75);
	Person p5("vsdf", 37);
	//p1 == p2;  ���У�
	vector<Person> v;
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	vector<Person>::iterator it = find(v.begin(), v.end(), p2);  // find ����
	if (it == v.end())
		cout << "can't find p2!" << endl;
	else cout << "find p2!\t" << "p2.name == " << it->name << "\tp2.age == " << it->age << endl;
	
 }
void test04() {
	vector<int> v;
	for (int i = 0;i < 6;i++) {
		v.push_back(rand() % 41 + 60);
	}
	cout << "vector<int> v ����sort����ǰ��" << endl;
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;

	sort(v.begin(), v.end()); 
	cout << "vector<int> v ����sort�����" << endl;
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;

	sort(v.begin(), v.end(),greater<int>());
	cout << "vector<int> v ����sort�������" << endl;
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;

	random_shuffle(v.begin(), v.end());
	cout << "vector<int> v ����random_shuffle ϴ�ƺ�" << endl;
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;
	
}
void test05() {
	vector<int> v;
	for (int i = 0; i <= 100; i++) {
		v.push_back(i);
	}

	int total = accumulate(v.begin(), v.end(), 0);

	cout << "total = " << total << endl;
}

int main() {

	//test01();

	// for_each ����
	//test02();

	//test03();

	// ���������㷨
	srand((unsigned int)time(NULL));	
	//test04();

	test05();
}
