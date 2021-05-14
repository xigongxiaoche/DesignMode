#include<iostream>
using namespace std;

//���󹤳�ģʽ
/*
	��Ʒ�ȼ��ṹ����Ʒ�ȼ��ṹ����Ʒ�ļ̳нṹ
	��Ʒ�壺
		�ڳ��󹤳�ģʽ�У���Ʒ����ָ��ͬһ�����������ģ�
		λ�ڲ�ͬ��Ʒ�ȼ��ṹ�е�һ���Ʒ

	���󹤳�ģʽ��Բ�Ʒ�壬��������Բ�Ʒ�ȼ��ṹ
*/
/*
	����һ�����󹤳��࣬������ж���һЩ������ͬ����Ĵ��麯����
	���幤����̳г��󹤳��࣬����д���麯��

	���󹤳�ģʽ�����Ͽ���ԭ��
*/

//����ƻ����
class AbstractApple{
public:
	virtual void showName() = 0;
};


//�й�ƻ����
class ChinaApple :public AbstractApple{
public:
	virtual void showName()
	{
		cout << "�й�ƻ��" << endl;
	}
};

//����ƻ����
class AmericanApple :public AbstractApple{
public:
	virtual void showName()
	{
		cout << "����ƻ��" << endl;
	}
};

//�ձ�ƻ����
class JapanApple :public AbstractApple{
public:
	virtual void showName()
	{
		cout << "�ձ�ƻ��" << endl;
	}
};

//����������
class AbstractOrange{
public:
	virtual void showName() = 0;
};



//�й�������
class ChinaOrange:public AbstractOrange{
public:
	virtual void showName()
	{
		cout << "�й�����" << endl;
	}
};

//����������
class AmericanOrange :public AbstractOrange{
public:
	virtual void showName()
	{
		cout << "��������" << endl;
	}
};

//�ձ�������
class JapanOrange :public AbstractOrange{
public:
	virtual void showName()
	{
		cout << "�ձ�����" << endl;
	}
};

//�����㽶��
class AbstractBanana{
public:
	virtual void showName() = 0;
};

//�й��㽶��
class ChinaBanana:public AbstractBanana{
public:
	virtual void showName()
	{
		cout << "�й��㽶" << endl;
	}
};

//�����㽶��
class AmericanBanana :public AbstractBanana{
public:
	virtual void showName()
	{
		cout << "�����㽶" << endl;
	}
};


//�ձ��㽶��
class JapanBanana :public AbstractBanana{
public:
	virtual void showName()
	{
		cout << "�ձ��㽶" << endl;
	}
};





//���󹤳���
class AbstractFactory{
public:
	virtual AbstractApple* appleCreate() = 0;
	virtual AbstractOrange* orangeCreate() = 0;
	virtual AbstractBanana* bananaCreate() = 0;
};

//�й�������
class ChinaFactory :public AbstractFactory{
public:
	virtual AbstractApple* appleCreate()
	{
		return new ChinaApple;
	}
	virtual AbstractOrange* orangeCreate()
	{
		return new ChinaOrange;
	}
	virtual AbstractBanana* bananaCreate()
	{
		return new ChinaBanana;
	}
};


//����������
class AmericanFactory :public AbstractFactory{
public:
	virtual AbstractApple* appleCreate()
	{
		return new AmericanApple;
	}
	virtual AbstractOrange* orangeCreate()
	{
		return new AmericanOrange;
	}
	virtual AbstractBanana* bananaCreate()
	{
		return new AmericanBanana;
	}
};

//�ձ�������
class JapanFactory :public AbstractFactory{
public:
	virtual AbstractApple* appleCreate()
	{
		return new JapanApple;
	}
	virtual AbstractOrange* orangeCreate()
	{
		return new JapanOrange;
	}
	virtual AbstractBanana* bananaCreate()
	{
		return new JapanBanana;
	}
};

//�ͻ���
void test()
{
	AbstractFactory* factory = nullptr;
	AbstractApple* apple = nullptr;
	AbstractOrange* orange = nullptr;
	AbstractBanana* banana = nullptr;

	//�й�����
	factory = new ChinaFactory;
	apple=factory->appleCreate();
	orange = factory->orangeCreate();
	banana = factory->bananaCreate();
	
	cout << "�й�����:" << endl;
	apple->showName();
	orange->showName();
	banana->showName();
	cout << "----------------------------------------" << endl;

	delete banana;
	delete orange;
	delete apple;
	delete factory;

	//��������
	factory = new AmericanFactory;
	apple = factory->appleCreate();
	orange = factory->orangeCreate();
	banana = factory->bananaCreate();

	cout << "��������:" << endl;
	apple->showName();
	orange->showName();
	banana->showName();
	cout << "----------------------------------------" << endl;

	delete banana;
	delete orange;
	delete apple;
	delete factory;

	//�ձ�����
	factory = new JapanFactory;
	apple = factory->appleCreate();
	orange = factory->orangeCreate();
	banana = factory->bananaCreate();

	cout << "�ձ�����:" << endl;
	apple->showName();
	orange->showName();
	banana->showName();
	cout << "----------------------------------------" << endl;

	delete banana;
	delete orange;
	delete apple;
	delete factory;
}


int main()
{
	test();
	return 0;
}