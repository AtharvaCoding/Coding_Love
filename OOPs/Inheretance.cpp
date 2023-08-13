#include <iostream>
#include <string.h>
using namespace std;
class A
{
public:
    A()
    {
        cout << "Inside A" << endl;
    }
    void Eat(){
        cout << "Eating "<< endl;
    }
};

class B : public A {
public:
    B(){
        cout << "Inside B"<< endl;
    }
};

class C : public B{
    public:
    C(){
        cout << "Inside C"<<endl;
    }
};

int main()
{
    C* c1 = new C();
    c1->Eat();
    return 0;
}