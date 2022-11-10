#include <iostream>
#include <string>

using namespace std;

// Account Ŭ���� �ۼ�
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

        // �Ա�
        void Deposit(int money){      
            this->balance += money;
        }

        // ���
        void WithDraw(int money) {
            this->balance -= money;
        }

        // ������ȸ
        void Show() {
            cout << "���� �� ���� ��: " << account_count << endl;
            cout << "����ID: " << this->ID << endl;
            cout << "�̸�: " << this->name << endl;
            cout << "�ܾ�: " << this->balance << endl << endl;
        }
};

int Account::account_count = 0;

int main(){
    /* 1�ܰ� �׽�Ʈ�� main�Լ� */
    Account* user1 = new Account(1234, 10000, "�����");
    user1->Deposit(5000);
    user1->Show();

    Account* user2 = new Account(5678, 10000, "�ڼ���");
    user2->WithDraw(5000);
    user2->Show();

    return 0;
}


 /*
    <2�ܰ���� ����� main�Լ��Դϴ� �ǵ��� �� ��.>
int main(){
   
    int option;
    while (1){

        cout << "-----Menu-----" << endl;
        cout << "1. ���°���" << endl;
        cout << "2. �Ա�" << endl;
        cout << "3. ���" << endl;
        cout << "4. ���¹�ȣ ��ü ���" << endl;
        cout << "5. ���α׷� ����" << endl;
        cout << "���� : ";

        cin >> option;
        cout << endl;

       switch(option){
        case 1: //���� ����
            //MakeAccount();
            break;
        case 2: //�Ա�
            //DepositMoney();
            break;
        case 3: //���
            //WithdrawMoney();
            break;
        case 4: //���¹�ȣ ��ü ���
            //ShowAll();
            break;
        case 5: //���α׷� ����
            return 0;
        default:
            cout << "�߸��� ����" << endl;
        }
    }
    return 0;
}

*/