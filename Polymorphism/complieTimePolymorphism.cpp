#include <iostream>
using namespace std;

class Calculator
{
public:
    int add(int a, int b)
    {
        return a + b;
    }

    double add(int a, int b, int c)
    {
        return a + b + c;
    }
};

int main()
{
    Calculator cal;
    cout << cal.add(5, 3) << endl;
    cout << cal.add(1, 2, 3);
}