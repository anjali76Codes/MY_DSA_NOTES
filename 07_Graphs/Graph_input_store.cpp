#include <bits/stdc++.h>
using namespace std;


// TC: O(N)+ O(N+2E)  
// SC : O(N)
// undirected graph -> adjacency matrix -> symmetric n*n

// basic dfs function to visit all connected nodes
void dfs(int node, vector<int> adj[], int vis[]) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it]) {
            dfs(it, adj, vis);
        }
    }
}

// function to count number of provinces
int no_of_provinces(vector<vector<int>> &adj, int n) {
    // converting adjacency matrix to adjacency list
    vector<int> adjs[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // if there is a connection and it's not a self-loop
            if (adj[i][j] == 1 && i != j) {
                adjs[i].push_back(j);
            }
        }
    }

    int vis[n] = {0}; // to keep track of visited nodes
    int cnt = 0;

    // run dfs for unvisited nodes and increase count
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            cnt++;
            dfs(i, adjs, vis);
        }
    }

    return cnt;
}

int main() {
    int n;
    cin >> n;

    // taking input for adjacency matrix
    vector<vector<int>> adj(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }

    // calling the function and printing the answer
    cout << no_of_provinces(adj, n) << endl;

    return 0;
}
