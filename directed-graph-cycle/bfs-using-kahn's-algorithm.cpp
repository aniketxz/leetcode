// Time Complexity: O(V + E)
// Space Complexity: O(V + E)
class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<int> adjacencyList[V];
        
        // build adjacency list
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            
            adjacencyList[u].push_back(v);
        }
        
        // using khan's algo to determine if the graph has a cycle
        
        // calculate indegree of all vertices
        vector<int> indegree(V, 0);
        for(vector<int>& neighbours : adjacencyList) {
            for(int& neighbour : neighbours) {
                indegree[neighbour]++;
            }
        }
        
        // push vertices with indegree 0
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
            
            // reduce degree of each neighbour of current node
            for(int& neighbour : adjacencyList[node]) {
                indegree[neighbour]--;
                if(indegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }
        
        // if topo.size == V, toposort was successful -> no cycles
        return topo.size() != V;
    }
};
