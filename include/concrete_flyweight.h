#ifndef _CONCRETE_FLYWEIGHT_H_
#define _CONCRETE_FLYWEIGHT_H_

#include "flyweight.h"
#include <string>

class ConcreteFlyweight : public Flyweight
{

public:
	ConcreteFlyweight(std::string str) : intrinsic_state(str) {};
	virtual ~ConcreteFlyweight() {};

	void Operation(int extrinsic_state);

private:
	std::string intrinsic_state;
};
#endif // !defined(_CONCRETE_FLYWEIGHT_H_)