#include <iostream>
#include <string>
#include <ctime>
using namespace std;


void guess_game() {
	srand((unsigned int)time(NULL));
	int num = rand() % 100 + 1;
	int a = 0;
	cout << "num = " << num;
	cout << "\n������һ��1��100�����֣�";
	int count = 0;
	while (true) {
		count++;
		cin >> a;
		if (a == num) {
			cout << "��ϲ��¶��ˣ�����" << "��һ������" << count << "��";
			break;
		}
		else if (a > num) {
			cout << "�´���\n";
		}
		else if (a < num) {
			cout << "��С��\n";
		}
		cout << "�ز£�";
	}
}
int judge_score(short score) {		
	if (score > 600) {
		if (score > 700) {
			cout << "�㿼�����廪";
		}
		else if(score > 650) {
			cout << "�㿼���˱���";
		}
		else {
			cout << "�㿼����һ��";
		}
	}
	else if (score > 500) {
		cout << "�㿼���˶���";
	}
	else if (score > 400) {
		cout << "�㿼��������";
	}
	else {
		cout << "��û�п��ϣ�";
	}
	cout << '\n';
	return 0;
}
void swi(short a) {
	switch (a) {
		case 1:
			cout << "����������һ\n";
			break;
		case 2:
			cout << "����������er\n";
			break;
		case 3:
			cout << "����������san\n";
			break;
		case 4:
			cout << "����������si\n";
			break;
		case 5:
			cout << "����������wu\n";
			break;
		case 6:
			cout << "����������liu\n";
			break;
		case 7:
			cout << "relocation:";
		case 0:
			cout << "����������tian\n";
			break;
		defalut:
			cout << "i don't know\n";
	}

}
int three_mi(int a) {
	return a * a * a;
}
void game2(int a) {
	int temp = a;
	int temp1 = temp % 10;
	temp /= 10;
	int temp2 = temp % 10;
	temp /= 10;
	int temp3 = temp % 10;
	int result = three_mi(temp1) + three_mi(temp2) + three_mi(temp3);
	if (result == a)
		cout << a << '\t';
}

int main() {
	short score = 0;
	// ifӦ��
	/*cout << "��������ĸ߿��ɼ���";
	cin >> score;
	judge_score(score);*/
	// ����

	//int a = 6;
	//int b = 2;
	//int c = 1;
	//c = ((a > b) ? a++ : b);
	//cout << a << b << c;
	
	//short b = 7;
	//swi(b);

	// ������
	//guess_game();

	//��λ��ˮ�ɻ���
	//int i = 153;
	//do {
	//	game2(i);
	//	i++;
	//} while (i < 1000);


	return 0;
	return 0;
	return 0;







}