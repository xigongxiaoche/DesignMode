#include<iostream>
using namespace std;
//传统的过程式设计倾向于高层次的模块依赖于底层的模块
//依赖倒转原则:业务层依赖于抽象层,依赖多态实现

////传统的过程式设计
////银行职员类
//class BankWorker{
//public:
//	void payService()
//	{
//		cout << "办理支付业务中" << endl;
//	}
//	void transferService()
//	{
//		cout << "办理转账业务中" << endl;
//	}
//	void saveService()
//	{
//		cout << "办理存款业务中" << endl;
//	}
//};
//
////中间类调用底层类
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
////高层次类调用中间类
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

//每个类只完成一个功能
class payBankWorker :public AbstractWorker{
public:
	virtual void doBusiness()
	{
		cout << "办理支付业务" << endl;
	}
};

class saveBankWorker :public AbstractWorker{
public:
	virtual void doBusiness()
	{
		cout << "办理存款业务" << endl;
	}
};

class transferBankWorker :public AbstractWorker{
public:
	virtual void doBusiness()
	{
		cout << "办理转账业务" << endl;
	}
};

//中间类调用抽象类，可以使业务具有可扩展性
void doService(AbstractWorker* worker)
{
	worker->doBusiness();
	delete worker;
}

//更高级的类调用中间类
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