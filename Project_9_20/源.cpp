#include <iostream>
#include <string>
using namespace std;

# define YBQ 666
int print_acsll(const char* var_name, const char var) {
	cout << var_name << " = " << var << '\n';
	cout << var_name << "��acsll����" << int(var) << "\n";
	return 0;
}

int main() {
	// system("pause");
	const int python = 123;
	int var = 789;
	cout << "var = " << var << "\n";
	cout << "YBQ = " << YBQ << "\n";
	cout << "python = " << python << "\n";
	cout << "hello world" << endl;

	cout << "short������ռ�ռ�Ϊ" << sizeof(short) << "���ֽ�" << "\n";
	cout << "int������ռ�ռ�Ϊ" << sizeof(int) << "���ֽ�" << "\n";
	cout << "long������ռ�ռ�Ϊ" << sizeof(long) << "���ֽ�" << "\n";
	cout << "long long������ռ�ռ�Ϊ" << sizeof(long long) << "���ֽ�" << "\n";
	cout << "float������ռ�ռ�Ϊ" << sizeof(float) << "���ֽ�" << "\n";
	cout << "double������ռ�ռ�Ϊ" << sizeof(double) << "���ֽ�" << "\n";
	cout << "char������ռ�ռ�Ϊ" << sizeof(char) << "���ֽ�" << "\n";
	char a = 'a';
	print_acsll("aasdf", a);
	char b = 98;
	print_acsll("badf", b);
	char c = 99;
	print_acsll("cadsf", c);
	cout << '\n';
	
	string str = "hello world!!!";

	bool flag = true;
	cout << flag << '\n';
	flag = false;
	cout << flag << '\n';
	flag = 100;
	cout << flag << '\n';
	flag = -100;
	cout << flag << '\n';
	flag = 0;
	cout << flag << '\n';

	cin >> a >> b >> c >> str >> flag;
	cout << a << b << c << str << flag;
	return 0;
}