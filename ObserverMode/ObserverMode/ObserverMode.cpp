#include<iostream>
#include<list>
using namespace std;
/*
	观察者模式：
	一个对象发生改变，自动通知其他对象，其他对象作出反应
*/

//抽象英雄类
class AbstractHero{
public:
	virtual void update() = 0;
};

class HeroA :public AbstractHero
{
public:
	HeroA()
	{
		cout << "英雄A加入打Boss中" << endl;
	}
	virtual void update()
	{
		cout << "英雄A准备抢装备" << endl;
	}
};

class HeroB :public AbstractHero
{
public:
	HeroB()
	{
		cout << "英雄B加入打Boss中" << endl;
	}
	virtual void update()
	{
		cout << "英雄B准备抢装备" << endl;
	}
};

class HeroC :public AbstractHero
{
public:
	HeroC()
	{
		cout << "英雄C加入打Boss中" << endl;
	}
	virtual void update()
	{
		cout << "英雄C准备抢装备" << endl;
	}
};

class HeroD :public AbstractHero
{
public:
	HeroD()
	{
		cout << "英雄D加入打Boss中" << endl;
	}
	virtual void update()
	{
		cout << "英雄D准备抢装备" << endl;
	}
};

class HeroE :public AbstractHero
{
public:
	HeroE()
	{
		cout << "英雄E加入打Boss中" << endl;
	}
	virtual void update()
	{
		cout << "英雄E准备抢装备" << endl;
	}
};

//抽象Boss类
class AbstractBoss{
public:
	virtual void addEnemy(AbstractHero* hero)=0;//添加敌人
	virtual void deleteEnemy(AbstractHero* hero) = 0;//删除敌人
	virtual void notify()=0;//通知所有英雄Boss已阵亡
};


class BossOfLevel1 :public AbstractBoss{
public:
	//添加敌人
	virtual void addEnemy(AbstractHero* hero)
	{
		_enemy.push_back(hero);
	}
	//删除敌人
	virtual void deleteEnemy(AbstractHero* hero)
	{
		list<AbstractHero*>::iterator it = _enemy.begin();
		while (it != _enemy.end())
		{
			if (*it == hero)
			{
				it=_enemy.erase(it);
				break;
			}
			it++;
		}
	}
	//通知所有英雄Boss已阵亡
	virtual void notify()
	{
		list<AbstractHero*>::iterator it = _enemy.begin();
		while (it != _enemy.end())
		{
			(*it)->update();
			it++;
		}
	}
public:
	list<AbstractHero*> _enemy;
};

//客户端
void test()
{
	AbstractBoss* boss = new BossOfLevel1;
	AbstractHero* hero1 = new HeroA;
	AbstractHero* hero2 = new HeroB;
	AbstractHero* hero3 = new HeroC;
	AbstractHero* hero4 = new HeroD;
	AbstractHero* hero5 = new HeroE;

	cout << "众英雄加入打Boss中" << endl;
	boss->addEnemy(hero1);
	boss->addEnemy(hero2);
	boss->addEnemy(hero3);
	boss->addEnemy(hero4);
	boss->addEnemy(hero5);

	cout << "hero2阵亡" << endl;
	boss->deleteEnemy(hero2);

	cout << "Boss阵亡,准备开始抢装备了！！！！" << endl;
	boss->notify();

	delete hero5;
	delete hero4;
	delete hero3;
	delete hero2;
	delete hero1;
	delete boss;

	hero5 = nullptr;
	hero4 = nullptr;
	hero3 = nullptr;
	hero2 = nullptr;
	hero1 = nullptr;
	boss = nullptr;

}
int main()
{
	test();
	return 0;
}