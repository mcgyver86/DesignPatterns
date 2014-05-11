#include <iostream>
#include "singleton.h"

using namespace std;

class MyTypeOne : public ISingleton<MyTypeOne>{
public:
    void setValue(int a) { var=a; }
    int  getValue()   const   { return var; }
protected:
    friend class ISingleton<MyTypeOne>;
    MyTypeOne(int a=0): var(a) {}
private:
    int var;
};


class MyTypeSecond : public ISingleton<MyTypeSecond>{
public:
    void setValue(float a) { var=a; }
    float  getValue()   const   { return var; }
private:
    friend class ISingleton<MyTypeSecond>;
    MyTypeSecond(float a=0.0): var(a) {}
private:
    float var;
};


int main(){

    cout<<"Start Programe"<<endl;

     MyTypeOne& myTypeOneObject = MyTypeOne::getInstance();
    cout<<"myTypeOneObject="<<myTypeOneObject.getValue()<<endl;
    myTypeOneObject.setValue(7);
    cout<<"myTypeOneObject="<<myTypeOneObject.getValue()<<endl;

     MyTypeOne& myTypeOneObject2 = MyTypeOne::getInstance();
     cout<<"myTypeOneObject2="<<myTypeOneObject2.getValue()<<endl;
     myTypeOneObject2.setValue(13);
     cout<<"myTypeOneObject="<<myTypeOneObject.getValue()<<endl;
     cout<<"myTypeOneObject2="<<myTypeOneObject2.getValue()<<endl;

     MyTypeSecond& myTypeSecondObject = MyTypeSecond::getInstance();
     cout<<"myTypeSecondObject="<<myTypeSecondObject.getValue()<<endl;
     myTypeSecondObject.setValue(7.61);
     cout<<"myTypeSecondObject="<<myTypeSecondObject.getValue()<<endl;

    cout <<"End Programe"<<endl;
    return 0;
}


/* obsolete
class MySingleObject : public ISingleton{
public:
 static ISingleton&   getInstance()
    {
        return MySingleInstance;
    }

private:
    MySingleObject(): ISingleton() {cout<<"aaa"<<endl;}
    ~MySingleObject() {cout<<"bbbb"<<endl;}

    static MySingleObject MySingleInstance;

};

MySingleObject MySingleObject::MySingleInstance;
*/
