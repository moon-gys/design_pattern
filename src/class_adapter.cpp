#include<iostream>

//Target
class Target
{
public:
	Target(){}
	~Target(){}

	virtual void Request()
	{
		std::cout << "Target::Request\n";
	}
};

//Adaptee
class Adaptee
{
public:
	Adaptee() {};
	~Adaptee() {};
	void SpecificRequest()
	{
		std::cout << "Adaptee::SpecificRequest" << std::endl;
	}
};

// Adapter
class Adapter : public Target, Adaptee
{
public:
	void Request()
	{
		Adaptee::SpecificRequest();
	}
};

////client
//int main()
//{
//	Target* targetObj = new Adapter();
//
//	targetObj->Request();
//
//	delete targetObj;
//	targetObj = NULL;
//
//	return 0;
//}