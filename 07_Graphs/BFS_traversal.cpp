#include<bits/stdc++.h>
using namespace std;


// TC: O(N)-> while + O(2E) ->for loop ( O(2E)-> degree of freedoms-> adjacent(neighbours))
// SC: O(3N) => O(N)
vector<int> bfsTraversal(vector<int>adj[] , int n , int m){
    // initialize the starting Node to start the traversal 
    int vis[n+1] = {0};
    vis[1]=1;   // starting node is 1 

    queue<int>q;
    q.push(1);
    vector<int>bfs;

    while(!q.empty()){
        // FIFO
        int node = q.front();
        q.pop();
        bfs.push_back(node);


        // add the adjacency list in the queue of the front node 
        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
            }
        }
    }

    return bfs;

}



/*
input : 9 8
1 2
1 6
2 3
2 4
4 5
6 7
6 9
7 8
output : 1 2 6 3 4 7 9 5 8 
*/
int main()
{
    int n , m;
    cin>>n>>m;

    vector<int>adj[n+1];
    for(int i = 0 ; i<m ; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

vector<int>res = bfsTraversal(adj, n ,m);
for(auto it: res){
    cout<<it<<" ";
}  

return 0;
}