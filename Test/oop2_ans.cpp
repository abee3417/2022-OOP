#include <iostream>
#include <string>

using namespace std;

class Account{
    static int account_count;

    private:
        int ID;
        int balance;
        string name;
    public:
        Account(int ID, int balance, string name){
            this->ID = ID;
            this->balance = balance;
            this->name = name;
            account_count++;
        }

        int getID(){ return this->ID; }

        // 입금
        void Deposit(int money){      
            this->balance += money;
        }

        // 출금
        void WithDraw(int money) {
            this->balance -= money;
        }

        // 계좌조회
        void Show() {
            cout << "계좌ID: " << this->ID << endl;
            cout << "이름: " << this->name << endl;
            cout << "잔액: " << this->balance << endl << endl;
        }
};

Account* arr[100];
int account_num = 0;

void MakeAccount() {
    int id, balance;
    string name;

    cout << "[계좌개설]" << endl;
    cout << "계좌ID: ";
    cin >> id;
    cout << "이름: ";
    cin >> name;
    cout << "입금액: ";
    cin >> balance;
    cout << endl;

    arr[account_num++] = new Account(id, balance, name);
}

void DepositMoney() {
    int id, money;
    cout << "[입금]" << endl;
    cout << "계좌ID: "; cin >> id;
    cout << "입금액: "; cin >> money;

    for (int i = 0; i < account_num; i++){
        if (arr[i]->getID() == id){
            arr[i]->Deposit(money);
            cout << "입금완료" << endl << endl;
            break;
        }
    }
}

void WithdrawMoney() {
    int id, money;
    cout << "[출금]" << endl;
    cout << "계좌ID: "; cin >> id;
    cout << "출금액: "; cin >> money;

    for (int i = 0; i < account_num; i++){
        if (arr[i]->getID() == id){
            arr[i]->WithDraw(money);
            cout << "출금완료" << endl << endl;
            break;
        }
    }
}

void ShowAll(){
    for (int i = 0; i < account_num; i++){
        arr[i]->Show();
    }
}

int main(){
   
    int option;
    while (1){

        cout << "-----Menu-----" << endl;
        cout << "1. 계좌개설" << endl;
        cout << "2. 입금" << endl;
        cout << "3. 출금" << endl;
        cout << "4. 계좌번호 전체 출력" << endl;
        cout << "5. 프로그램 종료" << endl;
        cout << "선택 : ";

        cin >> option;
        cout << endl;

       switch(option){
        case 1: //계좌 개설
            //MakeAccount();
            break;
        case 2: //입금
            //DepositMoney();
            break;
        case 3: //출금
            //WithdrawMoney();
            break;
        case 4: //계좌번호 전체 출력
            //ShowAll();
            break;
        case 5: //프로그램 종료
            return 0;
        default:
            cout << "잘못된 선택" << endl;
        }
    }
    return 0;
}