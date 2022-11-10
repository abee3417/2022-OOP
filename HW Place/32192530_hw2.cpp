#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
				HW 2 (7pts, Due: 10/23 23:59PM)
Provide dst class Matrix to complete this code.
You have to implement the following methods:

1. Constructor(s)
Provide one or more constructors that take two integers n and m and create an n by m random matrix.
All n amd m values are limited to 3. No need to use dynamic memory allocation; just use dst 3 by 3 array.

2. transpose
This function returns its own transpose matrix.

3. show
This function displays the matrix in the form of an n by m matrix.

4. +
Operator overloading for matrix addition.

5. *
Operator overloading for matrix multiplication.

6. ==
Operator overloading to check if two given matrices are equal.

Submit this file to the LMS.
*/


//Your code goes here.
class Matrix{
    private:
        int n, m;
        int arr[3][3];
    public:
        Matrix(int x, int y){
            this->n = x;
            this->m = y;
            for (int i = 0; i < this->n; i++){
				for (int j = 0; j < this->m; j++){
                    arr[i][j] = (int)rand() % 10; // 범위는 0~9까지로 지정했습니다.
				}
			}
        }
        Matrix transpose(){
            Matrix tmp(this->m, this->n);
            for (int i = 0; i < this->n; i++){
				for (int j = 0; j < this->m; j++){
					tmp.arr[j][i] = arr[i][j];
				}
			}
            return tmp;
        }
        void show(){
            for (int i = 0; i < this->n; i++){
                for (int j = 0; j < this->m; j++){
                    cout << arr[i][j] << " ";
                }
                cout << endl;
            }
        }
        Matrix operator+(Matrix dst){
            Matrix tmp(this->n, this->m);
            for (int i = 0; i < this->n; i++){
                for (int j = 0; j < this->m; j++){
                    tmp.arr[i][j] = arr[i][j] + dst.arr[i][j];
                }
            }
            return tmp;
        }
        Matrix operator*(Matrix dst){
            int sum = 0;
            Matrix tmp(this->n, dst.m);
            for (int i = 0; i < this->n; i++){
                for (int j = 0; j < dst.m; j++){
                    for (int k = 0; k < this->m; k++){
                        sum += arr[i][k] * dst.arr[k][j];
                    }
                    tmp.arr[i][j] = sum;
                    sum = 0;
                }
            }
            return tmp;
        }
        bool operator==(Matrix dst){
            for (int i = 0; i < this->n; i++){
                for (int j = 0; j < this->m; j++){
                    if (arr[i][j] != dst.arr[i][j]){
                        return false;
                    }
                }
            }
            return true;
        }
};

//DO NOT TOUCH THE MAIN FUNCTION.
int main() {
	srand(static_cast<unsigned int>(time(NULL)));

	Matrix A(2, 3), B(2, 3), C(2, 3), AT(3, 2), BT(3, 2), D(3, 2), E(2, 2), F(2, 2);
	AT = A.transpose();
	BT = B.transpose();
	cout << "A" << endl;
	A.show();
	cout << "=========" << endl;
	cout << "B" << endl;
	B.show();
	cout << "=========" << endl;
	cout << endl << "A " << (A == B ? "==" : "!=") << " B" << endl << endl << endl;

	C = A + B;
	cout << "C = A + B" << endl;
	C.show();
	cout << "=========" << endl;
	D = AT + BT;
	cout << "D = AT + BT" << endl;
	D.show();
	cout << endl << "C " << (C == D.transpose() ? "==" : "!=") << " Transpose of D" << endl << endl << endl;

	E = A * BT;
	cout << "E = A * BT" << endl;
	E.show();
	cout << "=========" << endl;
	F = B * AT;
	cout << "F = B * AT" << endl;
	F.show();
	cout << endl << "E " << (E == F.transpose() ? "==" : "!=") << " Transpose of F" << endl << endl << endl;

	return 0;
}

