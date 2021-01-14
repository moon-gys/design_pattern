#include<iostream>
#include<mutex>

#include "Singleton.h" 

Singleton* Singleton::m_Singleton = NULL;


Singleton::Singleton()
{
	std::cout << "Construtor!" << std::endl;
};

Singleton::~Singleton()
{
	std::cout << "Destrutor!" << std::endl;
};

Singleton* Singleton::getInstance()
{
	if (m_Singleton == NULL) {
		//为加锁不安全，线程并发时会创建多个实例
		m_Singleton = new (std::nothrow) Singleton;
	}
		
	return m_Singleton;
};

void Singleton::deleteInstance()
{
	if (m_Singleton)
	{
		delete m_Singleton;
		m_Singleton = NULL;
	}
};

void Singleton::print()
{
	std::cout << "My adrress is: " << this << std::endl;
};


#include<iostream>
//#include<mutex>
//#include<pthread.h>
//
//#include "Singleton.h"
//
//#define NUM_THREADS 5
//
//void* printHello(void* threadid)
//{
//	pthread_detach(pthread_self());
//
//	int tid = *((int*)threadid);
//
//	std::cout << "Hi, my threads id is: " << tid << std::endl;
//
//	Singleton::getInstance()->print();
//
//	pthread_exit(NULL);
//}
//
//int main()
//{
//
//	pthrad_t threads[NUM_THREADS] = { 0 };
//	int indexes[NUM_THREADS] = { 0 };
//
//	int ret = 0;
//	
//	std::cout << "main() starting..." << std::endl;
//
//	for (int i = 0; i < NUM_THREADS; i++)
//	{
//		std::cout << "main() creating thread:[" << i << "]" << std::endl;
//		indexes[i] = i;
//
//		ret = pthread_create(&threads[i], NULL, printHello, (void*)&indexes[i]);
//		if (ret)
//		{
//			std::cout << "Error, can not create thread" << ret << std::endl;
//			exit(-1);
//		}
//	}
//
//	Singleton::deleteInstance();
//	std::cout << "main(): ending..."<< std::endl;
//
//	return 0;
//}