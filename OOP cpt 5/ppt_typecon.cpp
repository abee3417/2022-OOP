#include <iostream>

using namespace std;

class dst{
    int code;
    public:
        void setcode(int a){
            code = a;
        }
        void display(){
            cout << "dst code = " << code << endl;
        }
};

class src{
    int code;
    public:
        src(int a){
            code = a;
        }
        void display(){
            cout << "src code = " << code << endl;
        }
        operator int(){
            return code * code;
        }
        operator dst(){
            dst d;
            d.setcode(code*code);
            return d;
        }
};

int main(){
    src s = 5;
    s.display();

    int val = s;
    cout << "val = " << val << endl;

    dst d;
    d = s;
    d.display();

    return 0;
}