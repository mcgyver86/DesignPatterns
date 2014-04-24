#include <iostream>
#include <string>


using namespace std;



class IBehaviour {
   public :
      virtual int moveCommand() =0;
};

class AgressiveBehaviour : public IBehaviour{
    public:
        int moveCommand()
    {
        cout<<"\tAgressive Behaviour: if find another robot attack it"<<endl;
        return 1;
    }
};

class DefensiveBehaviour: public IBehaviour{
    public:
         int moveCommand()
    {
        cout<<"\tDefensive Behaviour: if find another robot run from it"<<endl;;
        return -1;
    }
};

class NormalBehaviour : public IBehaviour{
    public :
            int moveCommand()
    {
        cout<<"\tNormal Behaviour: if find another robot ignore it"<<endl;;
        return 0;
    }
};

class Robot {
  public:


    Robot(string input)
    {
        name = input;
                behaviour=0;
    }
    ~Robot(){
        if(behaviour){
            delete behaviour;
            behaviour =0;
        }
    }
     void setBehaviour(IBehaviour* ibehaviour)
    {
         if(behaviour) {
             delete behaviour;
             behaviour = 0;
         }
         behaviour = ibehaviour;
    }

        IBehaviour* getBehaviour()
    {
        return behaviour;
    }

    void move()
    {
          if(!behaviour) { cout<<"error"<<endl; return;}
        cout<<name <<": Based on current position" <<
                     "the behaviour object decide the next move:"<<endl;
        int command = behaviour->moveCommand();
        // ... send the command to mechanisms
        cout<<"\tThe result returned by behaviour object " <<
                    "is sent to the movement mechanisms " <<
                    " for the robot '" << name <<"'"<<endl;
    }

     string getName() {
        return name;
    }

     void setName(string iname) {
        name = iname;
    }
        private:

        IBehaviour *behaviour;
    string name;
};




int main(){
  Robot* r1 = new Robot("Big Robot");
        Robot* r2 = new Robot("George v.2.1");
        Robot* r3 = new Robot("R2");

        IBehaviour* pAgressive = new AgressiveBehaviour;
        IBehaviour* pDefenssive= new DefensiveBehaviour;
        IBehaviour* pNormal    = new NormalBehaviour;

        pAgressive->moveCommand();
        pAgressive->moveCommand();

        //r1->setBehaviour(new AgressiveBehaviour );
        //r2->setBehaviour(new DefensiveBehaviour);
        //r3->setBehaviour(new NormalBehaviour );

        r1->setBehaviour(pAgressive);
        r2->setBehaviour(pDefenssive);
        r3->setBehaviour(pNormal );

        r1->move();
        r2->move();
        r3->move();

        cout<<"\r\nNew behaviours: " <<
                "\r\n\t'Big Robot' gets really scared" <<
                "\r\n\t, 'George v.2.1' becomes really mad because" <<
                "it's always attacked by other robots" <<
                "\r\n\t and R2 keeps its calm"<<endl;

        //r1->setBehaviour(new DefensiveBehaviour());
        //r2->setBehaviour(new AgressiveBehaviour());

        r1->setBehaviour(pDefenssive);
        r2->setBehaviour(pAgressive);

        r1->move();
        r2->move();
        r3->move();

        delete pAgressive;
        delete pDefenssive;
        delete pNormal;
  return 0;
}
