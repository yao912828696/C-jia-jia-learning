#include "workerManager.h"

void test() {
	//Worker* worker = NULL;
	//worker = new Employee(1, "����");    //����ָ������������
	//worker->showInfo();
	//delete worker;
	
	/*worker = new Manager(2, "����");
	worker->showInfo();
	delete worker;

	worker = new Boss(3, "����");
	worker->showInfo();
	delete worker;*/
	
	exit(0);

}

int main() {
	//test();
	WorkerManager wm;

	int select = 0;
	while (true) {
		wm.showMenu();
		cout << "���������ѡ��";
		cin >> select;
		switch (select) {
		case 0: //�˳�ϵͳ
			wm.exitSystem();
			break;
		case 1: //���ְ��
			wm.addWorker();
			wm.save();
			break;
		case 2: //��ʾְ��
			wm.showWorker();
			break;
		case 3: //ɾ��ְ��
			wm.deleteWorker();
			wm.save();
			break;
		case 4: //�޸�ְ��
			wm.updateWorker();
			wm.save();
			break;
		case 5: //����ְ��
			wm.findWorker();
			break;
		case 6: //����ְ��
			wm.sort();
			break;
		case 7: //����ļ�
			wm.clean();
			break;
		default:
			break;
		}
		system("pause");
		system("cls");
	}




	return 0;
}