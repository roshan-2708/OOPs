#include<iostream>
using namespace std;

class animal{
    public:
    void eat(){
        cout<<"This animal can eat.(extending the class animal)"<<endl;
    }
};
// extending the class dog from animal
class dog : public animal{
    public:
    void bark(){
        cout<<"This dog can bark.(extending the class dog from animal)"<<endl;
    }
};

// extending the class puppy from dog
class puppy : public dog{
    public:
    void weep(){
        cout<<"This puppy can weep.(extending the class puppy from dog)"<<endl;
    }
};

int main(){
    puppy p;
    p.eat();
    p.bark();
    p.weep();
    return 0;
}