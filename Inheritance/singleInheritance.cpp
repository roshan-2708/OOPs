#include <iostream>
using namespace std;

class animal
{
public:
    void eat()
    {
        cout << "This animal can eat." << endl;
    }
};

class dog : public animal
{
public:
    void bark()
    {
        cout << "This dog can bark." << endl;
    }
};

int main()
{
    dog d;
    d.eat();
    d.bark();
    return 0;
}