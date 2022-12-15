#include <iostream>
using namespace std;

class Company{ // Subject
    public:
        virtual void request() = 0;
};

class CEO : public Company{ // RealSubject
    public:
        void request(){
            cout << "Go to Meeting" << endl;
        }
};

class Assistant : public Company{ // Proxy
    private:
        CEO* master;
    public:
        Assistant(CEO* ceo){ // 자신의 전속 상사를 등록
            master = ceo;
        }
        void request(){
            cout << "Assistant Proxy : ";
            master->request();
        }
};

int main(){
    CEO* Tim_Cook = new CEO();
    Tim_Cook->request();
    // 이제는 Proxy를 고용하여 CEO 대신 미팅을 나간다.
    Assistant* Andrew = new Assistant(Tim_Cook);
    Andrew->request();
    return 0;
}