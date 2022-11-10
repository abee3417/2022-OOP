// Copy constructor
#include <iostream>
using namespace std;

class OOP{
    private:
        int *m;
    public:
        OOP(){ // Default Constructor
            m = new int(0);
        } 
        OOP(OOP& A){ // Copy constructor
            m = new int(0);
            *m = *(A.m);
        } 
        void set(int v){ // v로 바꿔주는 메소드
            *m = v;
        }
        void display(){
            cout << *m << endl;
        }
};
int main() {
    OOP a; // Default Constructor로 a.*m이 0으로 자동 초기화
    OOP b; // Default Constructor로 b.*m이 0으로 자동 초기화
    b.set(5); // b.*m이 5로 변경
    OOP c(b); // b는 OOP매개변수 이므로 Copy Constructor가 실행, c.*m = 5 -> deep copy
    OOP d;
    d = b; // shallow copy
    d.set(2); // 얕은 복사이므로 d.*m이랑 b.*m 둘다 2로 변경된다!
    a.display(); // 0
    b.display(); // 2
    c.display(); // 5
    d.display(); // 2
    

    return 0;
}