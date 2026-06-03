#include <iostream>
using namespace std;

class OuterClass {
public:
    static int staticVar;
    static int val;   // removed const

    class innerClass {
    public:
        void display() {
            cout << "Before increment: "
                 << OuterClass::staticVar << " "
                 << OuterClass::val << endl;

            OuterClass::val++;

            cout << "After increment: "
                 << OuterClass::staticVar << " "
                 << OuterClass::val << endl;
        }
    };
};

int OuterClass::staticVar = 100;
int OuterClass::val = 0;

int main() {
    OuterClass::innerClass obj;
    obj.display();

    return 0;
}