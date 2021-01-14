#include "factory.h"

//���󹤳�ģ���� 
//AbstractProdcut ��Ʒ������
template <class AbstractProduct>
class AbstractFactory
{
public:
	virtual AbstractProduct* CreateProduct() = 0;
	virtual ~AbstractFactory() {};
};

//�����Ʒģ����
//��Ʒ�����࣬ ��Ʒ������
template <class AbstractProduct, class ConcreteProduct>
class ConcreteFactory : public AbstractFactory<AbstractProduct>
{
public:
	AbstractProduct* CreateProduct()
	{
		return new ConcreteProduct();
	}
};

//int main()
//{
//	ConcreteFactory<Shoes, NikeShoes> nike_producer_shoes;
//	Shoes* p_nike_shoes = nike_producer_shoes.CreateProduct();
//	p_nike_shoes->Show();
//
//	ConcreteFactory<Clothe, NikeClothe> nike_producer_clothe;
//	Clothe* p_nike_clothe = nike_producer_clothe.CreateProduct();
//	p_nike_clothe->Show();
//
//	delete p_nike_shoes;
//	p_nike_shoes = NULL;
//
//	delete p_nike_clothe;
//	p_nike_clothe = NULL;
//
//
//	return 0;
//}