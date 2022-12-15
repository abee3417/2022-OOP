#include <iostream>
using namespace std;

class CPU{
    public:
        void freeze(){
            cout << "CPU Freeze" << endl;
        }
        void execute(){
            cout << "CPU Execute" << endl;
        }
        void jump(){
            cout << "CPU Jump" << endl;
        }
};

class Memory{
    public:
        void load(){
            cout << "Memory Load" << endl;
        }
        void save(){
            cout << "Memory Save" << endl;
        }
};

class SSD{
    public:
        void read(){
            cout << "SSD read" << endl;
        }
};

class Computer{ // Facade, 사용자는 파사드 하나로 모든 클래스를 관리
    private:
        CPU* myCPU;
        Memory* myMemory;
        SSD* mySSD;
    public:
        Computer(CPU* c, Memory* m, SSD* s){
            myCPU = c;
            myMemory = m;
            mySSD = s;
        }
        void startRun(){
            myCPU->freeze();
            myMemory->load();
            myCPU->jump();
            myCPU->execute();
            mySSD->read();
            myMemory->save();
        }
};

int main(){
    // 사용자가 부품을 사고
    CPU* intel_i5 = new CPU();
    Memory* ram_16gb = new Memory();
    SSD* samsung = new SSD();
    // 부품을 컴퓨터에 조립하고
    Computer* myComputer = new Computer(intel_i5, ram_16gb, samsung);
    // 컴퓨터 전원버튼만 누르면 컴퓨터가 알아서 작동한다.
    myComputer->startRun();
    return 0;
}