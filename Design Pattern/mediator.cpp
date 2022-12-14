// Mediator Pattern
#include <iostream>
#include <cstring>
using namespace std;

class Mediator{
    public:
        virtual void Notify(string event) = 0;
};

class Student{ // Colleague
    protected:
        Mediator* mediator;
        int damage = 0;
    public:
        void setMediator(Mediator* m){
            mediator = m;
        }
};

class MSstudent : public Student{ // ConcreteColleague1
    public:
        // event가 발생하면 mediator의 notify에 event를 넘겨줘서 처리하게한다.
        void MSattack(){
            mediator->Notify("MS attack");
        }
        // mediator로부터 event를 받으면 데미지를 입는다.
        void MSdamage(){
            damage++;
            cout << "MS Damage : " << damage << endl;
        }
};

class EEstudent : public Student{ // ConcreteColleague2
    public:
        // event가 발생하면 mediator의 notify에 event를 넘겨줘서 처리하게한다.
        void EEattack(){
            mediator->Notify("EE attack");
        }
        // mediator로부터 event를 받으면 데미지를 입는다.
        void EEdamage(){
            damage++;
            cout << "EE Damage : " << damage << endl;
        }
};


class StudentMediator : public Mediator{ // ConcreteMediator
    private:
        MSstudent* msstudent;
        EEstudent* eestudent;
    public:
        StudentMediator(MSstudent* s1, EEstudent* s2){
            msstudent = s1;
            eestudent = s2;
            // s1, s2에 들어가서 현재의 mediator을 넣어준다.
            msstudent->setMediator(this);
            eestudent->setMediator(this);
        }
        void Notify(string event){ // student에게 event를 받으면 처리한다.
            cout << event << endl;
            if (event == "MS attack"){
                eestudent->EEdamage();
            }
            if (event == "EE attack"){
                msstudent->MSdamage();
            }
        }
};

int main(){
    MSstudent* yunseong = new MSstudent();
    EEstudent* mingi = new EEstudent();
    StudentMediator* DKUmediator = new StudentMediator(yunseong, mingi);

    yunseong->MSattack();
    mingi->EEattack();
    yunseong->MSattack();

    return 0;
}