#include<iostream>
/*
	�ϳɸ���ԭ�򣺼̳к��������ʹ�����
*/

using namespace std;
//������
class  AbstractCar{
public:
	virtual void run() = 0;
};

//���ڳ���
class Dazhong :public AbstractCar{
public:
	virtual void run()
	{
		cout << "����������....." << endl;
	}
};


//������
class BenChi:public AbstractCar{
public:
	virtual void run()
	{
		cout << "����������....." << endl;
	}
};

//�����ٹ���
class WuLingRongGuang :public AbstractCar{
public:
	virtual void run()
	{
		cout << "����֮���������ٹ⣬�𺳵ǳ���������....." << endl;
	}
};


////��ʹ�ü̳�ʱ�����뿪��ͬ�ĳ�����Ҫ�̳в�ͬ�ľ���ĳ���
////��Ծ����࣬���ʺ�ʹ�ü̳�
//class PersonA :public Dazhong{
//public:
//	void DouFeng()
//	{
//		run();
//	}
//};
//
//class PersonB :public BenChi{
//public:
//	void DouFeng()
//	{
//		run();
//	}
//};
//void test()
//{
//	PersonA p;
//	p.DouFeng();
//	PersonB p2;
//	p2.DouFeng();
//}


//��������һ����������
class Person{
public:
	void setCar(AbstractCar* car)
	{
		_car = car;
	}
	void DouFeng()
	{
		_car->run();
		if (_car != NULL)
		{
			delete _car;
			_car = NULL;
		}
	}
	AbstractCar* _car;
};

void test()
{
	Person a;
	a.setCar(new WuLingRongGuang);
	a.DouFeng();
	a.setCar(new Dazhong);
	a.DouFeng();
}

int main()
{
	test();
	return 0;
}