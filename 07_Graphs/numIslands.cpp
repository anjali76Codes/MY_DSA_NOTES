#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
  void bfs(int row , int col, vector<vector<char>>&grid , vector<vector<int>>&vis){
     vis[row][col]=1;
      queue<pair<int,int>>qu;
      qu.push({row,col});
     
      int n = grid.size();
      int m = grid[0].size();
      
     
      while(!qu.empty()){
          int row = qu.front().first;
          int col = qu.front().second;
          qu.pop();
          
          // traverse in all 8 directions
          for(int delrow = -1; delrow<=1 ; delrow++){
              for(int delcol = -1 ; delcol <=1 ; delcol++){
                  int nrow = row+delrow;
                  int ncol = col+delcol;
                  
                  if(nrow>=0 && nrow<n  && ncol>=0 && ncol<m && grid[nrow][ncol]=='L'&& !vis[nrow][ncol]){
                      vis[nrow][ncol]=1 ;
                      qu.push({nrow,ncol});
                  }
              }
          }
      }
  }
  
    int countIslands(vector<vector<char>>& grid) {
        // row and col
        int n = grid.size();
        int m = grid[0].size();
        
        // 2d array visited matrix to mark as visited
        vector<vector<int>>vis(n , vector<int>(m,0));
        int cnt=0;
        for(int row = 0 ; row<n ; row++){
            for(int col = 0; col<m ; col++){
                if(!vis[row][col] && grid[row][col]=='L'){
                    cnt++;
                    bfs(row , col , grid, vis);
                }
            }
        }
        return cnt;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));

    // Input the grid
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    Solution sol;
    int result = sol.countIslands(grid);

    cout << result << endl;

    return 0;
}
