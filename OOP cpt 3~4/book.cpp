#include <iostream>
#include <string>
using namespace std;

class book{
    static int total;
    private:
        string file;
        int price;
    public:
        void fill(){
            cout << "Enter book name : ";
            cin >> this->file;
            cout << "Enter book's price : ";
            cin >> this->price;
            sum(this->price);
        }
        void print(){
            cout << "Book name : " << this->file << endl;
            cout << "Price : " << this->price << endl;
            cout << "Current Total Price : " << total << endl;
        }
        static void sum(int price){
            total += price;
        }
};

int book::total = 0;

int main(){
    book b1, b2, b3;
    b1.fill();
    b1.print();
    b2.fill();
    b2.print();
    b3.fill();
    b3.print();
    return 0;
}