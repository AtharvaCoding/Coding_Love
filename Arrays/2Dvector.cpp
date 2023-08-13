#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<vector<int> > arr (5 , vector<int> (5 , -8)); // smart way & ringt way aslo !! lsiten you MF

    // dumb way & wrong way aslo !!!! listen you MF 
    // vector<vector<int> > arr
    // int rows = 5 ; 
    // int cols = 5 ; 
    // for (int i = 0; i < rows; i++)
    // {
    //     for (int j = 0; j < cols; j++)
    //     {
    //         arr[i].push_back(-8) ;
    //     }
    // }
    
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout<< arr[i][j] << " ";
        }
        cout <<endl;
    }
    

return 0;
}   