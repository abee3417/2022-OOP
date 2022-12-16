// 피자를 만드는데 도우, 소스, 토핑 등 하나씩 하면 힘들다 -> 하나로 축약한 것이 builder
#include <iostream>
#include <cstring>
using namespace std;

class Pizza{ // Product
    private:
        string dough;
        string sauce;
        string topping;
    public:
        void setDough(string d){
            dough = d;
        }
        void setSauce(string s){
            sauce = s;
        }
        void setTopping(string t){
            topping = t;
        }
        void print(){
            cout << "Dough : " << dough << " / Sauce : " << sauce << " / Topping : " << topping << endl;
        }
};

class PizzaBuilder{ // Builder
    public:
        // 피자 Builder은 만들기,도우,소스,토핑,안내를 해준다.
        virtual void createPizza() = 0;
        virtual void buildDough() = 0;
        virtual void buildSauce() = 0;
        virtual void buildTopping() = 0;
        virtual void guidePizza() = 0;
};

class potatoPizzaBuilder : public PizzaBuilder{ // ConcreteBuilder
    private:
        Pizza* pizza;
    public:
        void createPizza(){
            pizza = new Pizza();
        }
        void buildDough(){
            pizza->setDough("Cross");
        }
        void buildSauce(){
            pizza->setSauce("Tomato");
        }
        void buildTopping(){
            pizza->setTopping("Potato");
        }
        void guidePizza(){
            pizza->print();
        }
};

class PizzaShef{ // Director
    private:
        PizzaBuilder* build;
    public:
        void setBuilder(PizzaBuilder* b){ // 빌더를 결합해준다.
            build = b;
        }
        void cook(){ // cook을 하면 피자의 제작 과정을 한번에 다해준다.
            build->createPizza();
            build->buildDough();
            build->buildSauce();
            build->buildTopping();
            build->guidePizza();
        }
};

int main(){
    // 포테이토피자 빌더를 선언해주고
    potatoPizzaBuilder* potato_pizza = new potatoPizzaBuilder();
    // 고든램지에게 포테이토피자 빌더를 주면
    PizzaShef* Ramsay = new PizzaShef();
    Ramsay->setBuilder(potato_pizza);
    // 고든램지가 포테이토피자를 알아서 만들어준다.
    // 즉 사용자는 Director만을 이용해 복잡한 과정을 전부할 수 있다.
    Ramsay->cook();
    return 0;
}