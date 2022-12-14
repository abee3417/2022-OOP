// Memento Pattern
#include <iostream>
#include <vector>
using namespace std;

class Memento{
    private:
        int state;
    public:
        void setState(int v){
            state = v;
        }
        int getState(){
            return state;
        }
};

class Originator{ // memento 전용 관리 클래스
    private:
        int state = 0;
    public:
        Memento* createMemento(){ // memento를 생성해준다.
            cout << "Save state " << state << endl;
            Memento* temp = new Memento();
            temp->setState(state);
            return temp;
        }
        void Upgrade(){ // memento 버전업그레이드
            cout << "Upgrade state " << state;
            state++;
            cout << " to state " << state << endl;
        }
        void setMemento(Memento* memento){ // 해당하는 memento 버전을 가져와준다.
            state = memento->getState();
            cout << "Restore state " << state << endl;
        }
};

class CareTaker{ // memento 버전을 관리하는 클래스
    private:
        vector<Memento*> mlist;
        Originator* myO;
    public:
        CareTaker(Originator* o){
            myO = o;
        }
        void Backup(){ // 저장하기
            mlist.push_back(myO->createMemento()); // 새로운 버전을 저장
        }
        void Undo(int n){ // 불러오기
            myO->setMemento(mlist[n]);
        }
};

int main(){
    Originator* o = new Originator();
    CareTaker* c = new CareTaker(o);
    c->Backup();
    o->Upgrade();
    c->Backup();
    o->Upgrade();
    c->Backup();

    c->Undo(1);
    return 0;
}