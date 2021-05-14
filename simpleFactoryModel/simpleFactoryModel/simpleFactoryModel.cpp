#include<iostream>
#include<string>
using namespace std;
//简单工厂模式：不想创建对象，只想使用这个对象
//优点:
//    客户端和具体实现类分离；
//    不用考虑创建某些复杂对象的情况
//缺点：
//    增加新功能是通过修改源代码实现，不符合开闭原则
//    工厂类职责过重，工厂类出现问题，会影响很多使用这个工厂的模块

//注意：简单工厂模式不属于23种设计模式
/*
	适用场景：
		1.工厂类负责创建的对象比较少，由于创建的对象比较少，
		  不会造成工厂方法中的业务逻辑太过复杂；
		2.客户端只知道传入工厂类的参数，对于如何创建并不关心；
*/

//抽象水果类
class AbstractFruit{
public:
	virtual void showName() = 0;
};

class Apple :public AbstractFruit{
public:
	virtual void showName()
	{
		cout << "我是一个苹果" << endl;
	}
};

class Banana :public AbstractFruit{
public:
	virtual void showName()
	{
		cout << "我是一个香蕉" << endl;
	}
};

class Orange :public AbstractFruit{
public:
	virtual void showName()
	{
		cout << "我是一个橘子" << endl;
	}
};


class Peach :public AbstractFruit{
public:
	virtual void showName()
	{
		cout << "我是一个桃子" << endl;
	}
};
//水果工厂
class FruitFactory{
public:
	AbstractFruit* FruitCreate(string name)
	{
		if (name == "apple")
		{
			return new Apple;
		}
		else if (name == "banana")
		{
			return new Banana;
		}
		else if (name == "orange")
		{
			return new Orange;
		}
		else if (name == "peach")
		{
			return new Peach;
		}
		else
		{
			return NULL;
		}
	}
};

//客户端不和具体的类交互，而是和工厂类进行交互
void test()
{
	//创建过程不需要关心，直接拿来用
	FruitFactory* factory=new FruitFactory;
	AbstractFruit* fruit = factory->FruitCreate("apple");
	fruit->showName();
	delete fruit;
	fruit = NULL;

	fruit = factory->FruitCreate("banana");
	fruit->showName();
	delete fruit;
	fruit = NULL;

	fruit = factory->FruitCreate("orange");
	fruit->showName();
	delete fruit;
	fruit = NULL;

	fruit = factory->FruitCreate("peach");
	fruit->showName();
	delete fruit;
	fruit = NULL;

	/*fruit = factory->FruitCreate("pear");
	fruit->showName();
	delete fruit;
	fruit = NULL;*/

	delete factory;
	factory = NULL;
}
int main()
{
	test();
	return 0;
}