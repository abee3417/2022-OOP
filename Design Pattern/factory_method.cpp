#include <iostream>
using namespace std;

class Coffee{ // Product
    public:
        virtual string operation() = 0;
};

class Americano : public Coffee{ // ConcreteProduct
    public:
        string operation(){
            return "Americano";
        }
};

class Mocha : public Coffee{ // ConcreteProduct
    public:
        string operation(){
            return "Mocha";
        }
};

class Fcoffee{ // Creator
    public:
        virtual Coffee* FactoryMethod() = 0;
        string anOperation(){ // 객체의 operation()을 실행시켜주는 멤버함수
            // 본인의 FactoryMethode를 찾아 temp에 넣어주고, operation()을 실행한다.
            Coffee* temp = this->FactoryMethod();
            string result = temp->operation();
            // temp 할당 해제해주고 operation()결과를 출력
            delete temp;
            cout << result << endl;
            return result;
        }
};

class Famericano : public Fcoffee{ // ConcreteCreator
    public:
        Coffee* FactoryMethod(){
            return new Americano();
        }
};

class Fmocha : public Fcoffee{ // ConcreteCreator
    public:
        Coffee* FactoryMethod(){
            return new Mocha();
        }

};

int main(){
    Fcoffee* coffee_factory_1 = new Famericano(); // 아메리카노 공장 세우기
    Fcoffee* coffee_factory_2 = new Fmocha(); // 모카 공장 세우기

    coffee_factory_1->anOperation(); // 아메리카노 공장 작동
    coffee_factory_2->anOperation(); // 모카 공장 작동
    
    delete coffee_factory_1;
    delete coffee_factory_2;
    return 0;
}