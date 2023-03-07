#include <iostream>
#include <string>
#include <fstream>
using namespace std;


// �����һ������������   ��������������Ա ����һ��û���κ�����Ļ���� �麯�� ������ж�̬
// ��̬��ʹ�������������ָ���������ָ���������  ������Ҫ��д������麯��
class AbstractCaculator {
public:
	AbstractCaculator() {         //���캯��
		num1 = 10;
		num2 = 100;
	}
	virtual int getResult()	{
		return 0;
	}

public:
	int num1;
	int num2;

};

class AddCaculator :public AbstractCaculator {
	//��д�����麯��
	int getResult() {
		return num1 + num2;
	}
};

class SubCaculator :public AbstractCaculator {
	//��д�����麯��
	int getResult() {
		return num1 - num2;
	}
};

class MulCaculator :public AbstractCaculator {
	//��д�����麯��
	int getResult() {
		return num1 * num2;
	}
};

class DivCaculator :public AbstractCaculator {
	//��д�����麯��
	int getResult() {
		return num1 / num2;
	}
};

void test01() {
	//�ӷ��Ķ�̬
	AbstractCaculator* abc = new AddCaculator;  // �����ָ���������ָ���������
	cout << abc->num1 << " + " << abc->num2 << " = " << abc->getResult() << endl;
	delete abc;   //�������ٵ����ݼǵ�ʹ����Ϻ�Ҫdelete

	//�����Ķ�̬
	abc = new SubCaculator;  // �����ָ���������ָ���������
	cout << abc->num1 << " - " << abc->num2 << " = " << abc->getResult() << endl;
	delete abc;   //�������ٵ����ݼǵ�ʹ����Ϻ�Ҫdelete

	//�˷��Ķ�̬
	abc = new MulCaculator;  // �����ָ���������ָ���������
	cout << abc->num1 << " * " << abc->num2 << " = " << abc->getResult() << endl;
	delete abc;   //�������ٵ����ݼǵ�ʹ����Ϻ�Ҫdelete

	//�����Ķ�̬
	abc = new DivCaculator;  // �����ָ���������ָ���������
	cout << abc->num1 << " / " << abc->num2 << " = " << abc->getResult() << endl;
	delete abc;   //�������ٵ����ݼǵ�ʹ����Ϻ�Ҫdelete


}




// �����һ����Ʒ��������   ���ĸ�û���κ����崿�麯�� ������ж�̬   ���������Ʒ�������ĸ����²���  ��һ���ܵ�����
class MakeDrinks {
public:
	virtual void boil() = 0;
	
	virtual void brew() = 0;
	
	virtual void pour() = 0;
	
	virtual void put() = 0;

	void dowork() {
		boil();
		brew();
		pour();
		put();
	}
public:
	string drink_name = "";
};

class Coffee :public MakeDrinks {
	virtual void boil() {
		cout << "boilcoffee" << endl;
	}
	virtual void brew() {
		cout << "brewcoffee" << endl;
	}
	virtual void pour() {
		cout << "pourcoffee" << endl;
	}
	virtual void put() {
		cout << "putcoffee" << endl;
	}
};

class Tea :public MakeDrinks {
	virtual void boil() {
		cout << "boiltea" << endl;
	}
	virtual void brew() {
		cout << "brewtea" << endl;
	}
	virtual void pour() {
		cout << "pourtea" << endl;
	}
	virtual void put() {
		cout << "puttea" << endl;
	}
};

void doWork(MakeDrinks* md,string name) {
	md->dowork();
	md->drink_name = name;
	cout << "Your "<< md->drink_name << " is over!"<<endl;
	cout << "--------------------"<<endl;
	delete md;   //�ڶ�������Ŀռ�ǵ�ʹ������ͷ�

}


// �����CPU����
class CPU {
public:
	virtual void calculate() = 0;
};

// ������Կ�����
class VideoCard {
public:
	virtual void display() = 0;
};

// ������ڴ����
class Memory {
public:
	virtual void storage() = 0;
};

