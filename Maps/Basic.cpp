#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    // creation 
    unordered_map<string , int> m;
    // inseration 
    pair<string , int> p = make_pair("Scropio" , 20);
    m.insert(p);

    pair<string , int> p1("alto" , 5);
    m.insert(p1);

    m["fortuner"] = 10;    // ******
    // exess 
    cout<< m.at("Scropio") << endl;
    cout<< m.at("alto") << endl;
    cout<< m["fortuner"] << endl;   // ******

    // search 
     
    cout<< m.count("Scropio") << endl;
    cout<< m.count("alto") << endl;
    if (m.count("alto"))
    {
        cout << "The alto is present "<< endl;
    }

    if (m.find("fortuner") != m.end())
    {  
        cout<< "Fortuner is present" << endl;
    }
    else{
        cout<< "absent "<<endl;
    }

    // size 
    cout<< "the size is " <<  m.size() <<endl;
    cout<< m["wagonr"] << endl; // if the key is not present in the map , then it creats the new key
    // and assign 0 to it 
    cout<< "the size is " <<  m.size() <<endl;   // thats why the size is 4 

    // printing all the values of map 
    cout<<endl << "Printing all the values of map" << endl;
    for (auto i : m)
    {
        // i is pair 
        // how to print pair >  i.first , i.second 

        cout << i.first << " -> " << i.second << endl;
    }
    
    
    
    

    return 0;
}   