#include<iostream>
using namespace std;
/*
	模板方法模式：
		在父类中定义一些算法的框架，
		在子类中进行细节的处理

	就是对C++继承和多态的使用
*/

//抽象类
class AbstractDrinkTemplate{
public:
	virtual void BoilWater() = 0;//煮水
	virtual void Brew() = 0;//冲泡
	virtual void PourInCup() = 0;//倒入杯中
	virtual void AddSomething() = 0;//加料

	//制作饮品
	void make()
	{
		BoilWater();
		Brew();
		PourInCup();
		AddSomething();
	}
};

//冲泡咖啡
class DrinkCoffee :public AbstractDrinkTemplate{
public:
	//煮水
	virtual void BoilWater()
	{
		cout << "上好的山泉水，加热中" << endl;
	}
	//冲泡
	virtual void Brew()
	{
		cout << "冲泡咖啡" << endl;
	}
	//倒入杯中
	virtual void PourInCup()
	{
		cout << "咖啡倒入杯中" << endl;
	}
	//加料
	virtual void AddSomething()
	{
		cout << "加入牛奶和糖，好甜啊！" << endl;
	}
};

class DrinkTea:public AbstractDrinkTemplate{
public:
	//煮水
	virtual void BoilWater()
	{
		cout << "阿尔卑斯山泉水，加热中" << endl;
	}
	//冲泡
	virtual void Brew()
	{
		cout << "冲泡茶叶" << endl;
	}
	//倒入杯中
	virtual void PourInCup()
	{
		cout << "茶水倒入杯中" << endl;
	}
	//加料
	virtual void AddSomething()
	{
		cout << "加入柠檬片，更美味哦！" << endl;
	}
};

void test()
{
	AbstractDrinkTemplate* drink = new DrinkCoffee;
	cout << "咖啡时刻：" << endl;
	drink->make();
	
	delete drink;
	drink = nullptr;

	drink = new DrinkTea;
	cout << "饮茶时刻：" << endl;
	drink->make();

	delete drink;
	drink = nullptr;
}
int main()
{
	test();
	return 0;
}