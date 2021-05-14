#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	适配器模式：将不符合要求的接口转换为需要的接口
	类似于充电器的转换头，将220v的电压转换为手机能够接受的电压
*/

//仿函数类
struct MyPrint{
	void operator()(int arg1,int arg2)
	{
		cout << arg1 << "+" << arg2 << "=" << arg1 + arg2 << endl;
	}
};

//定义目标接口，规定适配后的接口类型
class AbstractTarget{
public:
	virtual void operator()(int arg1) = 0;
};


////适配器类,但存在限制
//class Adapter :public AbstractTarget{
//public:
//	virtual void operator()(int arg1)
//	{
//		_myprint(arg1,100);//将参数限制了
//	}
//public:
//	MyPrint _myprint;
//};	


////客户端1
//void test()
//{
//	vector<int> v;
//	for (int i = 0; i < 11; ++i)
//	{
//		v.push_back(i);
//	}
//
//	//从begin开始到end，调用Adapter这个仿函数
//	for_each(v.begin(), v.end(), Adapter());
//}

//适配器模式，改进后
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

//客户端02:传入一个参数就可以完成传入两个参数的效果
void test()
{
	vector<int> v;
	for (int i = 0; i < 11; ++i)
	{
		v.push_back(i);
	}
	
	//从begin开始到end，调用Adapter这个仿函数
	//有两个参数，一个是传入的1024，另一个是迭代器指向的数据
	for_each(v.begin(), v.end(), myBind2nd(1024));
}
int main()
{
	test();
	return 0;
}