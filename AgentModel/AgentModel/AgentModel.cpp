#include<iostream>
using namespace std;
/*
	代理模式：提供一种方式来控制对其它对象的访问
	适用场景：
		一个对象不适合或者不能直接引用另一个对象，
		而代理对象可以在客户端和目标对象之间起到中介的作用
*/

//抽象系统类
class AbstractSystem{
public:
	virtual void run() = 0;
};

//自定义的系统类
class MySystem:public AbstractSystem{
public:
	virtual void run()
	{
		cout << "系统启动中..." << endl;
	}
};

//代理类
class Agent:public AbstractSystem{
public:
	Agent(string username, string userpasswd)
	{
		_username = username;
		_userpasswd = userpasswd;
		_system = new MySystem;
	}

	//检查权限
	bool checkRoot()
	{
		if (_username == "root" && _userpasswd == "123")
		{
			return true;
		}
		return false;
	}

	virtual void run()
	{
		if (checkRoot())
		{
			cout << "欢迎您，我的主人！" << endl;
			_system->run();
		}
		else
		{
			cout << "用户名或者密码错误，您的操作权限不足!" << endl;
		}
	}

	~Agent()
	{
		if (_system != nullptr)
		{
			delete _system;
		}
	}
public:
	string _username;
	string _userpasswd;
	MySystem* _system;
};


//void test()
//{
//	//使用具体类进行调用
//	MySystem* system = new MySystem;
//	system->run();
//}

//使用代理模式
void test()
{
	Agent* agent = new Agent("root","123");
	agent->run();

	delete agent;
	agent = nullptr;

	agent = new Agent("cxp", "666");
	agent->run();

	delete agent;
	agent = nullptr;
}

int main()
{
	test();
	return 0;
}