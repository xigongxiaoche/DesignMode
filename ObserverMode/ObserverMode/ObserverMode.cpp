#include<iostream>
#include<list>
using namespace std;
/*
	�۲���ģʽ��
	һ���������ı䣬�Զ�֪ͨ����������������������Ӧ
*/

//����Ӣ����
class AbstractHero{
public:
	virtual void update() = 0;
};

class HeroA :public AbstractHero
{
public:
	HeroA()
	{
		cout << "Ӣ��A�����Boss��" << endl;
	}
	virtual void update()
	{
		cout << "Ӣ��A׼����װ��" << endl;
	}
};

class HeroB :public AbstractHero
{
public:
	HeroB()
	{
		cout << "Ӣ��B�����Boss��" << endl;
	}
	virtual void update()
	{
		cout << "Ӣ��B׼����װ��" << endl;
	}
};

class HeroC :public AbstractHero
{
public:
	HeroC()
	{
		cout << "Ӣ��C�����Boss��" << endl;
	}
	virtual void update()
	{
		cout << "Ӣ��C׼����װ��" << endl;
	}
};

class HeroD :public AbstractHero
{
public:
	HeroD()
	{
		cout << "Ӣ��D�����Boss��" << endl;
	}
	virtual void update()
	{
		cout << "Ӣ��D׼����װ��" << endl;
	}
};

class HeroE :public AbstractHero
{
public:
	HeroE()
	{
		cout << "Ӣ��E�����Boss��" << endl;
	}
	virtual void update()
	{
		cout << "Ӣ��E׼����װ��" << endl;
	}
};

//����Boss��
class AbstractBoss{
public:
	virtual void addEnemy(AbstractHero* hero)=0;//��ӵ���
	virtual void deleteEnemy(AbstractHero* hero) = 0;//ɾ������
	virtual void notify()=0;//֪ͨ����Ӣ��Boss������
};


class BossOfLevel1 :public AbstractBoss{
public:
	//��ӵ���
	virtual void addEnemy(AbstractHero* hero)
	{
		_enemy.push_back(hero);
	}
	//ɾ������
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
	//֪ͨ����Ӣ��Boss������
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

//�ͻ���
void test()
{
	AbstractBoss* boss = new BossOfLevel1;
	AbstractHero* hero1 = new HeroA;
	AbstractHero* hero2 = new HeroB;
	AbstractHero* hero3 = new HeroC;
	AbstractHero* hero4 = new HeroD;
	AbstractHero* hero5 = new HeroE;

	cout << "��Ӣ�ۼ����Boss��" << endl;
	boss->addEnemy(hero1);
	boss->addEnemy(hero2);
	boss->addEnemy(hero3);
	boss->addEnemy(hero4);
	boss->addEnemy(hero5);

	cout << "hero2����" << endl;
	boss->deleteEnemy(hero2);

	cout << "Boss����,׼����ʼ��װ���ˣ�������" << endl;
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