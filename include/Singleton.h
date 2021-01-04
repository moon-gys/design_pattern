#ifndef _DESIGN_PATTERN_SINGLETON_
#define _DESIGN_PATTERN_SINGLETON_

class Singleton {
public:
	//get singleton object
	static Singleton* getInstance();

	//release singleton object when threads exits
	static void deleteInstance();

	//print singleton oject adrress
	void print();

private:
	//construct and desconstruct
	Singleton();
	~Singleton();

	//copy and assignment constructor
	/*!
	Don't forget to declare these two. You want to make sure they
	are inaccessible(especially from outside), otherwise, you may accidentally get copies of
	your singleton appearing.
	*/
	Singleton(const Singleton& signal);
	const Singleton& operator=(const Singleton& singal);

private:

	//the unique object points to this sigleton 
	static Singleton* m_Singleton;
};

#endif // !_DESIGN_PATTERN_SINGLETON_


