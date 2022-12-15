#include <iostream>
#include <cstring>
using namespace std;

class Coffee{ // Component
    public:
        virtual string operation() = 0;
};

class Frappuccino : public Coffee{ // ConcreteComponent
    public:
        string operation(){
            return "Frappuccino";
        }
};

class Decorator : public Coffee{ // Decorator
    protected:
        Coffee* coffee;
    public:
        string operation(){
            return coffee->operation();
        }
};

class Javachip_Decorator : public Decorator{ // ConcreteDecoratorA
    public:
        Javachip_Decorator(Coffee* c){
            coffee = c;
        }
        string operation(){
            return "Java Chip " + Decorator::operation();
        }
};

class Mocha_Decorator : public Decorator{ // ConcreteDecoratorB
    public:
        Mocha_Decorator(Coffee* c){
            coffee = c;
        }
        string operation(){
            return "Mocha " + Decorator::operation();
        }
};

int main(){
    Coffee* myCoffee = new Frappuccino(); // 내 프라푸치노를 만든다.
    cout << myCoffee->operation() << endl;
    myCoffee = new Javachip_Decorator(myCoffee); // 자바칩프라푸치노로 데코한다.
    cout << myCoffee->operation() << endl;
    myCoffee = new Mocha_Decorator(myCoffee); // 모카프라푸치노로 데코한다.
    cout << myCoffee->operation() << endl;
    return 0;
}