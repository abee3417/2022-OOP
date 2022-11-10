#include <iostream>

using namespace std;

class Matrix {
private:
   int r, c;
   const char* name;
   int** arr;
   void welcome() {
      cout << name <<" constructor called "<< endl;
   }
   void bye() {
      cout << name << " distructor called " << endl;
   }
public:
   Matrix(const char*str){
      name = str;
      r = c = 2;
      arr = new int* [r];
      for (int i = 0; i < r; i++) {
         arr[i] = new int[c];
      }
      welcome();
   }
   Matrix(const Matrix& m) {
      name = m.name;
      r = c = 2;
      arr = new int* [r];
      for (int i = 0; i < r; i++) {
         arr[i] = new int[c];
      }
   }
   ~Matrix() {
      for (int i = 0; i < r; i++) {
         delete[] arr[i];
      }
      delete[] arr;
      bye();
   }
   void setName(const char* str) {
      name = str;
   }
};

int main() {
   Matrix M1("m1"); // 2 by 2 matrix
   //Matrix M2("m2");
   {
      Matrix M2 = M1;  // copy constructor
      M2.setName("m2");
   }
   // M2.setName("m2");
   
   Matrix M3("m3");


   return 0;
}