// Intel ���̵ĸ��������:
class IntelCPU :public CPU {
public:
	void calculate() {
		cout << " ����IntelCPU��ʹ��---" << endl;
	}
};
class IntelVideoCard :public VideoCard {
public:
	void display() {
		cout << " ����Intel�Կ���ʹ��---" << endl;
	}
};
class IntelMemory :public Memory {
public:
	void storage() {
		cout << " ����Intel�ڴ���ʹ��---" << endl;
	}
};

// Lenovo ���̵ĸ��������:
class LenovoCPU :public CPU {
public:
	void calculate() {
		cout << " ����LenovoCPU��ʹ��---" << endl;
	}
};
class LenovoVideoCard :public VideoCard {
public:
	void display() {
		cout << " ����Lenovo�Կ���ʹ��---" << endl;
	}
};
class LenovoMemory :public Memory {
public:
	void storage() {
		cout << " ����Lenovo�ڴ���ʹ��---" << endl;
	}
};

// ������
class Computer {
public:
	// ���캯�������������ָ��
	Computer(CPU* cpu, VideoCard* vc, Memory* mmy) {
		this->cpu = cpu;
		this->vc = vc;
		this->mmy = mmy;
	}
	// ���Կ�����
	void startUp() {
		cpu->calculate();
		vc->display();
		mmy->storage();
	}

	// ���������ͷ�
	~Computer() {
		cout << "ִ�е�����������" << endl;
		cout << "----------------------" << endl;
		delete cpu;
		delete vc;
		delete mmy;
	}
private:
	CPU* cpu;
	VideoCard* vc;
	Memory* mmy;

};

// ���Ե���װ����
void assembly(CPU* cpu, VideoCard* vc, Memory* mmy) { // �ø���ָ�루�������� Ҳ��ָ�룩��������������ָ�� ��ָ��������� ������̬��ʹ������
	//��������
	Computer computer(cpu, vc, mmy);
	// ����
	computer.startUp();
}


// ��̬��ѧϰ
//int main() {
	//  ʹ�ö�̬��ɼӼ��˳�������
	//test01();

	// ʹ�ö�̬������Ʒ
	//doWork(new Coffee, "coffee");
	//doWork(new Tea, "tea");
	

	// �����̨���Ե���װ����
	/*assembly(new IntelCPU, new IntelVideoCard, new IntelMemory);
	assembly(new LenovoCPU, new LenovoVideoCard, new LenovoMemory);
	assembly(new IntelCPU, new LenovoVideoCard, new IntelMemory);*/

	//return 0;
//}



// �ļ�����:
int main() {
	cout << ios::in << endl;				//1             0000 0001
	cout << ios::out << endl;				//2				0000 0010
	cout << ios::ate << endl;				//4				0000 0100
	cout << ios::app << endl;			//8					0000 1000
	cout << ios::trunc << endl;			//16				0001 0000
	cout << ios::binary << endl;			//32			0010 0000
	cout << (ios::in | ios::binary) << endl;			//33        | λ��������������൱��ʵ���˼ӷ��Ĳ���


	// 1. ����ͷ�ļ�   #include <fstream>

	// 2. ���������� ����д����д�ļ�������
	ofstream ofs;    //д�ļ�������   output
	//ifstream ifs;	 //���ļ�������		input
	//fstream fs;		 //��д�ļ�������	output & input

	// 3. ���ļ� �������ļ�·�� �� �ļ��򿪷�ʽ��  
	ofs.open("./test.txt", ios::out);
	
	// 4. ִ����Ӧ�ļ�����
	ofs << "This is a test!" << endl;
	ofs << "This is a test2!" << endl;
	ofs << "This is a test3!" << endl;

	// 5.ִ����Ϻ�ǵùر��ļ�
	ofs.close();


	ifstream ifs;
	ifs.open("./test.txt", ios::in);
	string buf;
	while (getline(ifs, buf)) {   //��ȡһ�� �����ȡ���з� \n
		cout << buf <<endl;
	};

	cout << buf << endl;
	//
	//cout << "It's over!" << endl;
	ifs.close();



	return 0;
}