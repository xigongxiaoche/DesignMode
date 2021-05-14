#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	������ģʽ����������Ҫ��Ľӿ�ת��Ϊ��Ҫ�Ľӿ�
	�����ڳ������ת��ͷ����220v�ĵ�ѹת��Ϊ�ֻ��ܹ����ܵĵ�ѹ
*/

//�º�����
struct MyPrint{
	void operator()(int arg1,int arg2)
	{
		cout << arg1 << "+" << arg2 << "=" << arg1 + arg2 << endl;
	}
};

//����Ŀ��ӿڣ��涨�����Ľӿ�����
class AbstractTarget{
public:
	virtual void operator()(int arg1) = 0;
};


////��������,����������
//class Adapter :public AbstractTarget{
//public:
//	virtual void operator()(int arg1)
//	{
//		_myprint(arg1,100);//������������
//	}
//public:
//	MyPrint _myprint;
//};	


////�ͻ���1
//void test()
//{
//	vector<int> v;
//	for (int i = 0; i < 11; ++i)
//	{
//		v.push_back(i);
//	}
//
//	//��begin��ʼ��end������Adapter����º���
//	for_each(v.begin(), v.end(), Adapter());
//}

//������ģʽ���Ľ���
class Adapter :public AbstractTarget{
public:
	Adapter(int arg)
	{
		_arg = arg;
	}
	virtual void operator()(int arg1)
	{
		_myprint(arg1,_arg);
	}
public:
	MyPrint _myprint;
	int _arg;
};

Adapter myBind2nd(int arg)
{
	return Adapter(arg);
}

//�ͻ���02:����һ�������Ϳ�����ɴ�������������Ч��
void test()
{
	vector<int> v;
	for (int i = 0; i < 11; ++i)
	{
		v.push_back(i);
	}
	
	//��begin��ʼ��end������Adapter����º���
	//������������һ���Ǵ����1024����һ���ǵ�����ָ�������
	for_each(v.begin(), v.end(), myBind2nd(1024));
}
int main()
{
	test();
	return 0;
}