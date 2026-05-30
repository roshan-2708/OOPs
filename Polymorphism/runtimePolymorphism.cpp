#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void sound()
    {
        cout << "Animal makes a sound" << endl;
    }
};

class Dog : public Animal
{
public:
    void sound() override
    {
        cout << "Dog barks" << endl;
    }
};

int main()
{
    Animal *myAnimal = new Dog();

    myAnimal->sound();

    delete myAnimal;

    return 0;
}