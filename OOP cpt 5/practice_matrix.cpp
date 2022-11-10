#include <iostream>
#include <cstdlib>
using namespace std;

class Matrix{
    private:
        static int count;
        static int max;
        int r, c;
        int **arr;
        void alloc(){
            arr = new int*[2];
            for (int i = 0; i < r; i++){    
                arr[i] = new int[c];
            }
        }
        void set(int v){
            for (int i = 0; i < r; i++){
                for (int j = 0; j < c; j++){
                    arr[i][j] = v;
                }
            }
        }
    public:
        Matrix(int n){
            r = 2;
            c = 2;
            alloc();
            set(n);
            count++;
        }
        Matrix(const Matrix &m){ // 복사생성자 사용
            r = 2;
            c = 2;
            alloc();
            for (int i = 0; i < r; i++){
                for (int j = 0; j < c; j++){
                    arr[i][j] = m.arr[i][j];
                }
            }
            count++;
        }
        ~Matrix(){
            for (int i = 0; i < r; i++){
                delete[] arr[i];
            }
            delete[] arr;
            count--;
            cout << "Destructor called. count : " << count << endl;
        }
        void display(){
            for (int i = 0; i < 2; i++){
                for (int j = 0; j < 2; j++){
                    cout << arr[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
        static int getCount(){
            return count;
        }
        operator int(){
            int max = 0;
            for (int i = 0; i < r; i++){
                for (int j = 0; j < c; j++){
                    if (max < arr[i][j]){
                        max = arr[i][j];
                    }
                }
            }
            return max;
        }
};

int Matrix::count = 0;

int main(){
    Matrix a = 1;
    Matrix b = 2;
    Matrix c = b; // 복사생성자! (얕은복사는 그냥 c = b이다.)

    a.display();
    b.display();
    c.display();

    int max = c;
    cout << "max : " << max << endl;
    cout << "matrix count : " << Matrix::getCount() << endl << endl;

    return 0;
}