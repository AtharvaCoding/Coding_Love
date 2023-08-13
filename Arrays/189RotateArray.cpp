#include <iostream>
#include <vector>
using namespace std;
int main(){

return 0;
}
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        while(k>0){
            for(int j = nums.size()-1 , i = nums.size()-2 ; i>=0 ; j--,i--){
                swap(nums[i], nums[j]);
            }       
            k--;
        }
    }
};