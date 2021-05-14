#include<iostream>
using namespace std;
/*
	����ģʽ��

	�ϳɸ���ԭ��Ϳ���ԭ���ʹ��
*/


//��������
class WeaponStrategy{
public:
	virtual void useWeapon() = 0;
};

//AK47
class AK47 :public WeaponStrategy{
public:
	virtual void useWeapon()
	{
		cout << "AK47�����ˣ�" << endl;
	}
};

//��ש
class BanZhuan :public WeaponStrategy{
public:
	virtual void useWeapon()
	{
		cout << "�����ٌţ�һש�̵���" << endl;
	}
};

//��ɫ
class Character{
public:
	//��������
	void setWeapon(WeaponStrategy* weapon)
	{
		_cWeapon = weapon;
	}
	//ʹ������
	void useWeapon()
	{
		_cWeapon->useWeapon();
	}
private:
	WeaponStrategy* _cWeapon;
};
//�ͻ���
void test()
{
	Character* person1 = new Character;
	WeaponStrategy* ak = new AK47;
	WeaponStrategy* banzhuan = new BanZhuan;

	cout << "��ʼ��������:" << endl;
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