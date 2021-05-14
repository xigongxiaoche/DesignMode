#include<iostream>
#include<string>
using namespace std;
//�򵥹���ģʽ�����봴������ֻ��ʹ���������
//�ŵ�:
//    �ͻ��˺;���ʵ������룻
//    ���ÿ��Ǵ���ĳЩ���Ӷ�������
//ȱ�㣺
//    �����¹�����ͨ���޸�Դ����ʵ�֣������Ͽ���ԭ��
//    ������ְ����أ�������������⣬��Ӱ��ܶ�ʹ�����������ģ��

//ע�⣺�򵥹���ģʽ������23�����ģʽ
/*
	���ó�����
		1.�����ฺ�𴴽��Ķ���Ƚ��٣����ڴ����Ķ���Ƚ��٣�
		  ������ɹ��������е�ҵ���߼�̫�����ӣ�
		2.�ͻ���ֻ֪�����빤����Ĳ�����������δ����������ģ�
*/

//����ˮ����
class AbstractFruit{
public:
	virtual void showName() = 0;
};

class Apple :public AbstractFruit{
public:
	virtual void showName()
	{
		cout << "����һ��ƻ��" << endl;
	}
};

class Banana :public AbstractFruit{
public:
	virtual void showName()
	{
		cout << "����һ���㽶" << endl;
	}
};

class Orange :public AbstractFruit{
public:
	virtual void showName()
	{
		cout << "����һ������" << endl;
	}
};


class Peach :public AbstractFruit{
public:
	virtual void showName()
	{
		cout << "����һ������" << endl;
	}
};
//ˮ������
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

//�ͻ��˲��;�����ཻ�������Ǻ͹�������н���
void test()
{
	//�������̲���Ҫ���ģ�ֱ��������
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