#include <iostream>
using namespace std;

class Coffee{
    private:
        int price;
    public:
        void setPrice(int p){
            price = p;
        }
        int getPrice(){
            return price;
        }
};

class Americano{
    private:
        int price;
    public:
        Americano(int a){ // case1
            price = a;
        }
        void setPrice(int p){
            price = p;
        }
        int getPrice(){
            return price;
        }
        operator int(){ // case2
            return price;
        }
        operator Coffee(){ // case3
            Coffee tmp;
            tmp.setPrice(price);
            return tmp;
        }
};

/*
case1 : constructor
case2 : member function (operator function)
case3 : either works (constructor, operator function)
*/

int main(){
    // Type Conversion : Three situations

    Americano a = 5000; // case1 : class = int (basic to class)
    cout << "case 1 price : " << a.getPrice() << endl; // print 5000

    int price = a; // case2 : int = class (class to basic)
    cout << "case 2 price : " << price << endl; // print 5000

    Coffee b;
    b = a; // case3 : class b = class a (class to class)
    cout << "case 3 price : " << b.getPrice() << endl; // print 5000

    return 0;
}