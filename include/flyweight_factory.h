#ifndef _FLYWEIGHT_FACTORY_H_
#define _FLYWEIGHT_FACTORY_H_

#include <map>

#include "concrete_flyweight.h"

class FlyweightFactory
{
public:

	FlyweightFactory() {};
	~FlyweightFactory() {};

	Flyweight* get_flyweight(std::string str);

private:
	std::map<std::string, Flyweight*> m_flyweight;
};

#endif // !_FLYWEIGHT_FACTORY_H_


