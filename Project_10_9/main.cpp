#pragma once
#include <string>
#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
#include <ctime>
#include <stack>
#include <queue>
#include <list>
#include <set>
using namespace std;

void printDeque(const deque<int>& dq) {
	for (deque<int>::const_iterator it = dq.begin();it != dq.end();it++) {
		cout << (*it) << " ";
		//*it = 5;          const_iterator   �����Ͳ����޸���
	}
	cout << endl;
}

//deque �����Ĺ��� �͸�ֵ
void test01() {
	//deque ���޲ι���
	deque<int> dq1;
	for (int i = 0;i < 10;i++)
		dq1.push_back(i);
	printDeque(dq1);

	// deque ��3�ֿ�������
	deque<int> dq2(dq1.begin() + 1,dq1.end() - 1);

	deque<int> dq3(10, 100);

	deque<int> dq4(dq3);

	printDeque(dq2);
	printDeque(dq3);
	printDeque(dq4);

	//  ����operator= ��ֵ�����
	deque<int>dq5;
	dq5 = dq1;
	printDeque(dq5);
	// ���� assign(begin, end)   assign(n,elem) ���ָ�ֵ����
}


void test02() {
	deque<int> dq;
	dq.push_back(34);
	dq.push_back(24);
	dq.push_back(64);
	dq.push_back(235);
	dq.push_front(1324);
	dq.push_front(324);
	dq.push_front(3124);
	cout << "����ǰ : ";
	printDeque(dq);

	// sort����Ĭ�ϴ�С����     ֧��������ʵĵ�����������ʹ��sort����
	sort(dq.begin(), dq.end());
	cout << "����� : ";
	printDeque(dq);
}

// ѡ����
class Player {
public:
	Player(string name, int score) {
		this->name = name;
		this->score = score;
	}


public:
	string name;
	int score;
};

void creatPlayer(vector<Player>& v) {
	string name_seed = "ABCDE";
	for (int i = 0;i < 5;i++) {
		//v[i] = Player(name_seed[i], 0);  //����ģ�
		string name = string("ѡ��") + name_seed[i];        //�ַ���ƴ��ʱһ��Ҫͳһ���� string char����ȫ���� ��ʱ�������
		v.push_back(Player(name, 0));
	}
}
void printResult(vector<Player>& v) {
	for (vector<Player>::iterator it = v.begin();it != v.end();it++)
		cout << it->name << "�ĳɼ��ǣ� " << it->score << endl;
}

void setScore(vector<Player>& v) {
	//���������
	srand((unsigned int)time(NULL));
	int num = 0;
	for (vector<Player>::iterator it = v.begin(); it != v.end();it++) {

		deque<int> s;
		for (int i = 0;i < 10;i++) {
			num = rand() % 41 + 60;    //����60~100�������
			s.push_back(num);
		}
		sort(s.begin(), s.end());
		s.pop_back();
		s.pop_front();
		int sum = 0;
		for (deque<int>::iterator dit = s.begin();dit != s.end();dit++)
			sum += *dit;
		int avg = sum / s.size();
		it->score = avg;
	}
}
// ��ί��ְ���
void test03() {

	vector<Player> v;
	creatPlayer(v);
	setScore(v);
	printResult(v);
}

void printStack(stack<int> s) {
	cout << "��ջ����ջ�׵���������Ϊ��";
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}

// stack �ĳ��ýӿ�
void test04() {
	// stack �Ĺ��캯��   ջֻ�����ֹ��캯��  һ��Ĭ�Ϲ��� һ�ֿ�������
	stack<int> s;
	for (int i = 0;i < 10;i++)
		s.push(i);
	printStack(s);
	s.pop();
	s.pop();
	s.pop();

	stack<int> s2(s);
	printStack(s2);

	stack<int> s3;
	s3 = s2;           //stack �� ��ֵ���� ���� operator=
	printStack(s3);
}

void printQueue(queue<int> q) {
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}
// queue �ĳ��ýӿ�
void test05() {
	// queue �Ĺ��캯��   ���к�ջһ��ֻ�����ֹ��캯��  һ��Ĭ�Ϲ��� һ�ֿ�������
	queue<int> q;
	for (int i = 0;i < 10;i++)
		q.push(10 * i);
	printQueue(q);
	q.pop();
	q.pop();
	q.pop();

	queue<int> q2(q);
	printQueue(q2);




}



//                              ������list  ��Ϊ�βζ������֣���    �ǵ� 
//void printList(const list<int>& list) {
//
//	for (list<int>::const_iterator it = list.begin();it != list.end();it++)
//		cout << *it << " ";
//	cout << endl;
//}



void printList(const list<int>& L) {

	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) 
		cout << *it << " ";
	cout << endl;
}


