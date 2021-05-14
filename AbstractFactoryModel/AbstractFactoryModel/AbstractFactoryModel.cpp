#include<iostream>
using namespace std;

//抽象工厂模式
/*
	产品等级结构：产品等级结构即产品的继承结构
	产品族：
		在抽象工厂模式中，产品族是指由同一个工厂生产的，
		位于不同产品等级结构中的一组产品

	抽象工厂模式针对产品族，而不是针对产品等级结构
*/
/*
	定义一个抽象工厂类，这个类中定义一些产生不同对象的纯虚函数，
	具体工厂类继承抽象工厂类，并重写纯虚函数

	抽象工厂模式不符合开闭原则
*/

//抽象苹果类
class AbstractApple{
public:
	virtual void showName() = 0;
};


//中国苹果类
class ChinaApple :public AbstractApple{
public:
	virtual void showName()
	{
		cout << "中国苹果" << endl;
	}
};

//美国苹果类
class AmericanApple :public AbstractApple{
public:
	virtual void showName()
	{
		cout << "美国苹果" << endl;
	}
};

//日本苹果类
class JapanApple :public AbstractApple{
public:
	virtual void showName()
	{
		cout << "日本苹果" << endl;
	}
};

//抽象橘子类
class AbstractOrange{
public:
	virtual void showName() = 0;
};



//中国橘子类
class ChinaOrange:public AbstractOrange{
public:
	virtual void showName()
	{
		cout << "中国橘子" << endl;
	}
};

//美国橘子类
class AmericanOrange :public AbstractOrange{
public:
	virtual void showName()
	{
		cout << "美国橘子" << endl;
	}
};

//日本橘子类
class JapanOrange :public AbstractOrange{
public:
	virtual void showName()
	{
		cout << "日本橘子" << endl;
	}
};

//抽象香蕉类
class AbstractBanana{
public:
	virtual void showName() = 0;
};

//中国香蕉类
class ChinaBanana:public AbstractBanana{
public:
	virtual void showName()
	{
		cout << "中国香蕉" << endl;
	}
};

//美国香蕉类
class AmericanBanana :public AbstractBanana{
public:
	virtual void showName()
	{
		cout << "美国香蕉" << endl;
	}
};


//日本香蕉类
class JapanBanana :public AbstractBanana{
public:
	virtual void showName()
	{
		cout << "日本香蕉" << endl;
	}
};





//抽象工厂类
class AbstractFactory{
public:
	virtual AbstractApple* appleCreate() = 0;
	virtual AbstractOrange* orangeCreate() = 0;
	virtual AbstractBanana* bananaCreate() = 0;
};

//中国工厂类
class ChinaFactory :public AbstractFactory{
public:
	virtual AbstractApple* appleCreate()
	{
		return new ChinaApple;
	}
	virtual AbstractOrange* orangeCreate()
	{
		return new ChinaOrange;
	}
	virtual AbstractBanana* bananaCreate()
	{
		return new ChinaBanana;
	}
};


//美国工厂类
class AmericanFactory :public AbstractFactory{
public:
	virtual AbstractApple* appleCreate()
	{
		return new AmericanApple;
	}
	virtual AbstractOrange* orangeCreate()
	{
		return new AmericanOrange;
	}
	virtual AbstractBanana* bananaCreate()
	{
		return new AmericanBanana;
	}
};

//日本工厂类
class JapanFactory :public AbstractFactory{
public:
	virtual AbstractApple* appleCreate()
	{
		return new JapanApple;
	}
	virtual AbstractOrange* orangeCreate()
	{
		return new JapanOrange;
	}
	virtual AbstractBanana* bananaCreate()
	{
		return new JapanBanana;
	}
};

//客户端
void test()
{
	AbstractFactory* factory = nullptr;
	AbstractApple* apple = nullptr;
	AbstractOrange* orange = nullptr;
	AbstractBanana* banana = nullptr;

	//中国工厂
	factory = new ChinaFactory;
	apple=factory->appleCreate();
	orange = factory->orangeCreate();
	banana = factory->bananaCreate();
	
	cout << "中国工厂:" << endl;
	apple->showName();
	orange->showName();
	banana->showName();
	cout << "----------------------------------------" << endl;

	delete banana;
	delete orange;
	delete apple;
	delete factory;

	//美国工厂
	factory = new AmericanFactory;
	apple = factory->appleCreate();
	orange = factory->orangeCreate();
	banana = factory->bananaCreate();

	cout << "美国工厂:" << endl;
	apple->showName();
	orange->showName();
	banana->showName();
	cout << "----------------------------------------" << endl;

	delete banana;
	delete orange;
	delete apple;
	delete factory;

	//日本工厂
	factory = new JapanFactory;
	apple = factory->appleCreate();
	orange = factory->orangeCreate();
	banana = factory->bananaCreate();

	cout << "日本工厂:" << endl;
	apple->showName();
	orange->showName();
	banana->showName();
	cout << "----------------------------------------" << endl;

	delete banana;
	delete orange;
	delete apple;
	delete factory;
}


int main()
{
	test();
	return 0;
}