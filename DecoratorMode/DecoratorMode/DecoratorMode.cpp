#include<iostream>
using namespace std;
/*
	引言：
		一般情况下，通过使用继承来实现对于功能的扩展
*/

/*
	装饰者模式：
	通过一种对客户端透明的方式来扩展对象功能，是一种对继承关系的取代；
	可以动态地给一个类增加功能
*/

//抽象英雄类
class AbstractHero{
public:
	virtual void showStatus() = 0;//展示状态
public:
	int _HP;//血量
	int _MP;//能量
	int _AT;//攻击力
	int _DF;//防御力
};

class HeroA :public AbstractHero{
public:
	HeroA()
	{
		_HP = 0;
		_MP = 0;
		_AT = 0;
		_DF = 0;
	}
	virtual void showStatus()
	{
		cout << "血量：" << _HP << endl;
		cout << "能量：" << _MP << endl;
		cout << "攻击力：" << _AT << endl;
		cout << "防御力：" << _DF << endl;
	}
};

//穿上装备的英雄还是英雄
class AbstractEquipment:public AbstractHero{
public:
	AbstractEquipment(AbstractHero* hero)
	{
		_hero = hero;
		_HP = hero->_HP;
		_MP = hero->_MP;
		_AT = hero->_AT;
		_DF = hero->_DF;
	}
	virtual void showStatus() override {}
public:
	AbstractHero* _hero;
};

//铠甲：狂徒
class KuangTu :public AbstractEquipment{
public:
	KuangTu(AbstractHero* hero)
		:AbstractEquipment(hero)
	{}
	
	//增加额外的功能
	void AddEquipment()
	{
		_DF += 100;

		delete _hero;
	}
	virtual void showStatus()
	{
		cout << "英雄穿上狂徒后：" << endl;
		AddEquipment();
		cout << "血量：" << _HP << endl;
		cout << "能量：" << _MP << endl;
		cout << "攻击力：" << _AT << endl;
		cout << "防御力：" << _DF << endl;
	}
};

//武器：轩辕剑
class XuanYuanJian :public AbstractEquipment{
public:
	XuanYuanJian(AbstractHero* hero)
		:AbstractEquipment(hero)
	{}

	void AddEquipment()
	{
		_AT += 10000;

		delete _hero;
	}

	virtual void showStatus()
	{
		cout << "英雄拿到轩辕剑之后：" << endl;
		AddEquipment();
		cout << "血量：" << _HP << endl;
		cout << "能量：" << _MP << endl;
		cout << "攻击力：" << _AT << endl;
		cout << "防御力：" << _DF << endl;
		
	}
};

//客户端
void test()
{
	AbstractHero* hero = new HeroA;
	cout << "初始状态的英雄:" << endl;
	hero->showStatus();

	hero= new XuanYuanJian(hero);
	hero->showStatus();
	 

	hero = new KuangTu(hero);
	hero->showStatus();

	

}
int main()
{
	test();
	return 0;
}