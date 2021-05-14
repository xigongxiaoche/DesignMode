#include<iostream>
using namespace std;
/*
	策略模式：

	合成复用原则和开闭原则的使用
*/


//武器策略
class WeaponStrategy{
public:
	virtual void useWeapon() = 0;
};

//AK47
class AK47 :public WeaponStrategy{
public:
	virtual void useWeapon()
	{
		cout << "AK47开火了！" << endl;
	}
};

//板砖
class BanZhuan :public WeaponStrategy{
public:
	virtual void useWeapon()
	{
		cout << "功夫再屌，一砖撂倒！" << endl;
	}
};

//角色
class Character{
public:
	//设置武器
	void setWeapon(WeaponStrategy* weapon)
	{
		_cWeapon = weapon;
	}
	//使用武器
	void useWeapon()
	{
		_cWeapon->useWeapon();
	}
private:
	WeaponStrategy* _cWeapon;
};
//客户端
void test()
{
	Character* person1 = new Character;
	WeaponStrategy* ak = new AK47;
	WeaponStrategy* banzhuan = new BanZhuan;

	cout << "开始设置武器:" << endl;
	person1->setWeapon(ak);
	person1->useWeapon();
	
	delete ak;
	ak = nullptr;

	person1->setWeapon(banzhuan);
	person1->useWeapon();

	delete banzhuan;
	banzhuan = nullptr;

	delete person1;
	person1 = nullptr;
}


int main()
{
	test();
	return 0;
}