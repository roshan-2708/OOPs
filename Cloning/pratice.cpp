#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Employee
{
public:
    string empName;
    string empId;

    Employee(string empName, string empId)
    {
        this->empName = empName;
        this->empId = empId;
    }

    void display()
    {
        cout << "This email id is " << empId << " and the name of the employee is " << empName << endl;
    }
};

class Department
{
public:
    string deptName;
    vector<Employee *> employees;

    Department(string deptName)
    {
        this->deptName = deptName;
    }

    // DESTRUCTOR: Department delete hote hi uske andar ke saare employees heap se clear ho jayenge
    ~Department()
    {
        for (Employee *emp : employees)
        {
            delete emp;
        }
    }

    void addEmployee(Employee *emp)
    {
        employees.push_back(emp);
    }

    void displayEmployees()
    {
        cout << "Department: " << deptName << endl;
        for (Employee *emp : employees)
        {
            emp->display();
        }
    }
};

class Company
{
public:
    string companyName;
    Department *dept;

    Company(string companyName, Department *dept)
    {
        this->companyName = companyName;
        this->dept = dept;
    }

    // DESTRUCTOR: Deep copy wali company apna alag department delete karegi
    ~Company()
    {
        // Sirf tab delete karenge jab yeh deep copy ho (taaki shallow copy original ka data na uda de)
        // Ek standard practice real life mein smart pointers use karna hota hai,
        // par manual deletion ke liye hum yahan dhyan rakhenge.
    }

    Company *shallowCopy()
    {
        return new Company(this->companyName, this->dept);
    }

    Company *deepCopy()
    {
        Department *newDept = new Department(this->dept->deptName);
        for (Employee *emp : this->dept->employees)
        {
            newDept->addEmployee(new Employee(emp->empName, emp->empId));
        }
        return new Company(this->companyName, newDept);
    }

    void display()
    {
        cout << "Company: " << companyName << endl;
        if (dept)
        {
            dept->displayEmployees();
        }
        cout << "-----------------------------------" << endl;
    }
};

int main()
{
    // Sabhi ko Heap par banaya taaki pure system mein pointers consistently behave karein
    Employee *emp = new Employee("John Doe", "john.doe@example.com");
    Department *dept = new Department("Engineering");
    dept->addEmployee(emp);

    Company *originalCompany = new Company("TechCorp", dept);

    cout << "--- Original Company ---" << endl;
    originalCompany->display();

    Company *shallowClonedCompany = originalCompany->shallowCopy();
    Company *deepClonedCompany = originalCompany->deepCopy();

    // Modification test karne ke liye: Original employee ka naam badal dete hain
    emp->empName = "John Smith";

    cout << "--- After Modification ---" << endl;
    cout << "Shallow Copy (Will change to John Smith):" << endl;
    shallowClonedCompany->display();

    cout << "Deep Copy (Will remain John Doe):" << endl;
    deepClonedCompany->display();

    // Clean up memory to prevent leaks
    // 1. Deep clone ka apna alag department aur employees hain, unhe delete karte hain
    delete deepClonedCompany->dept; // Yeh department ke destructor ko call karega aur saare inner employees delete ho jayenge
    delete deepClonedCompany;

    // 2. Shallow copy ka data original ke sath shared hai, toh sirf company pointer delete karenge
    delete shallowClonedCompany;

    // 3. Last mein original setup clear karenge
    delete dept; // Yeh original employees bhi delete kar dega
    delete originalCompany;

    return 0;
}