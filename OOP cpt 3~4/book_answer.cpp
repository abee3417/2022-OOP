#include <iostream>
using namespace std;

class Book{
    private:
        static int total;
        char title[30];
        int price;
    public:
        void setValues(){
            cout << "title" << endl;
            cin >> title;
            cout << "price" << endl;
            cin >> price;
            total += price;
        }
        void display(){
            cout << title << "\t" << price << endl;
        }
        static void displayTotal(){
            cout << "Total price : " << total << endl;
        }
};

int Book::total = 0;

int main(){
    Book::displayTotal();

    Book b1, b2, b3;
    b1.setValues();
    b2.setValues();
    b3.setValues();

    b1.display();
    b2.display();
    b3.display();

    Book::displayTotal();
}