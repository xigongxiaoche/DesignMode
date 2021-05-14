#include<iostream>
#include<string>
using namespace std;
//工厂方法模式
/*
	定义一个抽象工厂类，再让其他类继承这个抽象工厂类，
	并重写抽象工厂类的方法
	每次生成一个要创建新的类，就创建一个具体的工厂类

	优点：符合开闭原则
	缺点：
		1.每当要增加一个新的类时，就要增加一个新的工厂类,
		  类的个数成倍增加，导致类越来越多，增加了维护成本；
		2.需要客户自己判断调用那个工厂来创建类对象；

	适用场景：
			1.客户端不知道它所需对象的类；
			2.抽象工厂类通过其子类来指定创建哪个对象；
*/
//简单工厂模式 + 开闭原则 = 工厂方法模式

//抽象水果类
class AbstractFruit{
public:
	virtual void showName() = 0;
};


//具体水果类
//苹果类
class Apple :public AbstractFruit{
public:
	virtual void showName()
	{
		cout << "I am apple" << endl;
	}
};

//橘子类
class Orange : public AbstractFruit{
public:
	virtual void showName()
	{
		cout << "I am orange" << endl;
	}
};

//抽象工厂类
class AbstractFactory{
public:
	virtual AbstractFruit* FruitCreate() = 0;
};

//具体工厂类
//苹果工厂
class Factory_apple:public AbstractFactory{
public:
	virtual AbstractFruit* FruitCreate()
	{
		return new Apple;
	}
};

//橘子工厂
class Factory_orange :public AbstractFactory{
public:
	virtual AbstractFruit* FruitCreate()
	{
		return new Orange;
	}
};


//客户端通过抽象工厂来调用具体工厂
void test()
{
	AbstractFactory* factory =NULL;
	AbstractFruit* fruit = NULL;


	//创建苹果工厂
	factory = new Factory_apple;
	fruit = factory->FruitCreate();
	fruit->showName();
	delete fruit;
	fruit = NULL;
	delete factory;
	factory = NULL;

	//创建橘子工厂
	factory = new Factory_orange;
	fruit = factory->FruitCreate();
	fruit->showName();
	delete fruit;
	fruit = NULL;
	delete factory;
	factory = NULL;
}

int main()
{
	test();
	return 0;
}