#include<iostream>
using namespace std;

/*
	单例模式：
		一个类只能有一个实例化对象，并提供一个接口进行访问；
		一个资源只能在内存中只有一份，不能出现多份；

	实现单例的步骤：
	1.构造函数私有化；
	2.增加静态的、私有的、当前类的指针变量；
	3.提供静态的对外接口，让用户可以获得单例对象；

	单例模式分为懒汉式和饿汉式

	懒汉式：资源在使用时才初始化加载（延时加载)
	饿汉式：资源在程序初始化阶段完成加载(空间换时间)
	
	饿汉式遇到多线程是安全的；
	懒汉式遇到多线程是不安全的；
*/


//懒汉式
class SingleTon_lazy{
private:
	//构造函数私有化保证一个类只能有一个对象
	SingleTon_lazy()
	{
		cout << "我是懒汉式单例模式" << endl;
	}

public:
	//将函数声明为静态，就可以通过类名访问
	static SingleTon_lazy* getInstance()
	{
		//没有就创建
		if (object == nullptr)
		{
			object = new SingleTon_lazy;
		}
		return object;
	}

private:
	static SingleTon_lazy* object;	//静态修饰保证资源只有一份，并且在类外进行初始化
};

//类外初始化
SingleTon_lazy* SingleTon_lazy::object = nullptr;


//饿汉式
class SingleTon_hunger{
private:
	//构造函数私有化保证一个类只能有一个对象
	SingleTon_hunger()
	{
		cout << "我是饿汉式单例模式" << endl;
	}

public:
	//将函数声明为静态，就可以通过类名访问
	static SingleTon_hunger* getInstance()
	{
		return object;
	}

	//饿汉式单例模式资源的释放
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

//类外初始化时创建对象
SingleTon_hunger* SingleTon_hunger::object = new SingleTon_hunger;



//void test()
//{
//	cout << "我是客户端" << endl;
//	SingleTon_lazy::getInstance();
//}

void test()
{
	SingleTon_hunger* p = SingleTon_hunger::getInstance();
	SingleTon_hunger* p2 = SingleTon_hunger::getInstance();
	if (p == p2)
	{
		cout << "两个指针指向同一块内存，是饿汉单例模式!" << endl;
	}
	else
	{
		cout << "不是单例模式" << endl;
	}

	SingleTon_lazy* p3 = SingleTon_lazy::getInstance();
	SingleTon_lazy* p4 = SingleTon_lazy::getInstance();
	if (p3 == p4)
	{
		cout << "两个指针指向同一块内存，是懒汉单例模式!" << endl;
	}
	else
	{
		cout << "不是单例模式" << endl;
	}

}

int main()
{
	test();
	return 0;
}