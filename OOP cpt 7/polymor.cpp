#include <iostream>
using namespace std;

class Person{
    char *name;
    public:
    Person(){
        name = new char[5];
        cout << "Person Structor" << endl;    
    }
    Person test(){
        return *this;
    }

};

class Student : public Person{
    int *age;
    public:
        Student() : Person(){
            age = new int(5);
            cout << "Student Structor" << endl;   
        }
};

int main(){
    Person* ptr;
    ptr = new Person();
    delete ptr;

    ptr = new Student();

    Student* ptr2;
    ptr2 = new Student(); // new Person()은 안됨.

    return 0;
}