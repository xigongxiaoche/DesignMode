#include<iostream>
using namespace std;
/*
	���ԣ�
		һ������£�ͨ��ʹ�ü̳���ʵ�ֶ��ڹ��ܵ���չ
*/

/*
	װ����ģʽ��
	ͨ��һ�ֶԿͻ���͸���ķ�ʽ����չ�����ܣ���һ�ֶԼ̳й�ϵ��ȡ����
	���Զ�̬�ظ�һ�������ӹ���
*/

//����Ӣ����
class AbstractHero{
public:
	virtual void showStatus() = 0;//չʾ״̬
public:
	int _HP;//Ѫ��
	int _MP;//����
	int _AT;//������
	int _DF;//������
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
		cout << "Ѫ����" << _HP << endl;
		cout << "������" << _MP << endl;
		cout << "��������" << _AT << endl;
		cout << "��������" << _DF << endl;
	}
};

//����װ����Ӣ�ۻ���Ӣ��
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

//���ף���ͽ
class KuangTu :public AbstractEquipment{
public:
	KuangTu(AbstractHero* hero)
		:AbstractEquipment(hero)
	{}
	
	//���Ӷ���Ĺ���
	void AddEquipment()
	{
		_DF += 100;

		delete _hero;
	}
	virtual void showStatus()
	{
		cout << "Ӣ�۴��Ͽ�ͽ��" << endl;
		AddEquipment();
		cout << "Ѫ����" << _HP << endl;
		cout << "������" << _MP << endl;
		cout << "��������" << _AT << endl;
		cout << "��������" << _DF << endl;
	}
};

//��������ԯ��
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
		cout << "Ӣ���õ���ԯ��֮��" << endl;
		AddEquipment();
		cout << "Ѫ����" << _HP << endl;
		cout << "������" << _MP << endl;
		cout << "��������" << _AT << endl;
		cout << "��������" << _DF << endl;
		
	}
};

//�ͻ���
void test()
{
	AbstractHero* hero = new HeroA;
	cout << "��ʼ״̬��Ӣ��:" << endl;
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