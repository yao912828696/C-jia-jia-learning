#include "workerManager.h"

void WorkerManager::showMenu() {
	cout << "********************************************" << endl;
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void WorkerManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	exit(0);
}

void WorkerManager::showWorker() {
	if (m_cap) {
		cout << "ְ�����\t" << "ְ������\t" << "ְ����λ\t" << endl;
		cout << "--------------------------------------------------" << endl;
		for (int i = 0;i < m_cap;i++) {
			m_p[i]->showInfo();
		}
	}
	else {
		cout << "�ļ�Ϊ��" << endl;
	}
}

void WorkerManager::addWorker() {
	//Worker** wkary
	int num = 0;
	while (true) {
		cout << "������ӵ�Ա����������";
		cin >> num;
		// �������� ���¿���һ������ռ�
		//m_p = new Worker * [m_cap + num];  //����ֱ����m_p���� �Ḳ�ǵ�֮ǰ���������� �����޷�ʹ�ú��޷��ͷ�
		Worker** new_p = new Worker * [m_cap + num];
		//��֮ǰ����Ǩ�ƹ���
		for (int i = 0;i < m_cap;i++) {
			new_p[i] = m_p[i];
		}
		delete[] m_p;
		m_p = NULL;
		//�������
		if (num >= 1 && num <= 10) {
			for (int i = 0;i < num;i++) {
				int id = 0;
				string name = "";
				int dSelect = 0;

				cout << "������� " << i + 1 << " ����ְ����ţ�" << endl;
				cin >> id;


				cout << "������� " << i + 1 << " ����ְ��������" << endl;
				cin >> name;


				cout << "��ѡ��Ա���ĸ�λ��" << endl;
				cout << "1����ְͨ��" << endl;
				cout << "2������" << endl;
				cout << "3���ϰ�" << endl;
				cin >> dSelect;
				Worker* worker = NULL;
				switch (dSelect)
				{
				case 1: //��ͨԱ��
					worker = new Employee(id, name);
					break;
				case 2: //����
					worker = new Manager(id, name);
					break;
				case 3:  //�ϰ�
					worker = new Boss(id, name);
					break;
				default:
					break;
				}
				new_p[m_cap + i] = worker;

			}
			//��ʾ��Ϣ
			cout << "�ɹ����" << num << "����ְ����" << endl;
			//�����Ϻ����ά����Ϣ
			m_cap += num;
			m_p = new_p;
			return;
		}
		else if (num == 0) {
			return;
		}
		else {
			cout << "�����������������:" << endl;
		}
	}
}

void WorkerManager::save() {
	if (m_cap) {
		ofstream ofs;
		ofs.open(FILEPATH, ios::out);
		
		for (int i = 0; i < m_cap; i++)
		{
			ofs << this->m_p[i]->m_id << " "
				<< this->m_p[i]->m_name << " "
				<< this->m_p[i]->m_did << endl;
		}
		
		ofs.close();
	}
}

int WorkerManager::isExsit(int id) {
	if (m_p)
		for (int i = 0;i < m_cap;i++) 
			if (id == m_p[i]->m_id)
				return i;
	return -1;
}  //����Ա��id����Ա�������� Worker* ָ�������±�  ��û�ҵ�����-1

void WorkerManager::deleteWorker() {
	int id = 0;
	cout << "��������Ҫɾ��Ա���ı�ţ�";
	cin >> id;
	int index = isExsit(id);
	if (index != -1) {
		delete m_p[index];
		for (int i = index;i < m_cap;i++) {
			m_p[index] = m_p[index + 1];
		}
		cout << "ɾ���ɹ���" << endl;
		m_cap -= 1;
		return;
	}
	cout << "���޴��ˣ�ɾ��ʧ��" << endl;
}

void WorkerManager::findWorker() {
	int id = 0;
	cout << "��������Ҫ����Ա���ı�ţ�";
	cin >> id;
	int index = isExsit(id);
	if (index != -1) {
		cout << "Ա��id��" << m_p[index]->m_id
			<< "\tԱ��������" << m_p[index]->m_name
			<< "\tԱ����λ��" << m_p[index]->getDeptName()
			<< endl;
		return;
	}
	cout << "���޴���" << endl;
}

