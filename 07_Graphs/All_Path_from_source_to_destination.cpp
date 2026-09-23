#include <bits/stdc++.h>
using namespace std;


    void dfs(int node, vector<vector<int>>& graph, vector<int>& temp, vector<vector<int>>& ans) {
        // if it is last node(destination) simply push it into the ans 
        if (node == graph.size() - 1) {
            ans.push_back(temp);
            return;
        }

        for (auto it : graph[node]) {
            temp.push_back(it);              // Use push_back instead of add
            dfs(it, graph, temp, ans);
            temp.pop_back();                 // Use pop_back instead of remove
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> temp;
        vector<vector<int>> ans;

        temp.push_back(0);
        dfs(0, graph, temp, ans);
        return ans;
    }

int main() {
  

    // Example input: graph = [[1,2],[3],[3],[]]
    vector<vector<int>> graph = {
        {1, 2},
        {3},
        {3},
        {}
    };

    vector<vector<int>> result = allPathsSourceTarget(graph);

    // Print the result
    cout << "All paths from source to target:\n";
    for (const auto& path : result) {
        cout << "[";
        for (size_t i = 0; i < path.size(); ++i) {
            cout << path[i];
            if (i != path.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }

    return 0;
}
