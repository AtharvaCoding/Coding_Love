#include <iostream>
#include <string.h>
using namespace std;
class Animal{
    public:
    virtual void Speak(){
        cout << " Speaking " << endl;
    }
};
class Dog : public Animal{
    public:
    void Speak(){
        cout << " Barking " << endl;
    }

};
int main(){
    Animal* A = new Animal();
    A->Speak();      // Speaking 

    Dog* D = new Dog();
    D->Speak();       // Barking 

// Upcasting 
    Animal* A1 = new Dog();
    A1->Speak();      // speaking |||| Barking with the virtual keyword 

// Down Casting 
    Dog* D1 = (Dog *)new Animal();
    D1->Speak();       // barking |||| Speaking with the virtual keyword 

return 0;
}   