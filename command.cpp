#include <iostream>
#include <vector>

using namespace std;


class Command{
public:
    virtual void execute()=0;
};

class Jump : public Command{
    void execute(){ cout<<"jumping jumping"<<endl; }
};

class Swim : public Command{
    void execute(){ cout<<"Swimming"<<endl; }
};

class ShowLine : public Command{
    void execute() {cout<<__LINE__<<endl;}
};

class ShowFile :public Command{
    void execute() {cout<<__FILE__<<endl; }
};


class CommandDispatcher{
public:
    void add(Command * com){
        commands.push_back(com);
    }
    void run(){
        vector<Command*>::iterator it =commands.begin();
        while(it !=commands.end()){
            (*it++)->execute();
        }
    }

private:
    vector<Command*> commands;
};

int main(){
    CommandDispatcher commandDispatcher;

    commandDispatcher.add(new Jump);
    commandDispatcher.add(new Swim);
    commandDispatcher.add(new ShowLine);
    commandDispatcher.add(new ShowFile);
    commandDispatcher.run();


    return 0;
}
