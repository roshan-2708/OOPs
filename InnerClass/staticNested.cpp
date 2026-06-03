#include <iostream>
using namespace std;

class OuterClass {
public:
    static int staticVar;
    static const int val = 0;

    class innerClass {
    public:
        void display() {
            cout << "Static variable : "
                << OuterClass::staticVar << " "
                << OuterClass::val << endl;
        }
    };
};

int OuterClass::staticVar = 100;

int main() {
    // nested class does not required outer class object
    OuterClass::innerClass obj;
    obj.display();

    return 0;
}