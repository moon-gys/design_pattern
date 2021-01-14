#include "factory.h"

//总鞋厂
class ShoesFactory 
{
public:
	virtual Shoes* CreateShoes() = 0;
	virtual ~ShoesFactory() {};
};

//耐克生产链
class NikeProducer:public ShoesFactory
{
	Shoes* CreateShoes()
	{
		return new NikeShoes();
	}
};

//阿迪生产链
class AdidasProducer :public ShoesFactory
{
	Shoes* CreateShoes()
	{
		return new AdidasShoes();
	}
};

//李宁生产链
class LiNingProducer: public ShoesFactory
{
	Shoes* CreateShoes()
	{
		return new LiNingShoes();
	}
};

//int main()
//{
//	// ========== 耐克生产流程 =========== //
//	//鞋厂开设耐克生产线
//	ShoesFactory* p_nike_producer = new NikeProducer();
//	//耐克生产线产出球鞋
//	Shoes* p_nike_shoes = new NikeShoes();
//	//耐克广告
//	p_nike_shoes->Show();
//
//	//释放资源
//	delete p_nike_shoes;
//	delete p_nike_producer;
//	
//
//	// ========== 阿迪生产流程 ======== //
//	//鞋厂开设阿迪生产线
//	ShoesFactory* p_adidas_producer = new AdidasProducer();
//	//阿迪生产线产出球鞋
//	Shoes* p_adidas_shoes = new AdidasShoes();
//	//阿迪广告
//	p_adidas_shoes->Show();
//
//	//释放资源
//	delete p_adidas_shoes;
//	delete p_adidas_producer;
//
//	return 0;
//}
