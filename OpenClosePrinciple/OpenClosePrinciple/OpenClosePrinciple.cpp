#include<iostream>
#include<string>


/*
����ԭ�򣬶���չ���ţ����޸Ĺرգ�
���ӹ�����ͨ�����Ӵ�����ʵ�ֵģ�������ͨ���޸�Դ������ʵ�ֵ�
*/
//class Caculator{
//public:
//	Caculator(int param1,int param2,std::string oper)
//		:_param1(param1)
//		, _param2(param2)
//		, _oper(oper)
//	{}
//
//	int getRes()
//	{
//		if (_oper.compare("+") == 0)
//			return _param1 + _param2;
//		if (_oper.compare("-") == 0)
//			return _param1 - _param2;
//		if (_oper.compare("*") == 0)
//			return _param1 * _param2;
//		if (_oper.compare("/") == 0)
//			return _param1 / _param2;
//	}
//private:
//	int _param1;
//	int _param2;
//	std::string _oper;
//	int res;
//};
///*
//	���������Caculator�࣬���Ҫ�����µ����㣬��Ҫ�޸�getRes������
//	����������¹��ܵ�ʱ��Ҫ�޸�Դ���룬��ô�ͻ����޸ĳ���Ŀ��ܡ�
//	�����������µĹ��ܵ�ʱ�򣬲���Ӱ�������Ѿ���ɵĹ��ܣ�
//	����Ƕ��޸Ĺرգ�����չ���ţ���������ԭ��
//*/

//void test()
//{
//	Caculator c(10, 2, "*");
//	int res = c.getRes();
//	std::cout << res << std::endl;
//}

//�����������
class AbstractCaculator{
public:
	virtual void setOperatorNumber(int num1, int num2) = 0;
	virtual int getResult() = 0;
};

//�ӷ���������
class PlusCaculator:public AbstractCaculator{
public:
	virtual void setOperatorNumber(int num1, int num2)
	{
		_num1 = num1;
		_num2 = num2;
	}
	virtual int getResult()
	{
		return _num1 + _num2;
	}
private:
	int _num1;
	int _num2;
};

//������������
class MinusCaculator :public AbstractCaculator{
public:
	virtual void setOperatorNumber(int num1, int num2)
	{
		_num1 = num1;
		_num2 = num2;
	}
	virtual int getResult()
	{
		return _num1 - _num2;
	}
private:
	int _num1;
	int _num2;
};

//�˷���������
class MutiplyCaculator :public AbstractCaculator{
public:
	virtual void setOperatorNumber(int num1, int num2)
	{
		_num1 = num1;
		_num2 = num2;
	}
	virtual int getResult()
	{
		return _num1 * _num2;
	}
private:
	int _num1;
	int _num2;
};

//������������
class DivideCaculator :public AbstractCaculator{
public:
	virtual void setOperatorNumber(int num1, int num2)
	{
		_num1 = num1;
		_num2 = num2;
	}
	virtual int getResult()
	{
		return _num1 / _num2;
	}
private:
	int _num1;
	int _num2;
};

//ָ����������
class PowCaculator :public AbstractCaculator{
public:
	virtual void setOperatorNumber(int num1, int num2)
	{
		_num1 = num1;
		_num2 = num2;
	}
	virtual int getResult()
	{
		int res = 1;
		for (int i = 0; i < _num2; ++i)
		{
			res *= _num1;
		}
		return res;
	}
private:
	int _num1;
	int _num2;
};
void test()
{
	AbstractCaculator* p=new PowCaculator;
	p->setOperatorNumber(2, 10);
	std::cout << "result:" << p->getResult() << std::endl;
	delete p;
}
int main()
{
	test();
	return 0;
}