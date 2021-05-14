//#include<iostream>
//using namespace std;
///*
//	外观模式就是将复杂的子类系统抽象到同一个接口中进行管理，
//	外界只需要通过这个接口和子类系统进行交互，而不必直接与子类系统进行交互
//
//*/
//
////系统1
//class System1{
//public:
//	void run()
//	{
//		cout << "我是系统1，正在启动中..." << endl;
//	}
//};
//
////系统2
//class System2{
//public:
//	void run()
//	{
//		cout << "我是系统2，正在启动中..." << endl;
//	}
//};
////系统3
//class System3{
//public:
//	void run()
//	{
//		cout << "我是系统3，正在启动中..." << endl;
//	}
//};
////系统4
//class System4{
//public:
//	void run()
//	{
//		cout << "我是系统4，正在启动中..." << endl;
//	}
//};
//
//
//////传统的调用方式
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
////外观类
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