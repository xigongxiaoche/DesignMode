#include<iostream>
using namespace std;
//��ͥӰԺ���ģʽ����
class AbstractFurniture{
public:
	virtual void On() = 0;
	virtual void Off() = 0;
};

//������
class TV :public AbstractFurniture{
public:
	virtual void On()
	{
		cout << "���ӻ�����!" << endl;
	}

	virtual void Off()
	{
		cout << "���ӻ��ر�!" << endl;
	}
};

//����
class Light :public AbstractFurniture{
public:
	virtual void On()
	{
		cout << "������!" << endl;
	}

	virtual void Off()
	{
		cout << "�ƹر�!" << endl;
	}
};

//��˷���
class Microphone :public AbstractFurniture{
public:
	virtual void On()
	{
		cout << "��˷�����!" << endl;
	}

	virtual void Off()
	{
		cout << "��˷�ر�!" << endl;
	}
};

//������
class Audio :public AbstractFurniture{
public:
	virtual void On()
	{
		cout << "��������!" << endl;
	}

	virtual void Off()
	{
		cout << "����ر�!" << endl;
	}
};

//DVD��
class DVD :public AbstractFurniture{
public:
	virtual void On()
	{
		cout << "DVD����!" << endl;
	}

	virtual void Off()
	{
		cout << "DVD�ر�!" << endl;
	}
};

//��Ϸ����
class GamePlayer :public AbstractFurniture{
public:
	virtual void On()
	{
		cout << "��Ϸ������!" << endl;
	}

	virtual void Off()
	{
		cout << "��Ϸ���ر�!" << endl;
	}
};

//KTV�����
class KTV{
public:
	KTV()
	{
		_tv = new TV;
		_light = new Light;
		_microphone = new Microphone;
		_audio = new Audio;
		_dvd = new DVD;
	}
	~KTV()
	{
		delete _tv;
		delete _light;
		delete _microphone;
		delete _audio;
		delete _dvd;
	}

	//KTVģʽ����
	void run()
	{
		_tv->On();	//���Ӵ�
		_light->Off();//�ƹر�
		_microphone->On();//��˷��
		_audio->On();//�����
		_dvd->On();//dvd��
	}

	//KTVģʽ�ر�
	void close()
	{
		_tv->Off();	//���ӹر�
		_light->On();//�ƴ�
		_microphone->Off();//��˷�ر�
		_audio->Off();//����ر�
		_dvd->Off();//dvd�ر�
	}
private:
	TV* _tv;
	Light* _light;
	Microphone* _microphone;
	Audio* _audio;
	DVD* _dvd;
};

//��Ϸ�����
class Game{
public:
	Game()
	{
		_tv = new TV;
		_audio = new Audio;
		_player = new GamePlayer;
	}
	~Game()
	{
		delete _tv;
		delete _audio;
		delete _player;
	}

	//��Ϸģʽ����
	void run()
	{
		_tv->On();//���Ӵ�
		_audio->On();//�����
		_player->On();//��Ϸ����
	}

	void close()
	{
		_tv->Off();//���ӹر�
		_audio->Off();//����ر�
		_player->Off();//��Ϸ���ر�
	}
private:
	TV* _tv;
	Audio* _audio;
	GamePlayer* _player;
};


void test()
{
	KTV* ktv = new KTV;
	Game* game = new Game;
	cout << "KTVģʽ����:" << endl;
	ktv->run();
	cout << "KTVģʽ�ر�:" << endl;
	ktv->close();
	cout << "��Ϸģʽ����:" << endl;
	game->run();
	cout << "��Ϸģʽ�ر�:" << endl;
	game->close();
}
int main()
{
	test();
	return 0;
}