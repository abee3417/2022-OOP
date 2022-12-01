#include <iostream>
using namespace std;

class A{
    public:
    A(){cout << "A constructor" << endl;} 
    virtual ~A(){cout << "A destructor" << endl;}
    // virtual 안붙여주면 자식을 지울 때 자식 소멸자가 실행되지 않아 메모리 누수가 발생.
    // 그러므로 상속 시에 부모 클래스 소멸자에는 반드시 virtual을 붙여주자.
};

class B : public A{
    public:
    B(){cout << "B constructor" << endl;} 
    ~B(){cout << "B destructor" << endl;}
};

int main(){
    A* ptr = new B();
    delete ptr;
    return 0;
}