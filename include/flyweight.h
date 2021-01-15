#ifndef _FLYWEIGHT_H_
#define _FLYWEIGHT_H_

class Flyweight
{

public:
	virtual ~Flyweight() {};

	virtual void Operation(int extrinsic_state) = 0;
};
#endif // !defined(_FLYWEIGHT_H_)