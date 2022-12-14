// Iterator Pattern
#include <iostream>
#include <vector>
using namespace std;

class Data{
    private:
        int data;
    public:
        Data(int n){
            data = n;
        }
        void setData(int n){
            data = n;
        }
        int getData(){
            return data;
        }
};

typedef typename vector<Data>::iterator iter_type;
class Iterator{
    private:
        vector<Data>* myDataSet;
        iter_type current;
    public:
        Iterator(vector<Data>* dataSet){
            myDataSet = dataSet;
        }
        void First(){ // 벡터의 첫번째 값을 current에 초기화해준다.
            current = myDataSet->begin();
        }
        void Next(){
            current++;
        }
        bool IsDone(){
            if (current == myDataSet->end()){
                return 1; // 벡터의 마지막 값과 current가 같으면 True
            }
            else{
                return 0;
            }
        }
        iter_type getCurrent(){
            return current;
        }
};

int main(){
    vector<Data> testSet;
    Data a(100), b(1000), c(10000);
    testSet.push_back(a);
    testSet.push_back(b);
    testSet.push_back(c);

    // Test
    Iterator* testIt = new Iterator(&testSet);
    for (testIt->First(); !testIt->IsDone(); testIt->Next()){
        cout << testIt->getCurrent()->getData() << endl;
    }
    return 0;
}