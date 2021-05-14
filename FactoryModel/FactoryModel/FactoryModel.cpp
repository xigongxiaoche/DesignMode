#include<iostream>
#include<string>
using namespace std;
//��������ģʽ
/*
	����һ�����󹤳��࣬����������̳�������󹤳��࣬
	����д���󹤳���ķ���
	ÿ������һ��Ҫ�����µ��࣬�ʹ���һ������Ĺ�����

	�ŵ㣺���Ͽ���ԭ��
	ȱ�㣺
		1.ÿ��Ҫ����һ���µ���ʱ����Ҫ����һ���µĹ�����,
		  ��ĸ����ɱ����ӣ�������Խ��Խ�࣬������ά���ɱ���
		2.��Ҫ�ͻ��Լ��жϵ����Ǹ����������������

	���ó�����
			1.�ͻ��˲�֪�������������ࣻ
			2.���󹤳���ͨ����������ָ�������ĸ�����
*/
//�򵥹���ģʽ + ����ԭ�� = ��������ģʽ

//����ˮ����
class AbstractFruit{
public:
	virtual void showName() = 0;
};


//����ˮ����
//ƻ����
class Apple :public AbstractFruit{
public:
	virtual void showName()
	{
		cout << "I am apple" << endl;
	}
};

//������
class Orange : public AbstractFruit{
public:
	virtual void showName()
	{
		cout << "I am orange" << endl;
	}
};

//���󹤳���
class AbstractFactory{
public:
	virtual AbstractFruit* FruitCreate() = 0;
};

//���幤����
//ƻ������
class Factory_apple:public AbstractFactory{
public:
	virtual AbstractFruit* FruitCreate()
	{
		return new Apple;
	}
};

//���ӹ���
class Factory_orange :public AbstractFactory{
public:
	virtual AbstractFruit* FruitCreate()
	{
		return new Orange;
	}
};


//�ͻ���ͨ�����󹤳������þ��幤��
void test()
{
	AbstractFactory* factory =NULL;
	AbstractFruit* fruit = NULL;


	//����ƻ������
	factory = new Factory_apple;
	fruit = factory->FruitCreate();
	fruit->showName();
	delete fruit;
	fruit = NULL;
	delete factory;
	factory = NULL;

	//�������ӹ���
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