#include<iostream>
using namespace std;

/*
	����ģʽ��
		һ����ֻ����һ��ʵ�������󣬲��ṩһ���ӿڽ��з��ʣ�
		һ����Դֻ�����ڴ���ֻ��һ�ݣ����ܳ��ֶ�ݣ�

	ʵ�ֵ����Ĳ��裺
	1.���캯��˽�л���
	2.���Ӿ�̬�ġ�˽�еġ���ǰ���ָ�������
	3.�ṩ��̬�Ķ���ӿڣ����û����Ի�õ�������

	����ģʽ��Ϊ����ʽ�Ͷ���ʽ

	����ʽ����Դ��ʹ��ʱ�ų�ʼ�����أ���ʱ����)
	����ʽ����Դ�ڳ����ʼ���׶���ɼ���(�ռ任ʱ��)
	
	����ʽ�������߳��ǰ�ȫ�ģ�
	����ʽ�������߳��ǲ���ȫ�ģ�
*/


//����ʽ
class SingleTon_lazy{
private:
	//���캯��˽�л���֤һ����ֻ����һ������
	SingleTon_lazy()
	{
		cout << "��������ʽ����ģʽ" << endl;
	}

public:
	//����������Ϊ��̬���Ϳ���ͨ����������
	static SingleTon_lazy* getInstance()
	{
		//û�оʹ���
		if (object == nullptr)
		{
			object = new SingleTon_lazy;
		}
		return object;
	}

private:
	static SingleTon_lazy* object;	//��̬���α�֤��Դֻ��һ�ݣ�������������г�ʼ��
};

//�����ʼ��
SingleTon_lazy* SingleTon_lazy::object = nullptr;


//����ʽ
class SingleTon_hunger{
private:
	//���캯��˽�л���֤һ����ֻ����һ������
	SingleTon_hunger()
	{
		cout << "���Ƕ���ʽ����ģʽ" << endl;
	}

public:
	//����������Ϊ��̬���Ϳ���ͨ����������
	static SingleTon_hunger* getInstance()
	{
		return object;
	}

	//����ʽ����ģʽ��Դ���ͷ�
	class Garbo{
		~Garbo()
		{
			if (object != nullptr)
			{
				delete object;
			}
		}
	};
private:
	static SingleTon_hunger* object;
	static Garbo garbo;
};

//�����ʼ��ʱ��������
SingleTon_hunger* SingleTon_hunger::object = new SingleTon_hunger;



//void test()
//{
//	cout << "���ǿͻ���" << endl;
//	SingleTon_lazy::getInstance();
//}

void test()
{
	SingleTon_hunger* p = SingleTon_hunger::getInstance();
	SingleTon_hunger* p2 = SingleTon_hunger::getInstance();
	if (p == p2)
	{
		cout << "����ָ��ָ��ͬһ���ڴ棬�Ƕ�������ģʽ!" << endl;
	}
	else
	{
		cout << "���ǵ���ģʽ" << endl;
	}

	SingleTon_lazy* p3 = SingleTon_lazy::getInstance();
	SingleTon_lazy* p4 = SingleTon_lazy::getInstance();
	if (p3 == p4)
	{
		cout << "����ָ��ָ��ͬһ���ڴ棬����������ģʽ!" << endl;
	}
	else
	{
		cout << "���ǵ���ģʽ" << endl;
	}

}

int main()
{
	test();
	return 0;
}