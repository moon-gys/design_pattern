#include <map>
#include <string>

#include "factory.h"

//���࣬��Ʒע���ģ��ӿ���
//ģ�������ʾ�����ǳ����Ʒ�ࣨShoes��Clothe��
template <class AbstractProcduct>
class IProductRegister
{
public:
	//��ȡ��Ʒ����ĳ���ӿ�
	virtual AbstractProcduct* CreateProduct() = 0;

protected:
	//��ֹ�ⲿ�Ĺ�����鹹�������ڲ��������������Ե���
	IProductRegister() {};
	virtual ~IProductRegister() {};

private:
	//��ֹ�ⲿ�����͸�ֵ����
	IProductRegister(const IProductRegister &);
	const IProductRegister& operator=(const IProductRegister &);
};

//����ģ���࣬����ע��ͻ�ȡ��Ʒ����
//ģ�����AbstractProduct��ʾ�Ĳ�Ʒ������
template <class AbstractProduct>
class ProductFactory
{
public:
	static ProductFactory<AbstractProduct>& get_instance()
	{
		static ProductFactory<AbstractProduct> instance;
		return instance;
	}

	//��Ʒע��
	void RegisterProduct(IProductRegister<AbstractProduct>* register_product_type, std::string name)
	{
		m_product_register[name] = register_product_type;
	}

	//��������name����ȡ��Ӧ�����Ʒ�Ķ���
	AbstractProduct* get_product_type(std::string name)
	{
		if (m_product_register.find(name) != m_product_register.end())
			return m_product_register[name]->CreateProduct();

		std::cout << "No product found" << std::endl;

		return NULL;
	}

private:
	//��ֹ�ⲿ�������鹹
	ProductFactory() {};
	~ProductFactory() {};

	//��ֹ�ⲿ�����͸�ֵ
	ProductFactory(const ProductFactory&) {};
	const ProductFactory& operator=(const ProductFactory&) {};

	//����ע����Ĳ�Ʒ��key����Ʒ�����֣�value����Ʒ����
	//std::map<std::string, IProductRegister<AbstractProduct>* > m_product_register;
	std::map<std::string, IProductRegister<AbstractProduct> * > m_product_register;

};

//��Ʒע��ģ���࣬���ڴ��������Ʒ�ʹӹ�����ע���Ʒ
//ģ�������ʾ�ĳ����Ʒ��;����Ʒ��
template <class AbstractProduct, class ConcreteProduct>
class ProductRegister : public IProductRegister<AbstractProduct>
{
public:

	//���캯��������ע���Ʒ��������ֻ����ʾ����
	explicit ProductRegister(std::string name)
	{
		//ͨ�����������Ѳ�Ʒע�ᵽ����
		ProductFactory<AbstractProduct>::get_instance().RegisterProduct(this, name);
	}

	//���������Ʒ����ָ��
	AbstractProduct* CreateProduct()
	{
		return new ConcreteProduct();
	}

};

//int main()
//{
//	// ============ �����Ϳ���Ь ============= //
//   // ע���Ʒ����ΪShoes�����ࣩ����ƷΪNiKe�����ࣩ����������Ʒ��Ϊnike
//	ProductRegister<Shoes, NikeShoes> nike_shoes_factory("nike");
//
//	// �ӹ�����ȡ��Ʒ����ΪShoes������Ϊnike�Ĳ�Ʒ����
//	Shoes* p_nike_shoes = ProductFactory<Shoes>::get_instance().get_product_type("nike");
//	// ��ʾ��Ʒ�Ĺ����
//	p_nike_shoes->Show();
//	// �ͷ���Դ
//	if (p_nike_shoes)
//		delete p_nike_shoes;
//
//	return 0;
//
//}