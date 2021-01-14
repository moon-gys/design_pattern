#include "factory.h"

//��Ь��
class ShoesFactory 
{
public:
	virtual Shoes* CreateShoes() = 0;
	virtual ~ShoesFactory() {};
};

//�Ϳ�������
class NikeProducer:public ShoesFactory
{
	Shoes* CreateShoes()
	{
		return new NikeShoes();
	}
};

//����������
class AdidasProducer :public ShoesFactory
{
	Shoes* CreateShoes()
	{
		return new AdidasShoes();
	}
};

//����������
class LiNingProducer: public ShoesFactory
{
	Shoes* CreateShoes()
	{
		return new LiNingShoes();
	}
};

//int main()
//{
//	// ========== �Ϳ��������� =========== //
//	//Ь�������Ϳ�������
//	ShoesFactory* p_nike_producer = new NikeProducer();
//	//�Ϳ������߲�����Ь
//	Shoes* p_nike_shoes = new NikeShoes();
//	//�Ϳ˹��
//	p_nike_shoes->Show();
//
//	//�ͷ���Դ
//	delete p_nike_shoes;
//	delete p_nike_producer;
//	
//
//	// ========== ������������ ======== //
//	//Ь�����谢��������
//	ShoesFactory* p_adidas_producer = new AdidasProducer();
//	//���������߲�����Ь
//	Shoes* p_adidas_shoes = new AdidasShoes();
//	//���Ϲ��
//	p_adidas_shoes->Show();
//
//	//�ͷ���Դ
//	delete p_adidas_shoes;
//	delete p_adidas_producer;
//
//	return 0;
//}
