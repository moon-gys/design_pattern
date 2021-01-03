#include<iostream>
#include <mutex>    
#include <pthread.h> 

using namespace std;

void* printHello(void* threadid)
{
	pthread_detach(pthread_self());
}

int main()
{

	cout << "Hello world!" << endl;

	return 0;
}