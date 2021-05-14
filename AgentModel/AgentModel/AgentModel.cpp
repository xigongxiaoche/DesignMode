#include<iostream>
using namespace std;
/*
	����ģʽ���ṩһ�ַ�ʽ�����ƶ���������ķ���
	���ó�����
		һ�������ʺϻ��߲���ֱ��������һ������
		�������������ڿͻ��˺�Ŀ�����֮�����н������
*/

//����ϵͳ��
class AbstractSystem{
public:
	virtual void run() = 0;
};

//�Զ����ϵͳ��
class MySystem:public AbstractSystem{
public:
	virtual void run()
	{
		cout << "ϵͳ������..." << endl;
	}
};

//������
class Agent:public AbstractSystem{
public:
	Agent(string username, string userpasswd)
	{
		_username = username;
		_userpasswd = userpasswd;
		_system = new MySystem;
	}

	//���Ȩ��
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
			cout << "��ӭ�����ҵ����ˣ�" << endl;
			_system->run();
		}
		else
		{
			cout << "�û�����������������Ĳ���Ȩ�޲���!" << endl;
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
//	//ʹ�þ�������е���
//	MySystem* system = new MySystem;
//	system->run();
//}

//ʹ�ô���ģʽ
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