#include <iostream>
#include <string.h>
using namespace std;
class Animal{
    public:
    int age ;
    int weight ; 

    Animal(){
        cout << "Animal Default cons called" <<endl;
    }

    void eat(){
        cout << "eating" << endl;
    }
};
class Dog : public Animal{
    public:
    Dog()
    {
        cout <<"Default of Dog"<<endl;
    }
    

};
int main(){



    Dog d;
    d.eat();
    // Dog* d1 = new Dog();

    return 0;
}   