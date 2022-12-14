// Observer Pattern
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Subscriber{ // Observer
    public:
        virtual void update() = 0;
};

class Publisher{ // Subject
    public:
        virtual void attach(Subscriber* sub) = 0;
        virtual void notify() = 0;
};

class NewsPublisher : public Publisher{ // ConcreteSubject
    private:
        vector<Subscriber*> subList; // 구독자 리스트
        string news;
    public:
        void attach(Subscriber* sub){ // 구독자를 추가해준다.
            subList.push_back(sub);
        }
        void detach(){ // 구독자를 제거해준다.
            subList.pop_back();
        }
        void notify(){ // 구독자에게 뉴스를 알려준다.
            for (int i = 0; i < subList.size(); i++){
                subList[i]->update();
            }
        }
        void setNews(string msg){ // 뉴스 설정
            news = msg;
            notify(); // 뉴스가 새로 만들어졌으니 알린다.
        }
        string getNews(){ // 뉴스 반환
            return news;
        }
};


class SMSSubscriber : public Subscriber{ // ConcreteObserver
    private:
        string name;
        NewsPublisher* SMSPub;
    public:
    SMSSubscriber(string n, NewsPublisher* pub){ // 생성자에서 출판사에 자신을 등록한다.
        name = n;
        SMSPub = pub;
        SMSPub->attach(this);
    }
    void update(){ // 출판사로부터 업데이트 받는다.
        cout << name << " get news : " << SMSPub->getNews() << endl;
    }
};

class EmailSubscriber : public Subscriber{ // ConcreteObserver
    private:
        string name;
        NewsPublisher* EmailPub;
    public:
    EmailSubscriber(string n, NewsPublisher* pub){ // 생성자에서 출판사에 자신을 등록한다.
        name = n;
        EmailPub = pub;
        EmailPub->attach(this);
    }
    void update(){ // 출판사로부터 업데이트 받는다.
        cout << name << " get news : " << EmailPub->getNews() << endl;
    }
};

int main(){
    // Test
    NewsPublisher* DKU = new NewsPublisher();
    SMSSubscriber* yys = new SMSSubscriber("Yunseong", DKU);
    SMSSubscriber* psh = new SMSSubscriber("Soohyun", DKU);
    EmailSubscriber* kmj = new EmailSubscriber("Minju", DKU);

    DKU->setNews("Notice! 12.19 OOP Final");
}