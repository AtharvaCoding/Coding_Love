#include <iostream>
#include <string.h>
using namespace std;
class A {
    private:
    int x ; 

    public:
    void setx(int val){
        x = val;
    }
    int getx(){
        return x;
    }

    friend class B;
    friend void Print(const A &a);

};

class B{
    public:
    void PrintAsX(const A &a){
        cout << "A's x is :" << a.x << endl;
    }
};

void Print(const A &a){
    cout << "A's x is :" << a.x << endl;
}
int main(){
    A a ;
    a.setx(5);
    // cout<<a.getx();

    B b;
    b.PrintAsX(a);
    Print(a);
    return 0;
}   