#ifndef __SINGLETON_H__
#define __SINGLETON_H__


template <class T>
class ISingleton
{
public:
    static  T& getInstance();

protected:
   ISingleton();
   virtual ~ISingleton();

private:

   ISingleton(const ISingleton &);
   ISingleton& operator=(const ISingleton&);

   //static   ISingleton ISingleInstance;


};


template<class T>
ISingleton<T>::ISingleton()
{
    std::cout<<"ISingleton constructor"<<std::endl;
}

template<class T>
ISingleton<T>::~ISingleton()
{
    std::cout<<"~ISingleton destructor"<<std::endl;
}

template<class T>
T& ISingleton<T>::getInstance()
{
    static T ISingleInstance;
    return ISingleInstance;
}

/*
class ISingleton
{
public:
    static  ISingleton& getInstance();

private:


   ISingleton(const ISingleton &tmp);
   ISingleton& operator=(const ISingleton&);
 protected:
    ISingleton();
   virtual ~ISingleton();


   static   ISingleton ISingleInstance;


};

*/

#endif