void WorkerManager::updateWorker() {
	int id = 0;
	cout << "��������Ҫ����Ա���ı�ţ�";
	cin >> id;
	int index = isExsit(id);
	if (index != -1) {
		int id = 0;
		string name = "";
		int dSelect = 0;

		cout << "��������ְ����ţ�" << endl;
		cin >> id;
		cout << "��������ְ��������" << endl;
		cin >> name;
		cout << "��ѡ��Ա���ĸ�λ��" << endl;
		cout << "1����ְͨ��" << endl;
		cout << "2������" << endl;
		cout << "3���ϰ�" << endl;
		cin >> dSelect;
		Worker* worker = NULL;
		switch (dSelect)
		{
		case 1: //��ͨԱ��
			worker = new Employee(id, name);
			break;
		case 2: //����
			worker = new Manager(id, name);
			break;
		case 3:  //�ϰ�
			worker = new Boss(id, name);
			break;
		default:
			break;
		}
		cout << "���³ɹ���" << endl;
		delete m_p[index];
		m_p[index] = worker;
		return;
	}
	cout << "���޴���" << endl;
}

void WorkerManager::clean() {
	string confirm = "";
	cout << "ȷ�������� Y����������������˳���գ�";
	cin >> confirm;
	if (confirm == "Y") {
		if (m_p) {
			for (int i = 0;i < m_cap;i++) {
				delete m_p[i];
				m_p[i] = NULL;
			}
			delete[] m_p;
			ofstream ofs;
			ofs.open(FILEPATH, ios::trunc);
			ofs.close();
			cout << "�ļ���ճɹ���" << endl;
			return;
		}
		cout << "�ļ������ڻ�Ϊ��" << endl;
	}
}

int WorkerManager::getNum()
{
	ifstream ifs;
	ifs.open(FILEPATH, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		//��¼����
		num++;
	}
	ifs.close();

	return num;
}

void WorkerManager::init()
{
	ifstream ifs;
	ifs.open(FILEPATH, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	m_p = new Worker * [getNum()];
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		//���ݲ�ͬ�Ĳ���Id������ͬ����
		if (dId == 1)  // 1��ͨԱ��
		{
			worker = new Employee(id, name);
		}
		else if (dId == 2) //2����
		{
			worker = new Manager(id, name);
		}
		else //�ܲ�
		{
			worker = new Boss(id, name);
		}
		//�����������
		this->m_p[index] = worker;
		index++;
	}
	m_cap = index;
}

// sort
//����ְ��
void WorkerManager::sort()
{
	if (m_cap==0)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ�� " << endl;
		cout << "1����ְ���Ž�������" << endl;
		cout << "2����ְ���Ž��н���" << endl;

		int select = 0;
		cin >> select;


		for (int i = 0; i < m_cap; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < m_cap; j++)
			{
				if (select == 1) //����
				{
					if (m_p[minOrMax]->m_id > m_p[j]->m_id)
					{
						minOrMax = j;
					}
				}
				else  //����
				{
					if (m_p[minOrMax]->m_id < m_p[j]->m_id)
					{
						minOrMax = j;
					}
				}
			}

			if (i != minOrMax)
			{
				Worker* temp = m_p[i];
				m_p[i] = m_p[minOrMax];
				m_p[minOrMax] = temp;
			}

		}

		cout << "����ɹ�,�������Ϊ��" << endl;
		this->save();
		this->showWorker();
	}

}
//���캯��
WorkerManager::WorkerManager(){
	ifstream ifs;
	ifs.open(FILEPATH, ios::in);

	//�ļ����������
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl; //�������
		this->m_cap = 0;  //��ʼ������
		this->m_fileIsEmpty = true; //��ʼ���ļ�Ϊ�ձ�־
		this->m_p = NULL; //��ʼ������
		ifs.close(); //�ر��ļ�
		return;
	}
	
	
	//�ļ����ڣ�����û�м�¼
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��!" << endl;
		this->m_cap = 0;
		this->m_fileIsEmpty = true;
		this->m_p = NULL;
		ifs.close();
		return;
	}
	
	
	//�ļ����ڣ����м�¼
	init();

}

//��������
WorkerManager::~WorkerManager(){
	if (m_p) {
		for (int i = 0;i < m_cap;i++) {
			delete m_p[i];
			m_p[i] = NULL;
		}
		delete[] m_p;
	}
}
