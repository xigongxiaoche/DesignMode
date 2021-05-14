#include<iostream>
using namespace std;
//��ͳ�Ĺ���ʽ��������ڸ߲�ε�ģ�������ڵײ��ģ��
//������תԭ��:ҵ��������ڳ����,������̬ʵ��

////��ͳ�Ĺ���ʽ���
////����ְԱ��
//class BankWorker{
//public:
//	void payService()
//	{
//		cout << "����֧��ҵ����" << endl;
//	}
//	void transferService()
//	{
//		cout << "����ת��ҵ����" << endl;
//	}
//	void saveService()
//	{
//		cout << "������ҵ����" << endl;
//	}
//};
//
////�м�����õײ���
//void doPayBusiness(BankWorker* p)
//{
//	p->payService();
//}
//void doTransferBusiness(BankWorker* p)
//{
//	p->transferService();
//}
//void doSaveBusiness(BankWorker* p)
//{
//	p->saveService();
//}
//
////�߲��������м���
//void test()
//{
//	BankWorker worker;
//	doPayBusiness(&worker);
//	doTransferBusiness(&worker);
//	doSaveBusiness(&worker);
//}

class AbstractWorker{
public:
	virtual void doBusiness() = 0;
};

//ÿ����ֻ���һ������
class payBankWorker :public AbstractWorker{
public:
	virtual void doBusiness()
	{
		cout << "����֧��ҵ��" << endl;
	}
};

class saveBankWorker :public AbstractWorker{
public:
	virtual void doBusiness()
	{
		cout << "������ҵ��" << endl;
	}
};

class transferBankWorker :public AbstractWorker{
public:
	virtual void doBusiness()
	{
		cout << "����ת��ҵ��" << endl;
	}
};

//�м�����ó����࣬����ʹҵ����п���չ��
void doService(AbstractWorker* worker)
{
	worker->doBusiness();
	delete worker;
}

//���߼���������м���
void test()
{
	doService(new payBankWorker);
	doService(new transferBankWorker);
	doService(new saveBankWorker);
}

int main()
{
	test();
	return 0;
}