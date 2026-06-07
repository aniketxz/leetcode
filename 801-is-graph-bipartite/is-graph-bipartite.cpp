// Time Complexity: O(V + E)
// Space Complexity: O(V)
class Solution {
public:
    bool bfs(int curr, vector<int>& visited, vector<vector<int>>& graph) {
        queue<int> q;
        q.push(curr);
        visited[curr] = 1;

        while(!q.empty()) {
            int node = q.front();
            int node_group = visited[node];
            q.pop();

            for(int neighbour : graph[node]) {
                int neighbour_group = visited[neighbour];
                
                // not colored yet
                if(neighbour_group == 0) { 
                    visited[neighbour] = (node_group == 1) ? 2 : 1;
                    q.push(neighbour);
                
                // adjacent node have same color
                } else if(neighbour_group == node_group) { 
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();

        // 0 -> not visited, 1 -> set A, 2 -> set B
        vector<int> visited(V, 0);

        for(int node = 0; node < V; node++) {
            if(!visited[node]) {
                if(!bfs(node, visited, graph))
                    return false;
            }
        }

        return true;
    }
};