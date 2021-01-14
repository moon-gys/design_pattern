#ifndef _FACTORY_H_
#define _FACTORY_H_

#include <iostream>

//鞋子抽象类
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
		std::cout << "我是耐克鞋，我的广告语: Just do it" << std::endl;
	}
};

class AdidasShoes :public Shoes
{
public:
	void Show()
	{
		std::cout << "我是阿迪鞋，我的广告语: Impossible is nothing" << std::endl;
	}
};

class LiNingShoes :public Shoes
{
public:
	void Show()
	{
		std::cout << "我是李宁鞋，我的广告语:  Everything is possible" << std::endl;
	}
};

//基类：衣服
class Clothe
{
public:
	virtual void Show() = 0;
	virtual ~Clothe() {};
};

//耐克衣服
class NikeClothe : public Clothe
{
	void Show()
	{
		std::cout << "我是耐克衣服，时尚我最在行" << std::endl;
	}
};

//耐克衣服
class AdidasClothe :public Clothe
{
	void Show()
	{
		std::cout << "我是阿迪衣服，时尚我最在行" << std::endl;
	}
};


#endif // !_FACTORY_H_
