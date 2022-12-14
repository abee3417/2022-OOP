// Chain of Responsibility Pattern
#include <iostream>
#include <cstring>
using namespace std;

class Handler{
    public:
        virtual void setNext(Handler* handler) = 0;
        virtual void process(int request)= 0;
};

class absHandler : public Handler{
    private:
        Handler* next;
    public:
        void setNext(Handler* handler){
            this->next = handler;
        }
        void process(int request){
            this->next->process(request);
        }
};

class cashHandler : public absHandler{
    public:
        void process(int request){
            if (request == 1){
                cout << "Cash Pay Sucess" << endl;
            }
            else{
                cout << "Cash Error" << endl;
                absHandler::process(request);
            }
        }
};

class creditHandler : public absHandler{
    void process(int request){
            if (request == 2){
                cout << "Credit Pay Sucess" << endl;
            }
            else{
                cout << "Credit Error" << endl;
                absHandler::process(request);
            }
        }
};

class mobileHaneler : public absHandler{
    void process(int request){
            if (request == 3){
                cout << "Mobile Pay Sucess" << endl;
            }
            else{
                cout << "Mobile Error" << endl;
                absHandler::process(request);
            }
        }
};

int main(){
    int payCode = 3;
    int result;
    cashHandler* cashH = new cashHandler();
    creditHandler* creditH = new creditHandler();
    mobileHaneler* mobileH = new mobileHaneler();

    // Chaining Objects
    cashH->setNext(creditH);
    creditH->setNext(mobileH);

    // Test
    cashH->process(payCode);
    return 0;
}