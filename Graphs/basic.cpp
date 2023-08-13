#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;
template <typename T>

class Graph
{
public:
    unordered_map<T, list<T>> adjlist;

    void addedge(T u, T v, bool directed)
    {
        // directed = 0 -> bydirected
        // directed = 1 -> unidirected

        // make a edge form u to v
        adjlist[u].push_back(v);
        if (directed == 0)
        {
            // make a edge form V TO U
            adjlist[v].push_back(u);
        }
    }
    // sort(adjlist.begin() , adjlist.end());

    void PrintAdjList()
    {

        for (auto node : adjlist)
        {
            cout << node.first << "->";
            for (auto neigbours : node.second)
            {
                cout << neigbours << " ";
            }
            cout << endl;
        }
    }
    void BFS(int src, unordered_map<int, bool> &visited)
    {
        // create queue , push the source , visited mark t crow
        queue<int> q;
        q.push(src);
        visited[src] = true;

        // q.empty tab tak logk chalao
        // logic : front element nikalo , usko pop crow , usko print crow ,
        // uske childs (list ke elements) dalo queue me (aur kab dalo ? jab visited of nbr false ho tab he)
        // offcource visited of nbr true mark crow
        while (!q.empty())
        {
            int element = q.front();
            q.pop();
            cout << element << " ";

            // Insert crow
            for (auto neibor : adjlist[element])
            {
                if (visited[neibor] == false)
                {
                    q.push(neibor);
                    visited[neibor] = true;
                }
            }
        }
    }

    void BFSPractice(int src, unordered_map<int, bool> &visited)
    {
        queue<int> q;
        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            int element = q.front();
            cout << element << " ";
            q.pop();
            visited[element] = true;

            for (auto nbr : adjlist[element])
            {

                if (visited[nbr] == false)
                {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }
    void DFSPractice(int src, unordered_map<int, bool> &visited)
    {
        cout << src << " ";
        visited[src] = 1;

        for (auto nbr : adjlist[src])
        {
            if (visited[nbr] == false)
            {
                visited[nbr] = true;
                DFSPractice(nbr, visited);
            }
        }
    }
    void DFS(int src, unordered_map<int, bool> &visited)
    {
        cout << src << " ";
        visited[src] = 1;

        for (auto neibours : adjlist[src])
        {
            if (!visited[neibours])
            {
                DFS(neibours, visited);
            }
        }
    }

    bool CycleDecUsingBFS(int src, unordered_map<int, bool> &visited)
    {
        queue<int> q;
        unordered_map<int, int> parent;
        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while (!q.empty())
        {
            int element = q.front();
            q.pop();

            for (auto nbr : adjlist[element])
            {
                if (visited[nbr] == false)
                {
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = element;
                }
                else
                { // visited[nbr] == true

                    // agar nbr element ka parent nahi hai toh cycle present hai
                    if (nbr != parent[element])
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool CycleDecUsingDFS(int src , unordered_map<int , bool> &visited , int parent){
        visited[src] =true ; 
        for(auto nbr : adjlist[src]){
            if (!visited[nbr])
            {
                bool aagekaans = CycleDecUsingDFS(nbr , visited , src);
                if (aagekaans)
                {
                    return aagekaans;
                }
                
            }
            else{
                if (nbr != parent)
                {
                    return true;
                }
                
            }
            
        }
        return false ;
    }
};
void AdjMatrix(vector<vector<int>> &adj, int n, int e)
{

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
    }
}
int main()
{
    // int n ;
    // cout << "Enter the total no of nodes : " << endl;
    // cin >> n ;

    // int e ;
    // cout << "Enter the total no of edges : " <<endl ;
    // cin >> e ;
    // vector<vector<int>> adj (n , vector<int> (n , 0));

    // AdjMatrix(adj , n , e);
    // // printing
    // for (int i = 0; i < adj.size(); i++)
    // {
    //     for (int j = 0; j < adj[i].size(); j++)
    //     {
    //         cout << adj[i][j] << " ";
    //     }
    //     cout << endl;

    // }

    // adj list

    Graph<int> g;
    // g.addedge(0 , 1 , 0);
    // g.addedge(0 , 3 , 0);
    // g.addedge(1 , 2 , 0);
    // g.addedge(1 , 3 , 0);
    // g.addedge(2 , 3 , 0);

    // Graph<char> gh;
    // gh.addedge('a', 'b', 0);
    // gh.addedge('a', 'c', 0);
    // gh.addedge('a', 'd', 0);
    // gh.addedge('a', 'e', 0);

    // g.addedge(0, 1, 1);
    // g.addedge(0, 3, 1);
    // g.addedge(1, 2, 1);
    // g.addedge(1, 3, 1);
    // g.addedge(2, 3, 1);

    // g.addedge(0 , 1 , 0);
    // g.addedge(1 , 2 , 0);
    // g.addedge(1 , 3 , 0);
    // g.addedge(3 , 5 , 0);
    // g.addedge(3 , 7 , 0);
    // g.addedge(7 , 6,  0);
    // g.addedge(7 , 4 , 0);

    g.addedge(0, 1, 0);
    g.addedge(1, 3, 0);
    g.addedge(0, 2, 0);
    g.addedge(2, 4, 0);
    g.addedge(1 ,2 ,0);
    int n = 5;

    cout << "Printing the adjency list " << endl;
    g.PrintAdjList();
    cout << endl
         << "BFS :" << endl;
    unordered_map<int, bool> visited;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            g.BFS(i, visited);
        }
    }

    cout << endl
         << "DFS :" << endl;
    unordered_map<int, bool> visited2;
    for (int i = 0; i < n; i++)
    {
        if (!visited2[i])
        {
            g.DFS(i, visited2);
        }
    }

    unordered_map<int, bool> visited3;
    bool ans = false;
    for (int i = 0; i < n; i++)
    {
        if (visited3[i] == false)
        {
            ans = g.CycleDecUsingBFS(i, visited3);
            if (ans == true)
            {
                break;
            }
        }
    }
    if (ans)
    {
        cout << endl << "Cycle is present" << endl;
    }
    else
    {
        cout << endl << "Cycle is absent" << endl;
    }



    unordered_map<int, bool> visited4;
    bool ansDFS = false;
    for (int i = 0; i < n; i++)
    {
        if (visited4[i] == false)
        {
            ansDFS = g.CycleDecUsingDFS(i, visited4 , -1);
            if (ansDFS == true)
            {
                break;
            }
        }
    }
    if (ansDFS)
    {
        cout << endl << "Cycle is present" << endl;
    }
    else
    {
        cout << endl << "Cycle is absent" << endl;
    }




    return 0;
}