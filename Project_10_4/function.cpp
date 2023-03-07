# include "main.h"


void knock_table() {
	for (int i = 1;i <= 100;i++) {
		bool result = (i % 10 == 7) || (i / 10) % 10 == 7 || i % 7 == 0;
		if (result)
			cout << "knock the table\n";
		else
			cout << i << '\t';
	}
}
void stars() {
	for (int i = 0;i < 10;i++) {
		for (int j = 0;j < 10;j++) {
			cout << "* ";
		}
		if (i < 9)
			cout << endl;
	}
}
void my_multiplication_tables() {
	for (int i = 1;i <= 9;i++) {
		for (int j = 1;j <= i;j++) {
			printf_s("%d * %d = %d\t", j, i, i * j);
		}
		cout << endl;
	}
}
int length(int arr[]) {
	return sizeof arr / sizeof(arr[0]);
}
void exchange_int(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void weight(int* arr, int length) {
	int max = arr[0];
	for (int i = 0;i < length - 1;i++)
		if (max < arr[i + 1])
			exchange_int(&max, &arr[i + 1]);
	cout << max;
}
void reverse_arr_int(int* arr, int length) {
	int head = 0;
	int tail = length - 1;
	while (head < tail) {
		exchange_int(&arr[head], &arr[tail]);
		head++;
		tail--;
	}
}
void print_arr(int* arr, int length) {
	for (int i = 0;i < length;i++) {
		cout << arr[i] << '\t';
	}
	cout << endl;
}
void bubble_sort(int* arr, int length) {
	//cout << "ԭ���飺";
	//print_arr(arr, length);
	for (int j = 0;j < length - 1;j++) {
		for (int i = 0;i < length - 1 - j;i++) {
			if (arr[i] > arr[i + 1])
				exchange_int(&arr[i], &arr[i + 1]);
		}
	}
	//cout << "��������飺";
	//print_arr(arr, length);
}
void print_stu(const Student* pstu) {
	cout << "ѧ�����֣�" << pstu->name << "�ɼ���" << pstu->score << endl;
}
void print_tea(const Teacher* ptea) {
	cout << "��ʦ���֣�" << ptea->name << endl;
	for (int i = 0; i < 5;i++) 
		print_stu(&(ptea->stu[i]));
	cout << endl;
}
void print_hero(const Hero* hero){
	cout << "Ӣ�۵�����:" << hero->name << "\tage:" << hero->age << "\tsex:" << hero->sex << endl;
}
Hero* find_hero_by_age(Hero* hero, const int length,int age) {
	Hero* temp = hero;
	for (int i = 0;i < length;i++) {
		if (hero[i].age == age)
			return temp;
		temp++;
	}
}
void print_hero_by_age(Hero* hero, const int length) {
	// int age[length] ������
	int age[5] = { 0 };
	for (int i = 0;i < length;i++)
		age[i] = hero[i].age;
	int len = sizeof age / sizeof age[0];
	bubble_sort(age, len);
	for (int i = 0;i < length;i++) {
		//cout << age[i] << endl;
		Hero* hr = find_hero_by_age(hero, length, age[i]);
		print_hero(hr);
	}
}

// ͨѶ¼��
void menu() {
	cout << "****************************" << endl
		<< "********" << "1.�����ϵ��" << "********" << endl
		<< "********" << "2.��ʾ��ϵ��" << "********" << endl
		<< "********" << "3.ɾ����ϵ��" << "********" << endl
		<< "********" << "4.������ϵ��" << "********" << endl
		<< "********" << "5.�޸���ϵ��" << "********" << endl
		<< "********" << "6.�����ϵ��" << "********" << endl
		<< "********" << "0.�˳�ͨѶ¼" << "********" << endl
		<< "****************************" << endl;
}
void add(Person* contact, int* pcap) {
	string name;
	string sex;
	int age;
	int telephone;
	string address;
	cout << "������������" << endl;
	cin >> name;
	cout << "�������Ա�" << endl;
	cin >> sex;
	cout << "���������䣺" << endl;
	cin >> age;
	cout << "��������ϵ�绰��" << endl;
	cin >> telephone;
	cout << "�������ͥסַ��" << endl;
	cin >> address;
	contact[*pcap].name = name;
	contact[*pcap].sex = sex;
	contact[*pcap].age = age;
	contact[*pcap].telephone = telephone;
	contact[*pcap].address = address;
	(*pcap)++;
}
void show(const Person* contact, int cap) {
	if (cap == 0) {
		cout << "ͨѶ¼Ϊ�գ��������ϵ��" << endl;
		return;
	}
	cout << "-----------------------------------------------------------" << endl;
	for (int i = 0;i < cap;i++) {
		cout << "������" << contact[i].name << "\t�Ա�" << contact[i].sex << "\t���䣺" << contact[i].age << "\t��ϵ�绰��"
			<< contact[i].telephone << "\t��ͥסַ��" << contact[i].address << endl;
	}
	cout << "-----------------------------------------------------------" << endl;
}
Person* find_person_by_name(Person* contact, int cap, string name) {
	Person* temp = contact;
	for (int i = 0;i < cap;i++) {
		if (contact[i].name == name)
			return temp;
		temp++;
	}
	cout << "û�������" << endl;
	return NULL;
}
int find_person_by_name2(Person* contact, int cap, string name) {
	for (int i = 0;i < cap;i++) {
		if (contact[i].name == name)
			return i;
	}
	cout << "û�������" << endl;
	return -1;
}
void delete_by_name(Person* contact, int* pcap) {
	string name = "";
	cout << "������Ҫɾ������ϵ�˵����֣�";
	cin >> name;
	int ret = find_person_by_name2(contact, *pcap, name);
	if (ret != -1) {
		if (confirm()) {
			for (int i = ret;i < (*pcap) - 1;i++)
				contact[i] = contact[i + 1];
			(*pcap)--;
			cout << "ɾ���ɹ���" << endl;
		}
	}
}
void find_by_name(Person* contact, int cap) {
	string name = "";
	cout << "������Ҫ���ҵ���ϵ�˵����֣�";
	cin >> name;
	Person* ps = find_person_by_name(contact, cap, name);
	if (ps) {
		cout << "������" << ps->name << "\t�Ա�" << ps->sex << "\t���䣺" << ps->age << "\t��ϵ�绰��"
			<< ps->telephone << "\t��ͥסַ��" << ps->address << endl;
	}
}
void update_by_name(Person* contact, int cap) {
	string name = "";
	cout << "������Ҫ�޸ĵ���ϵ�˵����֣�";
	cin >> name;
	Person* ps = find_person_by_name(contact, cap, name);
	if (ps) {
		string name;
		string sex;
		int age;
		int telephone;
		string address;
		cout << "������������" << endl;
		cin >> name;
		cout << "�������Ա�" << endl;
		cin >> sex;
		cout << "���������䣺" << endl;
		cin >> age;
		cout << "��������ϵ�绰��" << endl;
		cin >> telephone;
		cout << "�������ͥסַ��" << endl;
		cin >> address;
		ps->name = name;
		ps->sex = sex;
		ps->age = age;
		ps->telephone = telephone;
		ps->address = address;
	}
}
void cls() {
	system("pause");
	system("cls");
}
bool confirm() {
	string key = "";
	cout << "��ȷ��Ҫɾ����ȷ�������� Y ��������������ʾ��ȷ��" << endl;
	cin >> key;
	if (key == "Y")
		return true;
	return false;
}
