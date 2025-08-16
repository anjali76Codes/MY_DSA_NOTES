#include<bits/stdc++.h>
using namespace std;



// SC: O(N)+O(N)+O(N)=> O(N)   TC: O(N)+O(2E)
void dfs(int node , vector<int>adj[] , vector<int>&ls , int vis[]){
    vis[node] = 1;
    ls.push_back(node);

    // take the adjacency list : traverse all its neighbours
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it , adj , ls , vis);
        }
    }
}


vector<int> dfs_Traversal(vector<int>adj[], int n , int m){
    // 1. create a visited array
    int vis[n+1]= {0};
    // starting node 
    int start = 1;
    vector<int>ls;  // list to store the dfs traversal 
    dfs(start, adj , ls ,vis);
    return ls;

}



/*
1- based indexing :
input : 9 8
1 2
1 6
2 3
2 4
4 5
6 7
6 9
7 8
output : 1 2 3 4 5 6 7 8 9

0-based indexing :
inputs: 5 4
0 1
0 2
1 3
1 4
output: 0 1 3 4 2 

*/
int main()
{
    int n, m;
    cin>>n>>m;

    vector<int>adj[n+1];
    for(int i= 0 ; i<m ; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    vector<int>res= dfs_Traversal(adj, n , m);
    for(auto it: res){
        cout<<it<<" ";
    }

return 0;
}