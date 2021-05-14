#include<iostream>
using namespace std;
//家庭影院外观模式案例
class AbstractFurniture{
public:
	virtual void On() = 0;
	virtual void Off() = 0;
};

//电视类
class TV :public AbstractFurniture{
public:
	virtual void On()
	{
		cout << "电视机启动!" << endl;
	}

	virtual void Off()
	{
		cout << "电视机关闭!" << endl;
	}
};

//灯类
class Light :public AbstractFurniture{
public:
	virtual void On()
	{
		cout << "灯启动!" << endl;
	}

	virtual void Off()
	{
		cout << "灯关闭!" << endl;
	}
};

//麦克风类
class Microphone :public AbstractFurniture{
public:
	virtual void On()
	{
		cout << "麦克风启动!" << endl;
	}

	virtual void Off()
	{
		cout << "麦克风关闭!" << endl;
	}
};

//音响类
class Audio :public AbstractFurniture{
public:
	virtual void On()
	{
		cout << "音响启动!" << endl;
	}

	virtual void Off()
	{
		cout << "音响关闭!" << endl;
	}
};

//DVD类
class DVD :public AbstractFurniture{
public:
	virtual void On()
	{
		cout << "DVD启动!" << endl;
	}

	virtual void Off()
	{
		cout << "DVD关闭!" << endl;
	}
};

//游戏机类
class GamePlayer :public AbstractFurniture{
public:
	virtual void On()
	{
		cout << "游戏机启动!" << endl;
	}

	virtual void Off()
	{
		cout << "游戏机关闭!" << endl;
	}
};

//KTV外观类
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

	//KTV模式启动
	void run()
	{
		_tv->On();	//电视打开
		_light->Off();//灯关闭
		_microphone->On();//麦克风打开
		_audio->On();//音响打开
		_dvd->On();//dvd打开
	}

	//KTV模式关闭
	void close()
	{
		_tv->Off();	//电视关闭
		_light->On();//灯打开
		_microphone->Off();//麦克风关闭
		_audio->Off();//音响关闭
		_dvd->Off();//dvd关闭
	}
private:
	TV* _tv;
	Light* _light;
	Microphone* _microphone;
	Audio* _audio;
	DVD* _dvd;
};

//游戏外观类
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

	//游戏模式启动
	void run()
	{
		_tv->On();//电视打开
		_audio->On();//音响打开
		_player->On();//游戏机打开
	}

	void close()
	{
		_tv->Off();//电视关闭
		_audio->Off();//音响关闭
		_player->Off();//游戏机关闭
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
	cout << "KTV模式启动:" << endl;
	ktv->run();
	cout << "KTV模式关闭:" << endl;
	ktv->close();
	cout << "游戏模式启动:" << endl;
	game->run();
	cout << "游戏模式关闭:" << endl;
	game->close();
}
int main()
{
	test();
	return 0;
}