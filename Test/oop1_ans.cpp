#include <iostream>
#include <string>

using namespace std;

// Account 클래스 작성
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
            cout << "현재 총 계좌 수: " << account_count << endl;
            cout << "계좌ID: " << this->ID << endl;
            cout << "이름: " << this->name << endl;
            cout << "잔액: " << this->balance << endl << endl;
        }
};

int Account::account_count = 0;

int main(){
    /* 1단계 테스트용 main함수 */
    Account* user1 = new Account(1234, 10000, "김민주");
    user1->Deposit(5000);
    user1->Show();

    Account* user2 = new Account(5678, 10000, "박수현");
    user2->WithDraw(5000);
    user2->Show();

    return 0;
}


 /*
    <2단계부터 사용할 main함수입니다 건들지 말 것.>
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

*/