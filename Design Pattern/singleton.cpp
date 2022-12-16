// 전역 변수마냥, 전역 객체를 사용하고 싶을 때 : singletone

#include <iostream>
using namespace std;

class Singleton{
    private:
        static Singleton* instance;
    public:
        static Singleton* getInstance();
        static int add(int n1, int n2){
            return n1 + n2;
        }
};

Singleton* Singleton::instance = 0; // static 변수는 전역변수로 초기화
Singleton* Singleton::getInstance(){
    if (instance == 0){ // instance가 비어있으면 (최초의 상태)
        instance = new Singleton(); // 객체를 할당해준다.
    }
    // 즉, 이미 객체가 instance에 있다면 if문을 통과하지 않고 기존의 객체를 return해준다.
    return instance; 
}

int main(){
    int result;
    result = Singleton::add(50, 50); // 싱글톤의 add함수 사용 가능
    cout << result << endl;
    return 0;
}