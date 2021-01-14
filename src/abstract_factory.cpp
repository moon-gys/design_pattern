#include "factory.h"

//�ܳ�
class Factory
{
public:
	virtual Shoes* CreateShoes() = 0;
	virtual Clothe* CreateClothe() = 0;
	virtual ~Factory() {};
};

//�Ϳ�������
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
//	// =========== �Ϳ��������� ======== //
//	//Ь�������Ϳ�������
//	Factory* p_nike_producer = new NikeProduce();
//
//	//�Ϳ������߲�����Ь
//	Shoes* p_nike_shoes = p_nike_producer->CreateShoes();
//
//	//�Ϳ������߲����·�
//	Clothe* p_nike_clothe = p_nike_producer->CreateClothe();
//
//	//�Ϳ���Ь���
//	p_nike_shoes->Show();
//	//�Ϳ��·����
//	p_nike_clothe->Show();
//
//	//�ͷ���Դ
//	delete p_nike_shoes;
//	delete p_nike_clothe;
//	delete p_nike_producer;
//	
//	return 0;
//}