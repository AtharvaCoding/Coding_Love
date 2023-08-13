#include <iostream>
#include <string.h>
#include<vector>
using namespace std;
class animal
{
private:
    int weight;
    // propertices
public:
    int age;
    string name;
    // behaviour

    void setweight(int weight)
    {
        this->weight = weight;
    }

    int getWeight()
    {
        return weight;
    }

    // constructor

    animal()
    {
        cout << "default constructor called" << endl;
    }
    animal(int age, string name, int weight)
    {
        this->age = age;
        this->name = name;
        this->weight = weight;

        cout << "paramatrized constructor called" << endl;

        cout << this->age <<endl; 
        cout << this->name<<endl;
    }



    // copy constructor 

    animal (animal &obj){                // we have to pass the address of the variable 
        this->age = obj.age;
        this->name = obj.name;
        this->weight = obj.weight;

        cout << "we are inside copy constructor" << endl;

    }


};

class Ploymorphisum{
public:
    int value ;
    void operator +(Ploymorphisum obj2){
        int value1 = this->value ;
        int value2 = obj2.value;
        cout << "the addition is (sorry substraction is :))))" << value2-value1<<endl;

    }
};

class Solution {
public: 
    void swap(int* a , int* b){
        int temp = *a ; 
        *a = *b ;
        *b = temp ;
    }

    void sortColors(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n - i - 1 ; j++){
                if(nums[j] > nums[j+1]){
                    swap(&nums[j] , &nums[j+1]);
                }
            }
        }
    }
};
int main()
{
    animal a;
    // default constructor called
    a.age = 15;
    a.name = "lion";
    a.setweight(80);

    cout << a.age << endl;
    cout << a.name << endl;
    cout << a.getWeight() << endl;

    animal *b = new animal();
    // default constructor called

    animal *c = new animal(20, "bear", 80);
    cout << c->age << endl;

    animal animal1 = a;
    animal animal2(a);
    animal e(*b);

    // bubble sort using oops 
    Solution s ; 
    vector<int> nums = {5,8,9,4,6,2,1,3,5,8};

    cout << "Printing the elements of the nums before the sorting algorithm" << endl;
    for(auto i : nums){
        cout << nums[i] << " ";
    }
    s.sortColors(nums);

    cout << "Printhing the elements of nums" << endl;

    for(auto i : nums){
        cout << nums[i] << " ";
    }
    
    cout << endl << endl << endl;
    Ploymorphisum p1 ;
    Ploymorphisum p2;
    p1.value = 10;
    p2.value = 20;

    p1+p2;

    return 0;
}