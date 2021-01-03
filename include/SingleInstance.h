#include<iostream>

using namespace std;

class SingleInstance{
public:
	//��ȡ��������
	static SingleInstance* getInstance();

	//�ͷŵ����������˳�ʱ����
	static void deleteInstance();

	//��ӡ������ַ
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