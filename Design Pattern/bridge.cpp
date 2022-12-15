#include <iostream>
using namespace std;

class DrawAngleShape{ // Implementor, 도형을 그리는 자세한 부분
    public:
        virtual void drawing(int w, int h) = 0; // OperationImp()
};

class DrawRectangle : public DrawAngleShape{
    public:
        void drawing(int w, int h){
            cout << "Rectangle : " << w << " * " << h << " = " << w*h << endl;
        }
};

class DrawTriangle : public DrawAngleShape{
    public:
        void drawing(int w, int h){
            cout << "Triangle : " << w << " * " << h << " * 1/2 = " << w*h*0.5 << endl;
        }
};

class Shape{ // Abstraction, 사용자가 실제 사용하는 부분
    public:
        virtual void draw() = 0; // Operation()
};

class angleShape : public Shape{
    private:
        int width;
        int height;
        DrawAngleShape* Tool;
    public:
        angleShape(int w, int h, DrawAngleShape* d){
            width = w;
            height = h;
            Tool = d;
        }
        void draw(){
            Tool->drawing(width, height);
        }
};

int main(){
    DrawTriangle* Tool_3 = new DrawTriangle();
    DrawRectangle* Tool_4 = new DrawRectangle();

    // 사용자는 그림 그려주는 툴을 angleShape에 넣기만 해서 사용한다.
    angleShape* myTriangle = new angleShape(10, 10, Tool_3);
    angleShape* myRectangle = new angleShape(10, 10, Tool_4);
    myTriangle->draw();
    myRectangle->draw();

    return 0;
}