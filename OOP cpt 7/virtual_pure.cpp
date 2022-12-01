#include <iostream>


class Animal{
    public:
        virtual void speak() = 0; // 순수가상함수는 반드시 자식에서 오버라이딩
};

class Cat : public Animal{
    public:
        void speak(){
            std::cout << "hello";
        }
};

int main(){
    Animal *test = new Cat();
    return 0;
}