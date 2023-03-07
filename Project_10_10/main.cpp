#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;



void printMapIS(map<int, string>& m1) {
	for (map<int, string>::iterator it = m1.begin();it != m1.end();it++)
		cout << "ѧ�ţ�" << (*it).first << "    \t������" << (*it).second << endl;
}
class Compare {
public:
	bool operator()(int a, int b) const {
		return a > b;
	}
};
// map �ĳ��ýӿ�
void test01() {
	// map ͬ��ֻ��Ĭ�Ϲ��� �Ϳ�������    �Լ����� operator= ������
	map<int, string> m1;
	pair<int, string> p1(1, "ybq");
	pair<int, string> p2(2, "dfgq");
	pair<int, string> p3(3, "gfdhdq");
	pair<int, string> p4(4, "aabq");
	pair<int, string> p5(5, "qrgs");
	m1.insert(p1);
	m1.insert(p3);
	m1.insert(p5);
	m1.insert(p4);
	m1.insert(p2);
	printMapIS(m1);
	cout << endl;
	//map �Ŀ�������
	map<int, string> m2(m1);
	printMapIS(m2);
	cout << endl;
	map<int, string>::iterator it = m2.begin();
	it++;
	m2.erase(it);
	// map ������operator=������
	map<int, string> m3;
	m3 = m2;
	printMapIS(m3);
	cout << endl;


	// map �Ĳ����ɾ��
	m1.insert(make_pair(10, "japfd"));
	m1[5] = "apodjf";            //map ����������operator [] ������    ����ͨ��[key] �ķ�ʽ���������ظ�pair<typename T1,typename T2>������&  value Ĭ��Ϊ0
	//   һ�㲻�����ַ�ʽ������  
	printMapIS(m1);

	int key = 1;
	m1.erase(key);				//ͨ��key��ɾ����ӦԪ��
	printMapIS(m1);

	map<int, string>::iterator it2 = m1.begin();
	it2++;
	m1.erase(it2);				//ͨ����������ɾ����ӦԪ��
	m1.erase(m1.begin(), m1.end());  //ͨ��������������ɾ����Ӧ����Ԫ��  ����ǰ�����
	m1.clear();					//clear() ����ͨ��ɾ������  ɾ������Ԫ��
	printMapIS(m1);


	cout << "------------The divider-------------" << endl; 
	// map ���Զ�������       ֻ��key��������
	map<int, string, Compare> m4;
	m4.insert(p1);
	m4.insert(p3);
	m4.insert(p5);
	m4.insert(p4);
	m4.insert(p2);
	for (map<int, string, Compare>::iterator it = m4.begin();it != m4.end();it++)
		cout << "ѧ�ţ�" << (*it).first << "    \t������" << (*it).second << endl;
}

class Worker {
public: 
	Worker(string name, int salary) {
		this->name = name;
		this->salary = salary;
	}
	string getName() {
		return name;
	}
	int getSalary() {
		return salary;
	}
private:
	string name;
	int salary;
};

void creatWorker(vector<Worker>& v) {
	string name_seed = "ABCDEFGHIJ";
	for (int i = 0;i < 10;i++) {
		string name = "Ա��";
		name += name_seed[i];
		int salary = rand() % 10000 + 10000;   // ����10000~19999;
		Worker worker(name, salary);
		v.push_back(worker);
	}
}

void setGroup(vector<Worker>& v, multimap<int, Worker>& m) {
	for (vector<Worker>::iterator it = v.begin();it != v.end();it++) {
		int key = rand() % 3;  // 0----�߻�  1----����  2----�з�
		m.insert(make_pair(key, *it));
	}
}
void showWorkerByGroup(multimap<int, Worker>& m) {

	// �ȷֱ��ҵ��������ſ�ʼ�ĵ�����
	//multimap<int, Worker>::iterator pos1 = m.find(0); 
	//multimap<int, Worker>::iterator pos2 = m.find(1);
	//multimap<int, Worker>::iterator pos3 = m.find(2);
	// �Ż��汾��
	multimap<int, Worker>::iterator pos1 = m.begin();
	multimap<int, Worker>::iterator pos2 = m.find(1);
	multimap<int, Worker>::iterator pos3 = m.find(2);
	if (pos2 == m.end()) pos2 = pos3;

	cout << "�߻����ţ�" << endl;
	while (pos1 != pos2) {
		cout << "������" << pos1->second.getName() << "  \t���ʣ�" << pos1->second.getSalary() << endl;
		pos1++;
	}
	cout << "�������ţ�" << endl;
	while (pos2 != pos3) {
		cout << "������" << pos2->second.getName() << "  \t���ʣ�" << pos2->second.getSalary() << endl;
		pos2++;
	}
	cout << "�з����ţ�" << endl;
	while (pos3 != m.end()) {
		cout << "������" << pos3->second.getName() << "  \t���ʣ�" << pos3->second.getSalary() << endl;
		pos3++;
	}

} 

void test02() {
	srand((unsigned int)time(NULL));
	vector<Worker> vWorker;
	creatWorker(vWorker);
	//����
	for (vector<Worker>::iterator it1 = vWorker.begin();it1 != vWorker.end();it1++)
		cout << "������" << it1->getName() << "  \t����:" << it1->getSalary() << endl;
	multimap<int, Worker> mWorker;
	setGroup(vWorker, mWorker);
	showWorkerByGroup(mWorker);
}

//void operator()() {
//	cout << "hello world" << endl ;        //����������ֻ�ܷ���������   ���ⲻ���������������
//}



class MyPrint {
public:
	MyPrint() {
		count = 0;
	}
	// �����˺������ò������������� ������Ϊ��������
	// ����������ã���ʱ ��Ϊ���ƺ�������  ���Ժ�������Ҳ�зº���
	void operator()(string str) {
		cout << str << endl;
		count++;
	}

public:
	int count; //���ڼ�¼�������õĴ���
};
//�º�����һ������ ����˵��һ����������
//�º����������Լ���״̬   �����ڲ��ĳ�Ա������ʵ��

void test03() {
	MyPrint myPrint;
	myPrint("hello world");
	myPrint("hello world");
	myPrint("hello world");
	myPrint("hello world");
	cout << "myPrint����������" << myPrint.count << "��" << endl;

}
#include <functional>
//negate

class Test {
public:
	Test(int n) {
		this->t = n;
	}
	int t;
};
void test04() {
	negate<int> n;
	cout << n(50) << endl;


	negate<Test> n2;

	n(Test(1));

}
int main() {

	// map �ĳ��ýӿ�
	//test01();

	// Ա������
	//test02();

	// �º�����ν��
	//test03();

	//STL�ڽ���һЩ��������   Ҫ����ͷ�ļ�#include <functional>

	test04();


	return 0;
}