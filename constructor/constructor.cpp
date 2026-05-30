#include <iostream>
#include <string> // string use karne ke liye ye include karna best practice hai

using namespace std;

class Employee {
private:
    double Salary; 

public:
    string EmployeeName; 

    // Employee() {
    //     this->EmployeeName = "Roshan"; 
    //     this->Salary = 1000.0;         
    // }

    Employee(string name, double salary){
        this->EmployeeName = name;
        this->Salary = Salary;
    }

    void setName(string name) {
        this->EmployeeName = name;
    }

    void setSalary(double salary) {
        this->Salary = salary;
    }

    double getSalary() {
        return this->Salary;
    }
}; 

int main() {
    Employee* obj = new Employee("Roshan", 1000.0);

    cout << "Default values initialized by the constructor:\n" << endl;
    cout << "Employee Name: " << obj->EmployeeName << endl;
    cout << "Salary: " << obj->getSalary() << endl;

    return 0;
}