#include <iostream>
using namespace std;

class Coffee{ // AbstractProductA
    public:
        virtual void make() = 0;
};

class Americano : public Coffee{ // ProductA1
    public:
        void make(){
            cout << "Americano created" << endl;
        }
};

class Latte : public Coffee{ // ProductA2
    public:
        void make(){
            cout << "Latte created" << endl;
        }
};

class Food{ // AbstractProductB
    public:
        virtual void make() = 0;
};

class Sandwich : public Food{ // ProductB1
    public:
        void make(){
            cout << "Sandwich created" << endl;
        }
};

class Macaron : public Food{ // ProductB2
    public:
        void make(){
            cout << "Macaron created" << endl;
        }
};

class set_Factory{ // AbstractFactory
    public:
        virtual Coffee* create_coffee() = 0;
        virtual Food* create_food() = 0;
};

class setA_Factory{ // ConcreteFactory1
    // 아메리카노와 샌드위치 세트를 만드는 팩토리
    public:
        Coffee* create_coffee(){
            return new Americano();
        }
        Food* create_food(){
            return new Sandwich();
        }
};

class setB_Factory{ // ConcreteFactory2
    // 라떼와 마카롱 세트를 만드는 팩토리
    public:
        Coffee* create_coffee(){
            return new Latte();
        }
        Food* create_food(){
            return new Macaron();
        }
};

int main(){
    // setA, setB를 만드는 Factory
    setA_Factory* f1 = new setA_Factory();
    setB_Factory* f2 = new setB_Factory();
    // 커피컵과 음식담을 그릇 준비
    Coffee* coffee_cup;
    Food* food_plate;
    // 컵과 그릇에 세트를 담는다.
    coffee_cup = f1->create_coffee();
    coffee_cup->make();
    food_plate = f1->create_food();
    food_plate->make();

    return 0;
}