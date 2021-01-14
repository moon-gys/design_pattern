#ifndef _FACTORY_H_
#define _FACTORY_H_

#include <iostream>

//Ь�ӳ�����
class Shoes
{
public:
	virtual ~Shoes() {};
	virtual void Show() = 0;
};

class NikeShoes :public Shoes
{
public:
	void Show()
	{
		std::cout << "�����Ϳ�Ь���ҵĹ����: Just do it" << std::endl;
	}
};

class AdidasShoes :public Shoes
{
public:
	void Show()
	{
		std::cout << "���ǰ���Ь���ҵĹ����: Impossible is nothing" << std::endl;
	}
};

class LiNingShoes :public Shoes
{
public:
	void Show()
	{
		std::cout << "��������Ь���ҵĹ����:  Everything is possible" << std::endl;
	}
};

//���ࣺ�·�
class Clothe
{
public:
	virtual void Show() = 0;
	virtual ~Clothe() {};
};

//�Ϳ��·�
class NikeClothe : public Clothe
{
	void Show()
	{
		std::cout << "�����Ϳ��·���ʱ����������" << std::endl;
	}
};

//�Ϳ��·�
class AdidasClothe :public Clothe
{
	void Show()
	{
		std::cout << "���ǰ����·���ʱ����������" << std::endl;
	}
};


#endif // !_FACTORY_H_
