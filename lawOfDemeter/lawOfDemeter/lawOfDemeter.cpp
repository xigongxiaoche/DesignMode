#include<iostream>
#include<string>
#include<vector>

/*
	迪米特法则，也叫最少知道原则。
	就是说一个对象应当对其它对象有尽可能少的了解，不要和陌生人说话。
	主张通过一个中介类获取用户的需求，并进行服务，
	用户不需要自己进行繁琐的工作，中介类会替用户做这些事

	迪米特法则的初衷在于降低类之间的耦合
*/

//抽象楼盘类
class  AbastractBuilding{
public:
	virtual void sale() = 0;
	virtual std::string getQuality() = 0;
};

//楼盘A
class BuildingA :public AbastractBuilding{
public:
	BuildingA()
	{
		_quality = "高品质";
	}
	virtual void sale()
	{
		std::cout << "楼盘A--" << _quality << " 正在售卖中！" << std::endl;
	}
	virtual std::string getQuality()
	{
		return _quality;
	}
public:
	std::string _quality;
};

//楼盘B
class BuildingB :public AbastractBuilding{
public:
	BuildingB()
	{
		_quality = "中品质";
	}
	virtual void sale()
	{
		std::cout << "楼盘B--" << _quality << " 正在售卖中！" << std::endl;
	}
	virtual std::string getQuality()
	{
		return _quality;
	}
public:
	std::string _quality;
};

//楼盘C
class BuildingC :public AbastractBuilding{
public:
	BuildingC()
	{
		_quality = "低品质";
	}
	virtual void sale()
	{
		std::cout << "楼盘C--" << _quality << " 正在售卖中！" << std::endl;
	}
	virtual std::string getQuality()
	{
		return _quality;
	}
public:
	std::string _quality;
};



////客户端：当需要不同品质的楼盘，要和具体类打交道，需要通过一次次的查找比较，
////找到自己想要的楼盘，效率很低,客户体验很差
//void Client01(std::string quality)
//{
//	BuildingA* p = new BuildingA;
//	if (p->_quality == quality)
//	{
//		p->sale();
//		delete p;
//		return;
//	}
//	
//
//	BuildingB* p2 = new BuildingB;
//	if (p2->_quality == quality)
//	{
//		p2->sale();
//		delete p2;
//		return;
//	}
//	
//
//	BuildingC* p3 = new BuildingC;
//	if (p3->_quality == quality)
//	{
//		p3->sale();
//		delete p3;
//		return;
//	}
//	
//	std::cout << "不好意思，没有满足您要求的楼盘!" << std::endl;
//}

//中介类：维护管理所有的楼盘类
class Intermediary{
public:
	Intermediary()
	{
		AbastractBuilding* p = new BuildingA;
		vbuilding.push_back(p);
		p = new BuildingB;
		vbuilding.push_back(p);
		p = new BuildingC;
		vbuilding.push_back(p);
	}

	AbastractBuilding* findMyBuilding(std::string quality)
	{
		for (const auto e : vbuilding)
		{
			if (e->getQuality() == quality)
				return e;
		}

		return NULL;
	}
	~Intermediary()
	{
		for (const auto e : vbuilding)
		{
			delete e;
		}
	}
public:
	std::vector<AbastractBuilding*> vbuilding;
};


//客户端通过中介得到自己想要的楼盘
void Client02()
{
	Intermediary* midPeople = new Intermediary;
	AbastractBuilding* building=midPeople->findMyBuilding("高品质");
	if (building != NULL)
	{
		building->sale();
	}
	else
	{
		std::cout << "对不起，没有找到满足您要求的楼盘!" << std::endl;
	}
}
int main()
{
	Client02();
	return 0;
}