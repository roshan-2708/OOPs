#include <iostream>
using namespace std;

class Person
{
public:
    string name;
    int age;

    // normal constructor
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    // copy constructor
    Person(const Person &other)
    {
        this->name = other.name;
        this->age = other.age;

        cout<<"Copy constructor called for "<<endl;
    }

    void display()
    {
        cout<<"Name: "<<name<<", Age: "<<age<<endl;
    }
};

int main()
{

    Person p1 ("Roshan", 21);

    Person p2 (p1); // copy constructor is called
    Person p3 = p1; // copy constructor is called

    p2.name = "Sita";
    p3.name = "Gita";

    p1.display();
    p2.display();
    p3.display();

    return 0;
}