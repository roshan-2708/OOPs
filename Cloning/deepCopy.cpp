#include <iostream>
using namespace std;

class Address
{
public:
    string city;

    Address(string city)
    {
        this->city = city;
    }

    Address(const Address &other)
    {
        this->city = other.city;
    }
};

class Person
{
public:
    string name;
    Address *address;

    Person(string name, Address *address)
    {
        this->name = name;
        this->address = address;
    }

    Person(const Person &other)
    {
        this->name = other.name;
        this->address = new Address(*other.address); // deep copy, create a new address object for the cloned person
    }

    ~Person()
    {
        delete address; // free the memory allocated for address
    }
};

int main()
{
    Address *address = new Address("Mumbai");
    Person *person = new Person("Rahul", address);

    // Clone using copy constructor
    // (deep copy because Person allocates new Address)
    Person *clonedPerson = new Person(*person);

    clonedPerson->address->city = "New Delhi";

    cout << person->name << " lives in " << person->address->city << endl;
    cout << clonedPerson->name << " lives in " << clonedPerson->address->city << endl;

    // Delete only Persons; each Person frees its own Address
    delete person;
    delete clonedPerson;
    
    return 0;
}