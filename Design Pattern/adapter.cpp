#include <iostream>
using namespace std;

class V220{ // Adaptee
    public:
        void SpecificRequest(){
            cout << "220V Connected" << endl;
        }
};

class V110{ // Target
    public:
        void Request(){
            cout << "110V Connected" << endl;
        }
};

class VAdapter : public V110{ // Adpater
    private:
        V220* convertV;
    public:
        VAdapter(V220* v){
            convertV = v;
        }
        void Request(){ // 바꿀 타입의 메소드를 실행
            convertV->SpecificRequest();
        }
};


int main(){
    V110* USA = new V110();
    V220* Korea = new V220();
    // USA를 그냥 실행
    USA->Request();

    // 110v에 220v로 바꿔주는 Adapter을 꽂는다.
    VAdapter* adapter = new VAdapter(Korea);
    // USA에 Adapter을 꽂은 채 실행
    adapter->Request();
    
    return 0;
}