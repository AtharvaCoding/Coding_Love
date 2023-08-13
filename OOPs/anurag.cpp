#include <iostream>
#include <unordered_map>

using namespace std;
class Anurag{
public:
    int a;
    int b;
    
    Anurag(int a, int b){
        this->a = a;
        this->b = b;
    }
};
int main(){
    Anurag* anu = new Anurag(9 , 10);
    cout << anu->a << endl;
    (*anu).a = 10;
    cout << anu->a << endl;
    return 0;
}