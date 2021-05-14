#include<iostream>
#include<string>
#include<vector>

/*
	�����ط���Ҳ������֪��ԭ��
	����˵һ������Ӧ�������������о������ٵ��˽⣬��Ҫ��İ����˵����
	����ͨ��һ���н����ȡ�û������󣬲����з���
	�û�����Ҫ�Լ����з����Ĺ������н�������û�����Щ��

	�����ط���ĳ������ڽ�����֮������
*/

//����¥����
class  AbastractBuilding{
public:
	virtual void sale() = 0;
	virtual std::string getQuality() = 0;
};

//¥��A
class BuildingA :public AbastractBuilding{
public:
	BuildingA()
	{
		_quality = "��Ʒ��";
	}
	virtual void sale()
	{
		std::cout << "¥��A--" << _quality << " ���������У�" << std::endl;
	}
	virtual std::string getQuality()
	{
		return _quality;
	}
public:
	std::string _quality;
};

//¥��B
class BuildingB :public AbastractBuilding{
public:
	BuildingB()
	{
		_quality = "��Ʒ��";
	}
	virtual void sale()
	{
		std::cout << "¥��B--" << _quality << " ���������У�" << std::endl;
	}
	virtual std::string getQuality()
	{
		return _quality;
	}
public:
	std::string _quality;
};

//¥��C
class BuildingC :public AbastractBuilding{
public:
	BuildingC()
	{
		_quality = "��Ʒ��";
	}
	virtual void sale()
	{
		std::cout << "¥��C--" << _quality << " ���������У�" << std::endl;
	}
	virtual std::string getQuality()
	{
		return _quality;
	}
public:
	std::string _quality;
};



////�ͻ��ˣ�����Ҫ��ͬƷ�ʵ�¥�̣�Ҫ�;�����򽻵�����Ҫͨ��һ�δεĲ��ұȽϣ�
////�ҵ��Լ���Ҫ��¥�̣�Ч�ʺܵ�,�ͻ�����ܲ�
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
//	std::cout << "������˼��û��������Ҫ���¥��!" << std::endl;
//}

//�н��ࣺά���������е�¥����
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


//�ͻ���ͨ���н�õ��Լ���Ҫ��¥��
void Client02()
{
	Intermediary* midPeople = new Intermediary;
	AbastractBuilding* building=midPeople->findMyBuilding("��Ʒ��");
	if (building != NULL)
	{
		building->sale();
	}
	else
	{
		std::cout << "�Բ���û���ҵ�������Ҫ���¥��!" << std::endl;
	}
}
int main()
{
	Client02();
	return 0;
}