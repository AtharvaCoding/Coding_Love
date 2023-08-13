#include <iostream>
#include <string.h>
#include "bird.h"
using namespace std;
void BirdDoesSomething(Bird* &bird){
    bird->eat();
    bird->eat();
    bird->fly();
    bird->fly();
    bird->eat();
    bird->fly();
    bird->fly();
    bird->eat();
}
int main()
{
    // Bird* b = new Bird();      // not possible 

    Bird* b = new sprrow();     // If you want to print the eagle , then change the right side wala function only 
    Bird* e = new eagle(); 
    BirdDoesSomething(b);
    BirdDoesSomething(e);



    return 0;
}