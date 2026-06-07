#include<iostream>
#include<string>
using namespace std;

// One-to-One Relationship
class Passport {
private:
    int passportNumber;

public:
    // Constructor (Public hona zaroori hai)
    Passport(int passportNumber) {
        this->passportNumber = passportNumber;
    }

    // Getter function
    int getPassportNumber() {
        return passportNumber;
    }
};

class Student {
private:
    string name;
    Passport passport; // Composition / Association

public:
    // Constructor with proper types
    Student(string name, Passport passport) : passport(passport) {
        this->name = name;
    }

    void display() {
        cout << "Student Name is : " << name << endl;
        // Getter use karna padega variable print karne ke liye
        cout << "Passport Number is : " << passport.getPassportNumber() << endl;
    }
};

int main() {
    // C++ mein static allocation bina 'new' ke hoti hai (Best & Clean)
    Passport myPassport(123456789);
    Student myStudent("Roshan", myPassport);

    // Data display karne ke liye
    myStudent.display();

    return 0;
}