void test06() {
	//   list ����Ĺ��캯��
	list<int> lst;
	for (int i = 0;i < 10;i++)
		lst.push_back(10 * i);
//	printList(lst);

	// list �����assign��ֵ  ������ operator= ������
	list<int> lst2;
	lst2.assign(10,100);
	//lst2 = lst1;

	cout << "����ǰ:" << endl;
	printList(lst);
	printList(lst2);

	//lst.swap(lst2);
	swap(lst, lst2);
	//sort(lst.begin(), lst.end());
	cout << "������:" << endl;
	printList(lst);
	printList(lst2);




}
void test07() {
	list<int> L;
	for (int i = 0;i < 6;i++)
		L.push_back(rand() % 99 + 1);
	cout << "reverse ��ת����ǰ��" << endl;
	printList(L);

	L.reverse();
	cout << "reverse ��ת�����" << endl;
	printList(L);

	//���ڵ�������֧���������   ������ it += 2 �������� ����ʹ��ȫ��sort 
	// �����ڸ������ڲ����ṩsort���������������
	//Ĭ�ϵ�������� ��С����
	L.sort();
	cout << "sort�����:" << endl;
	printList(L);
	L.reverse();
	cout << "reverse ��ת�����" << endl;
	printList(L);
}

class Person {
public:
	Person(string name, int height, int age) {
		this->name = name;
		this->height = height;
		this->age = age;
	}

public:
	string name;
	int height;
	int age;
};

void printListPerson(const list<Person>& L) {
	for (list<Person>::const_iterator it = L.begin();it != L.end();it++)
		cout << "ѡ�ֵ�������" << it->name << "\t\t��ߣ�" << it->height << "\t���䣺" << it->age << "\t" << endl;
}

bool myCompare(Person p1, Person p2) {
	if (p1.age == p2.age) return p1.height < p2.height;
	else return p1.age < p2.age;
}
// list �������Զ����������� ������
void test08() {
	list<Person> L;
	Person p1("ybq", 170, 19);
	Person p2("gbq", 178, 29);
	Person p3("ddq", 183, 39);
	Person p4("hbq", 184, 59);
	Person p5("zw", 164, 19);
	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	cout << "before sort:" << endl;
	printListPerson(L);
	L.sort(myCompare);
	cout << "after sort:" << endl;
	printListPerson(L);
}

void printSet(set<int>& s) {
	for (set<int>::iterator it = s.begin();it != s.end();it++)
		cout << *it << " ";
	cout << endl;
}
// set �ĳ��ýӿ�
void test09() {
	// set ����ֻ��Ĭ�Ϲ���Ϳ�������      ��ֵֻ������ operator=
	set<int> s1;

	// set ��������ֻ��insert û��push
	s1.insert(40);
	s1.insert(20);
	s1.insert(50);
	s1.insert(10);

	// set �������ݺ���Զ�����
	printSet(s1);


}



pair<string, int> test10() {
	//pair �����ִ�����ʽ
	//1.   pair<string, int> p("test",1);
	//2.   pair<string, int> p = make_pair("test10", 10);
	// ͨ��pair   �������ڿ���һ�η������������ˣ�������
	return make_pair("test10", 10);
}


//class MyCompare
//{
//public:
//	bool operator()(int v1, int v2) {             //!!!!!!! ���λ��Ҫ��const զҲ������ զҲ������
//		return v1 > v2;
//	}
//};
class MyCompare
{
public:
	bool operator()(int v1, int v2) const{
		return v1 > v2;
	}
};

class PersonCompare {
public:
	bool operator()(const Person p1, const Person p2) const {
		if (p1.height == p2.height)
			return p1.height < p2.height;
		else
			return p1.age < p2.age;
	}
};
void test11() {
	// s1 Ĭ�ϵ��������
	set<int> s1;
	s1.insert(19);
	s1.insert(39);
	s1.insert(519);
	s1.insert(1149);
	s1.insert(169);	
	printSet(s1);
	// diy s2's regular for sort
	set<int, MyCompare> s2;
	s2.insert(10);
	s2.insert(39);
	s2.insert(519);
	s2.insert(1149);
	s2.insert(169);
	for (set<int, MyCompare>::iterator it = s2.begin();it != s2.end();it++)
		cout << *it << " ";
	cout << endl;
	// s3 �Զ����������͵��������
	// �Ҷ����Զ����������ͣ�set����ָ���������ſ��Բ�������
	set<Person, PersonCompare> s3;
	Person p1("ybq", 170, 19);
	Person p2("gbq", 178, 29);
	Person p3("ddq", 183, 39);
	Person p4("hbq", 184, 59);
	Person p5("zw", 164, 19);
	s3.insert(p1);
	s3.insert(p3);
	s3.insert(p2);
	s3.insert(p4);
	s3.insert(p5);
	for (set<Person, PersonCompare>::iterator it = s3.begin();it != s3.end();it++)
		cout << "ѡ�ֵ�����Ϊ��" << it->name << "\t��ߣ�" << it->height << "\t���䣺" << it->age << endl;

	// set �в�������ͬ��ֵ����
}
int main() {
	
	// deque �����Ĺ���͸�ֵ
	//test01();

	// deque ����
	//test02();

	// ��ί��ְ���
	//test03();

	// stack �ĳ��ýӿ�
	//test04();

	// queue �ĳ��ýӿ�
	//test05();

	// list �ĳ��ýӿ�
	//test06();

	// list �ķ�ת������
	//test07();

	// list �������Զ����������� ������
	//test08();

	// set �ĳ��ýӿ�
	//test09();

	// pair ����Ĵ���
	//cout << "pair����ĵ�һ��������:" << test10().first << endl;
	//cout << "pair����ĵڶ���������:" << test10().second << endl;

	// set �Զ����������  ----> ͨ���º���  ���ࣩ   �� С����operator() ������ ����Զ���������߼�
	test11();

	return 0;
}






