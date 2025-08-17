#include <bits/stdc++.h>
using namespace std;


    void dfs(int row , int col , int delRow[] , int delCol[], vector<vector<int>>&image , vector<vector<int>>&ans, int newColor, int iniColor) {
        // initial row col 
        ans[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();
        
        // now I have to traverse to its neighbours (in 4 directions)
        for(int i = 0 ; i < 4 ; i++) {
            int nrow = row + delRow[i]; 
            int ncol = col + delCol[i];
            // check conditions 
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && ans[nrow][ncol] != newColor && image[nrow][ncol] == iniColor) {
                dfs(nrow , ncol , delRow , delCol , image , ans , newColor , iniColor);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // copy of the image 
        vector<vector<int>> ans = image;
        int iniColor = image[sr][sc];  // initial color

        int delRow[] = {-1, 0, +1, 0}; // up, right, down, left
        int delCol[] = {0, +1, 0, -1}; 

        dfs(sr , sc , delRow , delCol , image, ans , newColor, iniColor);
        return ans;
    }


int main() {
    // Predefined input for testing
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    int sr = 1; // starting row index
    int sc = 1; // starting column index
    int newColor = 2; // new color to fill

    
    vector<vector<int>> result = floodFill(image, sr, sc, newColor);

    // Printing the result
    cout << "Modified image after flood fill:" << endl;
    for (auto row : result) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
