// Strategy Pattern
#include <iostream>
using namespace std;

class CoffeeCapsule{ // Strategy
    public:
        virtual void explain() = 0; // AlgorithmInterface()
};

class AmericanoCapsule: public CoffeeCapsule{ // ConcreteStrategyA
    public:
        void explain(){
            cout << "Americano : Espresso" << endl;
        }
};

class LatteCapsule : public CoffeeCapsule{ // ConcreteStrategyB
    public:
        void explain(){
            cout << "Latte : Espresso + Milk" << endl;
        }
};

class CoffeeMachine{ // Context
    private:
        CoffeeCapsule* capsule;
    public:
        CoffeeMachine(CoffeeCapsule* c){
            capsule = c;
        }
        void changeCapsule(CoffeeCapsule* newcapsule){
            delete capsule; // 현재 캡슐은 지우고 (숨기고)
            capsule = newcapsule; // 새로운 캡슐을 커피머신에 넣는다.
        }
        void makeCoffee(){ // 커피 제작
            capsule->explain();
        }
};

int main(){
    CoffeeMachine* Nespresso = new CoffeeMachine(new AmericanoCapsule());
    Nespresso->makeCoffee();
    Nespresso->changeCapsule(new LatteCapsule());
    Nespresso->makeCoffee();
    return 0;
}