#include <iostream>

#include "flyweight.h"
#include "concrete_flyweight.h"
#include "flyweight_factory.h"


int main(int argc, char* argv[])
{
	FlyweightFactory factory;
	Flyweight* fw = factory.get_flyweight("one");
	fw->Operation(1);

	Flyweight* fw2 = factory.get_flyweight("two");
	fw2->Operation(2);
	//aready exist in pool
	Flyweight* fw3 = factory.get_flyweight("one");
	fw3->Operation(3);
	return 0;
}