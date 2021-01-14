#include "factory.h"

enum ShoesType
{
	NIKE,
	LINING,
	ADIDAS
};

//��Ь��
class ShoesFactory
{
public:
	//����Ь�����ʹ�����ӦЬ�Ӷ���
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
//	//���칤������
//	ShoesFactory shoes_factory;
//
//	//��Ь�������󴴽��Ϳ�Ь����
//	Shoes* p_nike_shoes = shoes_factory.CreateShoes(NIKE);
//	if (p_nike_shoes)
//	{
//		//�Ϳ˹��
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

