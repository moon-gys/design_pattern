#include<iostream>
#include<mutex>
#include<pthread.h>

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
		//Ϊ��������ȫ���̲߳���ʱ�ᴴ�����ʵ��
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
