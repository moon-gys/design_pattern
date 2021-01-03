#include<iostream>

using namespace std;

class SingleInstance{
public:
	//获取单例对象
	static SingleInstance* getInstance();

	//释放单例，进程退出时调用
	static void deleteInstance();

	//打印单例地址
	void print();

private:
	//construct and desconstruct
	SingleInstance();
	~SingleInstance();

	SingleInstance(const SingleInstance& signal);
	const SingleInstance& operator=(const SingleInstance& singal);

private:

	static SingleInstance* m_SingleInstance;
};