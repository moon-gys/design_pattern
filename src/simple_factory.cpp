#include "factory.h"

enum ShoesType
{
	NIKE,
	LINING,
	ADIDAS
};

//总鞋厂
class ShoesFactory
{
public:
	//根据鞋子类型创建对应鞋子对象
	Shoes* CreateShoes(ShoesType type)
	{
		switch (type)
		{
		case NIKE:
			return new NikeShoes();
			break;
		case ADIDAS:
			return new AdidasShoes();
			break;
		case LINING:
			return new LiNingShoes();
			break;
		default:
			break;
		}
	}
};

//int main()
//{
//	//构造工厂对象
//	ShoesFactory shoes_factory;
//
//	//从鞋工厂对象创建耐克鞋对象
//	Shoes* p_nike_shoes = shoes_factory.CreateShoes(NIKE);
//	if (p_nike_shoes)
//	{
//		//耐克广告
//		p_nike_shoes->Show();
//
//		delete p_nike_shoes;
//		p_nike_shoes = NULL;
//	}
//
//	Shoes* p_adidas_shoes = shoes_factory.CreateShoes(ADIDAS);
//	if (p_adidas_shoes)
//	{
//		p_adidas_shoes->Show();
//
//		delete p_adidas_shoes;
//		p_adidas_shoes = NULL;
//	}
//
//	Shoes* p_lining_shoes = shoes_factory.CreateShoes(LINING);
//	if (p_lining_shoes)
//	{
//		p_lining_shoes->Show();
//
//		delete p_lining_shoes;
//		p_lining_shoes = NULL;
//	}
//
//	return 0;
//}

