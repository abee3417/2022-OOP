#include <iostream>
using namespace std;

class Animal{
    private:
        int height;
    public:
        virtual ~Animal(){} // 부모 클래스의 소멸자에는 반드시 virtual을 붙여줄 것.
        virtual void speak(){
            cout << "Animal" << endl;
        }
    
};

class Cat : public Animal{
    private:
        int weight;
    public:
        ~Cat(){}
        void speak(){
            cout << "Cat" << endl;
        }
};

int main(){
    cout << "Animal Size : " << sizeof(Animal) << endl;
    cout << "Cat Size : " << sizeof(Cat) << endl;

    Animal * test = new Cat(); // 다형성
    test->speak();
    // Animal.speak()에 virtual붙이면 사이즈가 8, 12 안붙이면 4, 8
}