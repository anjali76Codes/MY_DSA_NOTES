#include<bits/stdc++.h>
using namespace std;


void dfs(int node , vector<int>adj[] , int vis[]){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it , adj , vis);
        }
    }
}

int no_of_provinces(vector<vector<int>>adj, int n , int m){
    // needs to convert the matrix into the adjacency list 
    vector<int>adjs[n];
    int cnt = 0;
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<n ; j++){
            if(adjs[i][j]==1 && i!=j){
                adjs[i].push_back(j);
                adjs[j].push_back(i);

            }

        }
    }
    int vis[n];
for(int i = 0; i<n ; i++){
    if(!vis[i]){
        cnt++;
        dfs(i, adjs, vis);
    }
}

    
return cnt;
}

int main()
{

    int n,m;
    cin>>n>>m;
 // Initialize adjacency list
    vector<vector<int>> adj(n + 1);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << no_of_provinces(adj, n,m) << endl;

return 0;
}