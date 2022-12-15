#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Component{
    public:
        virtual void operation() = 0;
};

class Box : public Component{ // Composite
    private:
        string name;
        vector<Component*> candyList;
    public:
        Box(string s){
            name = s;
        }
        void operation(){ // 상자와 내용물들 출력
            cout << "Box Name : " << name << endl;
            cout << "Info" << endl;
            for (int i = 0; i < candyList.size(); i++){
                candyList[i]->operation();
            }
            cout << "End Box " << name << endl;
        }
        void add(Component* component){ // 캔디 리스트에 새로운 캔디 추가
            candyList.push_back(component);
        }
        // remove, get은 생략
};

class Candy : public Component{ // Leaf
    private:
        string taste;
    public:
        Candy(string s){
            taste = s;
        }
        void operation(){ // 캔디 출력
            cout << "- " << taste << " Candy" << endl;
        }
};

int main(){
    Candy* c1 = new Candy("Coffee");
    Candy* c2 = new Candy("Strawberry");
    Candy* c3 = new Candy("Grape");
    Candy* c4 = new Candy("Apple");
    Box* box1 = new Box("For Soohyun");
    Box* box2 = new Box("For Minju");

    box2->add(c1);
    box2->add(c2);
    box1->add(box2);
    box1->add(c3);
    box1->add(c4);

    box1->operation();

    return 0;
}