#include <bits/stdc++.h>
using namespace std;

  
  bool detectCycle(int start, vector<int> adj[], int visited[]) {
      visited[start] = 1;
      queue<pair<int, int>> q;
      
      q.push({start, -1});
      
      while (!q.empty()) {
          int node = q.front().first;
          int parent = q.front().second;
          q.pop();
          
          for (auto it : adj[node]) {
              if (visited[it] && it != parent) {
                  return true;
              } else if (!visited[it]) {
                  visited[it] = 1;
                  q.push({it, node});
              }
          }
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
      
      // Iterate through all vertices and check for cycle using BFS
      for (int i = 0; i < V; ++i) {
          if (!visited[i]) {
              if (detectCycle(i, adj, visited)) {
                  return true;
              }
          }
      }
      return false;
  }


int main()
{

    int V1 = 7;
    vector<vector<int>> edges1 = {
        {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 2} // Edge (5, 2) creates a cycle
    };

    cout << "Graph 1 (With Cycle): ";
    if (isCycle(V1, edges1))
    {
        cout << "Cycle detected!" << endl;
    }
    else
    {
        cout << "No cycle detected!" << endl;
    }

    int V2 = 8;
    vector<vector<int>> edges2 = {
        {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7} // No cycle here
    };

    cout << "Graph 2 (Without Cycle): ";
    if (isCycle(V2, edges2))
    {
        cout << "Cycle detected!" << endl;
    }
    else
    {
        cout << "No cycle detected!" << endl;
    }

    return 0;
}