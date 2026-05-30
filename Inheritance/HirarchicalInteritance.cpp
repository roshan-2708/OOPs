#include <iostream>
using namespace std;

class Animal
{
public:
    void eat()
    {
        cout << "This animal is eat." << endl;
    }
};

class Dog : public Animal
{
public:
    void bark()
    {
        cout << "This is a dog who bark." << endl;
    }
};

class Cat : public Animal
{
public:
    void meow()
    {
        cout << "This is a cat who meow" << endl;
    }
};

int main()
{
    Dog d;
    d.bark();
    d.eat();

    Cat c;
    c.eat();
    c.meow();
    return 0;
}