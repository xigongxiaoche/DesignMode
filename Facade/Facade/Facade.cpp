//#include<iostream>
//using namespace std;
///*
//	���ģʽ���ǽ����ӵ�����ϵͳ����ͬһ���ӿ��н��й���
//	���ֻ��Ҫͨ������ӿں�����ϵͳ���н�����������ֱ��������ϵͳ���н���
//
//*/
//
////ϵͳ1
//class System1{
//public:
//	void run()
//	{
//		cout << "����ϵͳ1������������..." << endl;
//	}
//};
//
////ϵͳ2
//class System2{
//public:
//	void run()
//	{
//		cout << "����ϵͳ2������������..." << endl;
//	}
//};
////ϵͳ3
//class System3{
//public:
//	void run()
//	{
//		cout << "����ϵͳ3������������..." << endl;
//	}
//};
////ϵͳ4
//class System4{
//public:
//	void run()
//	{
//		cout << "����ϵͳ4������������..." << endl;
//	}
//};
//
//
//////��ͳ�ĵ��÷�ʽ
////void test()
////{
////	System1* s1=new System1;
////	System2* s2=new System2;
////	System3* s3=new System3;
////	System4* s4=new System4;
////	s1->run();
////	s2->run();
////	s3->run();
////	s4->run();
////
////	delete s1;
////	delete s2;
////	delete s3;
////	delete s4;
////}
//
//
////�����
//class System{
//public:
//	System()
//	{
//		_s1 = new System1;
//		_s2 = new System2;
//		_s3 = new System3;
//		_s4 = new System4;
//	}
//	~System()
//	{
//		delete _s1;
//		delete _s2;
//		delete _s3;
//		delete _s4;
//	}
//	void runSystem()
//	{
//		_s1->run();
//		_s2->run();
//		_s3->run();
//		_s4->run();
//	}
//private:
//	System1* _s1;
//	System2* _s2;
//	System3* _s3;
//	System4* _s4;
//};
//void test()
//{
//	System* system = new System;
//	system->runSystem();
//}
//int main()
//{
//	test();
//	return 0;
//}