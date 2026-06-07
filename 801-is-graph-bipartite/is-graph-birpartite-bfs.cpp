// Time Complexity: O(V + E)
// Space Complexity: O(V)
class Solution {
public:
    bool dfs(int node, int currColor, vector<int>& color, vector<vector<int>>& graph) {
        if(color[node] != -1)
            return color[node] == currColor;

        color[node] = currColor;

        for(int neighbour : graph[node]) {
            if(!dfs(neighbour, 1 - currColor, color, graph))
                return false;
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();

        // -1 -> not color, 0 -> set A, 1 -> set B
        vector<int> color(V, -1);

        for(int node = 0; node < V; node++) {
            if(color[node] == -1) {
                if(!dfs(node, 0, color, graph))
                    return false;
            }
        }

        return true;
    }
};
