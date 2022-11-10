#include <iostream>
using namespace std;

class Person{
    private:
        long _identity;
    public:
        void setId(long identity){ // setter
            _identity = identity;
        }
        long getId(){ // getter
            return _identity;
        }
};

class Student : public Person{
    private:
        double _gpa;
    public:
        void setGPA(double gpa){
            _gpa = gpa;
        }
        double getGPA(){
            return _gpa;
        }
        
};

int main(){
    Person p;
    p.setId(100);
    // p._identity = 100; private이므로 오류 발생
    cout << p.getId() << endl;
    return 0;
}