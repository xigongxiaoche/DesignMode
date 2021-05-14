#include<iostream>
using namespace std;
/*
	ģ�巽��ģʽ��
		�ڸ����ж���һЩ�㷨�Ŀ�ܣ�
		�������н���ϸ�ڵĴ���

	���Ƕ�C++�̳кͶ�̬��ʹ��
*/

//������
class AbstractDrinkTemplate{
public:
	virtual void BoilWater() = 0;//��ˮ
	virtual void Brew() = 0;//����
	virtual void PourInCup() = 0;//���뱭��
	virtual void AddSomething() = 0;//����

	//������Ʒ
	void make()
	{
		BoilWater();
		Brew();
		PourInCup();
		AddSomething();
	}
};

//���ݿ���
class DrinkCoffee :public AbstractDrinkTemplate{
public:
	//��ˮ
	virtual void BoilWater()
	{
		cout << "�Ϻõ�ɽȪˮ��������" << endl;
	}
	//����
	virtual void Brew()
	{
		cout << "���ݿ���" << endl;
	}
	//���뱭��
	virtual void PourInCup()
	{
		cout << "���ȵ��뱭��" << endl;
	}
	//����
	virtual void AddSomething()
	{
		cout << "����ţ�̺��ǣ����𰡣�" << endl;
	}
};

class DrinkTea:public AbstractDrinkTemplate{
public:
	//��ˮ
	virtual void BoilWater()
	{
		cout << "������˹ɽȪˮ��������" << endl;
	}
	//����
	virtual void Brew()
	{
		cout << "���ݲ�Ҷ" << endl;
	}
	//���뱭��
	virtual void PourInCup()
	{
		cout << "��ˮ���뱭��" << endl;
	}
	//����
	virtual void AddSomething()
	{
		cout << "��������Ƭ������ζŶ��" << endl;
	}
};

void test()
{
	AbstractDrinkTemplate* drink = new DrinkCoffee;
	cout << "����ʱ�̣�" << endl;
	drink->make();
	
	delete drink;
	drink = nullptr;

	drink = new DrinkTea;
	cout << "����ʱ�̣�" << endl;
	drink->make();

	delete drink;
	drink = nullptr;
}
int main()
{
	test();
	return 0;
}