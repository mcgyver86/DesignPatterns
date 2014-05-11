#include <iostream>
#include <vector>

using namespace std;

class ProxyBase{
public:
    virtual void turnLeft()=0;
    virtual void turnRight()=0;
    virtual void stop()=0;
    virtual void start()=0;
};


class Implementation : public ProxyBase{
public:
    void turnLeft(){ cout<<"impl->turnLeft"<<endl; }
    void turnRight(){ cout<<"imp-> turn right"<<endl; }
    void stop(){ cout<<"impl-> Stop"<<endl; }
    void start(){ cout<<"imp->start"<<endl; }
};


class Proxy :public ProxyBase {
    ProxyBase * implementation;
public:
    Proxy()  { implementation = new Implementation ; }
    ~Proxy() { delete implementation; }

    void turnLeft(){ implementation->turnLeft(); }
    void turnRight(){ implementation->turnRight(); }
    void stop(){ implementation->stop();}
    void start() {implementation->stop(); }

};





int main () {
    Proxy proxy;
    proxy.start();
    proxy.turnLeft();
    proxy.turnRight();
    proxy.stop();

    return 0;
}
