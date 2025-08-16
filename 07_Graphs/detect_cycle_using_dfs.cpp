#include <bits/stdc++.h>
using namespace std;



bool detectCycle(int node ,int parent , vector<int>adj[], int visited[]){
    visited[node]= 1;
    for(auto it : adj[node]){
        
        if(!visited[it]){
           if( detectCycle(it ,node,  adj, visited)== true) return true;
        }
        else if(it != parent) return true;
        
    }
    return false;
}

  bool isCycle(int V, vector<vector<int>>& edges) {
      vector<int> adj[V];
      
      // Build the adjacency list from the edges
      for (auto& edge : edges) {
          int u = edge[0];
          int v = edge[1];
          
          adj[u].push_back(v);
          adj[v].push_back(u);
      }
      
      // Visited array should be initialized outside the loop
      int visited[V] = {0};
      // for loop for the n components
      for(int i = 0; i<V ; i++){
        if(!visited[i]){
           if(detectCycle(i , -1,  adj , visited)== true)
           return true;
        }
      }
     return false;
  }


int main()
{

    int V= 7;
    vector<vector<int>> edges1 = {
        {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 2} 
    };

    if (isCycle(V, edges1))
    {
        cout << "Cycle detected!" << endl;
    }
    else
    {
        cout << "No cycle detected!" << endl;
    }

  

    return 0;
}