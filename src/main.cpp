#include<iostream>
#include<mutex>
#include<pthread.h>

#include "Singleton.h"

#define NUM_THREADS 5

void* printHello(void* threadid)
{
	pthread_detach(pthread_self());

	int tid = *((int*)threadid);

	std::cout << "Hi, my threads id is: " << tid << std::endl;

	Singleton::getInstance()->print();

	pthread_exit(NULL);
}

int main()
{

	pthrad_t threads[NUM_THREADS] = { 0 };
	int indexes[NUM_THREADS] = { 0 };

	int ret = 0;
	
	std::cout << "main() starting..." << std::endl;

	for (int i = 0; i < NUM_THREADS; i++)
	{
		std::cout << "main() creating thread:[" << i << "]" << std::endl;
		indexes[i] = i;

		ret = pthread_create(&threads[i], NULL, printHello, (void*)&indexes[i]);
		if (ret)
		{
			std::cout << "Error, can not create thread" << ret << std::endl;
			exit(-1);
		}
	}

	Singleton::deleteInstance();
	std::cout << "main(): ending..."<< std::endl;

	return 0;
}