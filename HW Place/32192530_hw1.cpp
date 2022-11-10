#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
				HW 1 (7pts, Due: 10/1 23:59PM)
Provide a class Matrix to complete this code.
This class should support the following methods:

1. void create()
This function takes two integers (say n and m) from user input and allocates memory blocks for an n by m matrix. (NOT m by n !!!).
You may want to use dynamic memory allocation.

2. void destory()
This function releases the allocated memory blocks.

3. void display()
This function displays the matrix in the form of an n by m matrix.

4. void set()
This function sets the values of the matrix to non-zero integers between 0 and 5. You may want to use rand() for this.

5. void transpose()
This function displays the transpose of the matrix in the form of an m by n matrix.

6. int getMax()
This function returns the maximum value of the matrix.

7. bool isSquare()
This function checks if the matrix is a square matrix or not.

Submit this file to the LMS.
*/

//Your code goes here.

class Matrix{
	private:
		int **arr;
		int n, m;
	public:
		void create(){
			cout << "Enter n and m : ";
			cin >> this->n;
			cin >> this->m;
			arr = new int*[n];
			for (int i = 0; i < n; i++){
				arr[i] = new int[m];
			}
		}
		void destroy(){
			for (int i = 0; i < n; i++){
				delete[] arr[i];
			}
			delete[] arr;
		}
		void display(){
			cout << "Normal Matrix" << endl;
			for (int i = 0; i < n; i++){
				for (int j = 0; j < m; j++){
					cout << arr[i][j] << " ";
				}
				cout << endl;
			}
		}
		void set(){
			srand((unsigned int)time(NULL));
			for (int i = 0; i < n; i++){
				for (int j = 0; j < m; j++){
					arr[i][j] = (int)rand() % 5 + 1;
				}
			}
		}
		void transpose(){
			cout << "Transpose Matrix" << endl;
			for (int i = 0; i < m; i++){
				for (int j = 0; j < n; j++){
					cout << arr[j][i] << " ";
				}
				cout << endl;
			}
		}
		int getMax(){
			int max = 0;
			for (int i = 0; i < n; i++){
				for (int j = 0; j < m; j++){
					if (arr[i][j] > max){
						max = arr[i][j];
					}
				}
			}
			return max;
		}
		bool isSquare(){
			if (m == n){
				return true;
			}
			else{
				return false;
			}
		}
};

//DO NOT TOUCH THE MAIN FUNCTION.
int main() {

	for (int i = 0; i < 3; i++) {
		Matrix* A = new Matrix;
		cout << "====Matrix A[" << i << "]====" << endl << endl;
		A->create();
		A->set();
		A->display();
		A->transpose();
		cout << "Maximum value: " << A->getMax() << endl;
		cout << "Matrix A[" << i << "] is " << (A->isSquare() ? "" : "not ") << "a square matrix." << endl;
		A->destroy();
		delete A;
		cout << endl << "==== Bye!!! ====" << endl << endl;
	}

	return 0;
}