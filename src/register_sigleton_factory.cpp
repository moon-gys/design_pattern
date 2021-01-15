#include <map>
#include <string>

#include "factory.h"

//基类，产品注册的模板接口类
//模板参数表示的类是抽象产品类（Shoes，Clothe）
template <class AbstractProcduct>
class IProductRegister
{
public:
	//获取产品对象的抽象接口
	virtual AbstractProcduct* CreateProduct() = 0;

protected:
	//禁止外部的构造和虚构，子类内部的其他函数可以调用
	IProductRegister() {};
	virtual ~IProductRegister() {};

private:
	//禁止外部拷贝和赋值操作
	IProductRegister(const IProductRegister &);
	const IProductRegister& operator=(const IProductRegister &);
};

//工厂模板类，用于注册和获取产品对象
//模板参数AbstractProduct表示的产品抽象类
template <class AbstractProduct>
class ProductFactory
{
public:
	static ProductFactory<AbstractProduct>& get_instance()
	{
		static ProductFactory<AbstractProduct> instance;
		return instance;
	}

	//产品注册
	void RegisterProduct(IProductRegister<AbstractProduct>* register_product_type, std::string name)
	{
		m_product_register[name] = register_product_type;
	}

	//根据名字name，获取对应具体产品的对象
	AbstractProduct* get_product_type(std::string name)
	{
		if (m_product_register.find(name) != m_product_register.end())
			return m_product_register[name]->CreateProduct();

		std::cout << "No product found" << std::endl;

		return NULL;
	}

private:
	//禁止外部拷贝和虚构
	ProductFactory() {};
	~ProductFactory() {};

	//禁止外部拷贝和赋值
	ProductFactory(const ProductFactory&) {};
	const ProductFactory& operator=(const ProductFactory&) {};

	//保存注册过的产品，key：产品的名字，value：产品类型
	//std::map<std::string, IProductRegister<AbstractProduct>* > m_product_register;
	std::map<std::string, IProductRegister<AbstractProduct> * > m_product_register;

};

//产品注册模板类，用于创建具体产品和从工厂里注册产品
//模板参数表示的抽象产品类和具体产品类
template <class AbstractProduct, class ConcreteProduct>
class ProductRegister : public IProductRegister<AbstractProduct>
{
public:

	//构造函数，用于注册产品到工厂，只能显示调用
	explicit ProductRegister(std::string name)
	{
		//通过工厂单例把产品注册到工厂
		ProductFactory<AbstractProduct>::get_instance().RegisterProduct(this, name);
	}

	//创建具体产品对象指针
	AbstractProduct* CreateProduct()
	{
		return new ConcreteProduct();
	}

};

//int main()
//{
//	// ============ 生产耐克球鞋 ============= //
//   // 注册产品种类为Shoes（基类），产品为NiKe（子类）到工厂，产品名为nike
//	ProductRegister<Shoes, NikeShoes> nike_shoes_factory("nike");
//
//	// 从工厂获取产品种类为Shoes，名称为nike的产品对象
//	Shoes* p_nike_shoes = ProductFactory<Shoes>::get_instance().get_product_type("nike");
//	// 显示产品的广告语
//	p_nike_shoes->Show();
//	// 释放资源
//	if (p_nike_shoes)
//		delete p_nike_shoes;
//
//	return 0;
//
//}