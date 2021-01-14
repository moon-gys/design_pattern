#include "factory.h"

//总厂
class Factory
{
public:
	virtual Shoes* CreateShoes() = 0;
	virtual Clothe* CreateClothe() = 0;
	virtual ~Factory() {};
};

//耐克生产链
class NikeProduce : public Factory
{
	Shoes* CreateShoes()
	{
		return new NikeShoes();
	}

	Clothe* CreateClothe()
	{
		return new NikeClothe();
	}
};

//int main()
//{
//	// =========== 耐克生产流程 ======== //
//	//鞋厂开设耐克生产线
//	Factory* p_nike_producer = new NikeProduce();
//
//	//耐克生产线产出球鞋
//	Shoes* p_nike_shoes = p_nike_producer->CreateShoes();
//
//	//耐克生产线产出衣服
//	Clothe* p_nike_clothe = p_nike_producer->CreateClothe();
//
//	//耐克球鞋广告
//	p_nike_shoes->Show();
//	//耐克衣服广告
//	p_nike_clothe->Show();
//
//	//释放资源
//	delete p_nike_shoes;
//	delete p_nike_clothe;
//	delete p_nike_producer;
//	
//	return 0;
//}