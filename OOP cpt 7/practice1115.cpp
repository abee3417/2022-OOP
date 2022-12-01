#include <iostream>
#include <string>

using namespace std;

class Person {        // abstract class
private:
	string _name;
	string _address;
public:
	Person(string name, string address) {
		_name = name;
		_address = address;
		cout << "Person Constructor" << endl;
	}
	virtual ~Person() {
		cout << "Person Destructor" << endl;
	}

	virtual void printInfo() = 0;  //pure
};

class Employee : public Person{
public:
	Employee(string name, string address) : Person(name,address) {
		cout << "Employee Constructor" << endl;
	}
	~Employee() {
		cout << "Employee Destructor" << endl;
	}
		void printInfo() {
		cout << "Employee" << endl;
	}
};

class Customer : public Person{
public:
	Customer(string name, string address) : Person(name, address) {
		cout << "Customer Constructor" << endl;
	}
	~Customer() {
		cout << "Customer Destructor" << endl;
	}
	void printInfo() {
		cout << "Customer" << endl;
	}
};

int main() {

	Person* array[3];       //array of pointers to class Person

	array[0] = new Employee("Lee", "Dankook");
	array[1] = new Employee("Park", "Google");
	array[2] = new Customer("Kim", "Seoul");

	for (int i = 0; i < 3; i++) {
		array[i]->printInfo();
	}

	for (int i = 0; i < 3; i++) {
		delete array[i];
	}



	return 0;
}