#include <iostream>

#include "flyweight_factory.h"


Flyweight* FlyweightFactory::get_flyweight(std::string str) {
	std::map<std::string, Flyweight*>::iterator itr = m_flyweight.find(str);
	if (itr == m_flyweight.end())
	{
		Flyweight* fw = new ConcreteFlyweight(str);
		m_flyweight.insert(make_pair(str, fw));
		return fw;
	}
	else
	{
		std::cout << "aready in the pool,use the exist one:" << std::endl;
		return itr->second;
	}
}