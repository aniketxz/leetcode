// Time Complexity : O(V + E)
// Space Complexity: O(V + E)
#include <vector>
#include <stack>
using namespace std;

class Solution {
  public:
    // Standard DFS to traverse graph post-order
    void dfs_helper(int node, stack<int>& st, vector<int> adjacencyList[], vector<bool>& visited) {
        visited[node] = true;
        
        for(auto it : adjacencyList[node]) {
            if(!visited[it])
                dfs_helper(it, st, adjacencyList, visited);
        }
        
        // Push to stack after all neighbors are processed (dependencies first)
        st.push(node);
    }
  
    // Returns topological sort sequence of a DAG
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> adjacencyList[V];
        
        // Build adjacency list (u -> v)
        for(auto &it : edges) {
            int u = it[0];
            int v = it[1];
            adjacencyList[u].push_back(v);
        }
        
        vector<bool> visited(V, false);
        stack<int> st;
        
        // Run DFS for all components to handle disconnected graphs
        for(int node = 0; node < V; node++) {
            if(!visited[node]) {
                dfs_helper(node, st, adjacencyList, visited);
            }
        }
        
        // Pop stack to reverse post-order and get correct topological sequence
        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};
