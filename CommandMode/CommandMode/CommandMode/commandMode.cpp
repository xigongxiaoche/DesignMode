#include<iostream>
#include<queue>
#include<Windows.h>
using namespace std;
/*
	命令模式:
	对命令进行封装，将发出命令的责任和执行命令的责任分割开。
	比如客户机和服务器之间的任务处理，线程池
*/
//任务处理类
class HandlerClientProtocol{
public:
	//增加金币
	void AddMoney()
	{
		cout << "给玩家增加金币" << endl;
	}
	//增加钻石
	void addDiamond()
	{
		cout << "给玩家增加钻石" << endl;
	}
	//增加装备
	void addEquipment()
	{
		cout << "给玩家增加装备" << endl;
	}
	//升级
	void addLevel()
	{
		cout << "给玩家升级" << endl;
	}
};




//抽象命令接口
class AbstractCommand{
public:
	virtual void handler() = 0;//处理客户端的请求
};

//处理增加金币请求
class AddMoneyCommand :public AbstractCommand{
public:
	AddMoneyCommand(HandlerClientProtocol* protocol)
	{
		_protocol = protocol;
	}
	virtual void handler()
	{
		_protocol->AddMoney();
	}
public:
	HandlerClientProtocol* _protocol;
};

//处理增加钻石请求
class AddDiamondCommand :public AbstractCommand{
public:
	AddDiamondCommand(HandlerClientProtocol* protocol)
	{
		_protocol = protocol;
	}
	virtual void handler()
	{
		_protocol->addDiamond();
	}
public:
	HandlerClientProtocol* _protocol;
};

//处理增加装备请求
class AddEquipmentCommand :public AbstractCommand{
public:
	AddEquipmentCommand(HandlerClientProtocol* protocol)
	{
		_protocol = protocol;
	}
	virtual void handler()
	{
		_protocol->addEquipment();
	}
public:
	HandlerClientProtocol* _protocol;
};

//处理增加等级请求
class AddLevelCommand :public AbstractCommand{
public:
	AddLevelCommand(HandlerClientProtocol* protocol)
	{
		_protocol = protocol;
	}
	virtual void handler()
	{
		_protocol->addLevel();
	}
public:
	HandlerClientProtocol* _protocol;
};


//服务器
class Server{
public:
	//增加客户请求
	void addRequest(AbstractCommand* command)
	{
		_commands.push(command);
	}

	//处理请求
	void startHandle()
	{
		while (!_commands.empty())
		{
			AbstractCommand* curCommand = _commands.front();
			curCommand->handler();
			_commands.pop();
			Sleep(100);
		}
	}
public:
	queue<AbstractCommand*> _commands;
};

//客户端
void test()
{
	Server* server = new Server;
	HandlerClientProtocol* protocol = new HandlerClientProtocol;
	AbstractCommand* command1 = new AddMoneyCommand(protocol);
	AbstractCommand* command2 = new AddDiamondCommand(protocol);
	AbstractCommand* command3 = new AddEquipmentCommand(protocol);
	AbstractCommand* command4 = new AddLevelCommand(protocol);

	//服务器接收客户端请求
	server->addRequest(command1);
	server->addRequest(command2);
	server->addRequest(command3);
	server->addRequest(command4);
	//服务器处理客户端请求
	server->startHandle();

	delete command4;
	delete command3;
	delete command2;
	delete command1;
	delete protocol;
	delete server;

	command4 = nullptr;
	command3 = nullptr;
	command2 = nullptr;
	command1 = nullptr;
	protocol = nullptr;
	server = nullptr;
}

int main()
{
	test();
	return 0;
}