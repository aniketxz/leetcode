// Time Complexity: O(V + E)
// Space Complexity: O(V + E)
class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> adjacencyList[V];
        
        // build adjacency list
        for(auto &it : edges) {
            adjacencyList[it[0]].push_back(it[1]);
        }
        
        // calculate indegree of each node
        vector<int> indegree(V, 0);
        for(vector<int>& neighbours : adjacencyList) {
            for(int& neighbour : neighbours) {
                indegree[neighbour]++;
            }
        }
        
        // push all vertices with indegree 0
        queue<int> q;
        for(int node = 0; node < V; node++) {
            if(indegree[node] == 0) {
                q.push(node);
            }
        }
        
        vector<int> topo;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            // reduce indegree of neighbours
            for(auto it : adjacencyList[node]) {
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        
        return topo;
    }
};
