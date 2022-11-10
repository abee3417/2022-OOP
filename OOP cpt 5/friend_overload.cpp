#include <iostream>
using namespace std;

class complex{
    float x, y;
    public:
        complex(){
            x = y = 0;
        }
        complex(float real, float imag){
            x = real;
            y = imag;
        }
        friend complex operator+(int b, complex a){
            return complex(b + a.x, a.y);
        }
        void display(){
            cout << x << ", " << y << endl;
        }
};

int main(){
    complex c1(2.5, 3.5), c2(2.5, 3.5), c3;
    c3 = 2 + c1;
    c3.display();
    return 0;
}