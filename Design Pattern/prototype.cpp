#include <iostream>
#include <cstring>
using namespace std;

class Prototype{
    protected:
        string name;
    public:
        virtual Prototype* clone() = 0;
        void print(){
            cout << name << " Latte" << endl;
        }
        void setName(string n){
            name = n;
        }
};

class Latte_Prototype : public Prototype{
    public:
        Latte_Prototype(string n){
            name = n;
        }
        Prototype* clone(){
            return new Latte_Prototype(*this);
        }
};

int main(){
    Prototype* Basic_Latte = new Latte_Prototype("Normal");
    // choco에 basic 복사
    Prototype* Choco_Latte = Basic_Latte->clone();
    // choco에 basic이 그대로 복사된 것을 확인할 수 있다.
    Basic_Latte->print(); // Noraml Latte
    Choco_Latte->print(); // Noraml Latte

    // 이제 라떼를 가져왔으니 이름을 바꿔주자.
    Choco_Latte->setName("Choco");
    Choco_Latte->print(); // Choco Latte
    return 0;
}