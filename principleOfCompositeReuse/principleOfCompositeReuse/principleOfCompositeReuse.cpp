#include<iostream>
/*
	合成复用原则：继承和组合优先使用组合
*/

using namespace std;
//抽象车类
class  AbstractCar{
public:
	virtual void run() = 0;
};

//大众车类
class Dazhong :public AbstractCar{
public:
	virtual void run()
	{
		cout << "大众启动中....." << endl;
	}
};


//奔驰类
class BenChi:public AbstractCar{
public:
	virtual void run()
	{
		cout << "奔驰启动中....." << endl;
	}
};

//五菱荣光类
class WuLingRongGuang :public AbstractCar{
public:
	virtual void run()
	{
		cout << "车中之王，五菱荣光，震撼登场，启动中....." << endl;
	}
};


////当使用继承时，人想开不同的车就需要继承不同的具体的车类
////针对具体类，不适合使用继承
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


//给人增加一个车的属性
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