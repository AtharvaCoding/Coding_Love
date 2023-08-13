#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
using namespace std;
int main(){
    vector<int> arr = {2,1,5,3,6,8};
    map <pair<int ,int> , int> maxi;

    for(int i = 0 ; i < arr.size() ; i++){
        maxi[{i,i}] = arr[i];
        for(int j = i+1 ; j<arr.size() ;j++){
            int curr = maxi[{i , j-1}];
            maxi[{i,j}] = max(arr[j] , curr);
        }
    }

    for( auto i : maxi){
        cout << i.first.first << " " << i.first.second << " : " << maxi[{i.first.first ,i.first.second }] << endl; 
    }
    

return 0;
}