// State Pattern
#include <iostream>
using namespace std;


class CoffeeMachine{ // Context
    private:
        State* state;
    public:
        CoffeeMachine(State* s){
            convert(s);
        }
        void convert(State* s){
            state = s;
            state->setMachine(this); // 업데이트한 state를 커피머신에 재설정
        }
        void button(){ // Request()
            state->handle(); // state 업데이트 호출
        }
};

class State{ // 상태를 관리하는 클래스
    protected:
        CoffeeMachine* myMachine;
    public:
        void setMachine(CoffeeMachine* Machine){
            myMachine = Machine;
        }
        virtual void handle() = 0;
};

class ReadyState : public State{
    public:
        void handle();
};

class OnState : public State{
    public:
        void handle();
};

class OffState : public State{
    public:
        void handle();
};

void ReadyState::handle(){
    cout << "Convert [Ready] -> [On]" << endl;
    myMachine->convert(new OnState);
}

void OnState::handle(){
    cout << "Convert [On] -> [Off]" << endl;
    myMachine->convert(new OffState);
}

void OffState::handle(){
    cout << "Convert [On] -> [Off]" << endl;
    myMachine->convert(new ReadyState);
}


int main(){
    CoffeeMachine* Nespresso = new CoffeeMachine(new OffState());
    Nespresso->button();
    Nespresso->button();
    Nespresso->button();
    return 0;
}