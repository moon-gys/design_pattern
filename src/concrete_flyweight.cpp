#include <iostream>

#include "concrete_flyweight.h"

void ConcreteFlyweight::Operation(int extrinsic_state) {
	std::cout << "Flyweight[" << extrinsic_state << "] do operation." << std::endl;
}