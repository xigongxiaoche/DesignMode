#include<iostream>
#include<queue>
#include<Windows.h>
using namespace std;
/*
	����ģʽ:
	��������з�װ����������������κ�ִ����������ηָ��
	����ͻ����ͷ�����֮����������̳߳�
*/
//��������
class HandlerClientProtocol{
public:
	//���ӽ��
	void AddMoney()
	{
		cout << "��������ӽ��" << endl;
	}
	//������ʯ
	void addDiamond()
	{
		cout << "�����������ʯ" << endl;
	}
	//����װ��
	void addEquipment()
	{
		cout << "���������װ��" << endl;
	}
	//����
	void addLevel()
	{
		cout << "���������" << endl;
	}
};




//��������ӿ�
class AbstractCommand{
public:
	virtual void handler() = 0;//����ͻ��˵�����
};

//�������ӽ������
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

//����������ʯ����
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

//��������װ������
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

//�������ӵȼ�����
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


//������
class Server{
public:
	//���ӿͻ�����
	void addRequest(AbstractCommand* command)
	{
		_commands.push(command);
	}

	//��������
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

//�ͻ���
void test()
{
	Server* server = new Server;
	HandlerClientProtocol* protocol = new HandlerClientProtocol;
	AbstractCommand* command1 = new AddMoneyCommand(protocol);
	AbstractCommand* command2 = new AddDiamondCommand(protocol);
	AbstractCommand* command3 = new AddEquipmentCommand(protocol);
	AbstractCommand* command4 = new AddLevelCommand(protocol);

	//���������տͻ�������
	server->addRequest(command1);
	server->addRequest(command2);
	server->addRequest(command3);
	server->addRequest(command4);
	//����������ͻ�������
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