#include<iostream>
#include<string>


/*
开闭原则，对扩展开放，对修改关闭，
增加功能是通过增加代码来实现的，而不是通过修改源代码来实现的
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
//	对于上面的Caculator类，如果要增加新的运算，需要修改getRes方法，
//	如果在增加新功能的时候要修改源代码，那么就会有修改出错的可能。
//	我们在增加新的功能的时候，不能影响其他已经完成的功能，
//	这就是对修改关闭，对扩展开放，叫做开闭原则。
//*/

//void test()
//{
//	Caculator c(10, 2, "*");
//	int res = c.getRes();
//	std::cout << res << std::endl;
//}

//抽象计算器类
class AbstractCaculator{
public:
	virtual void setOperatorNumber(int num1, int num2) = 0;
	virtual int getResult() = 0;
};

//加法计算器类
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

//减法计算器类
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

//乘法计算器类
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

//除法计算器类
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

//指数计算器类
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