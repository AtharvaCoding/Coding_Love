#include <iostream>
#include <string.h>
using namespace std;
class A {
    public:
    int age ; 
    int weight;
};
int main(){
 A a1 ;
 A const a2  = a1;
 a1.age = 10;
 a1.weight = 30;
 cout << a1.age << endl << a1.weight<< endl << a2.age<< endl << a2.weight <<endl;
return 0;
}   