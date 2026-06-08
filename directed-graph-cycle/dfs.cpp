class Solution {
  public:
    bool detect(int node, vector<bool>& visited, 
        vector<bool>& pathVisited, vector<int> adjacencyList[]) {
        
        visited[node] = true;
        pathVisited[node] = true;
        
        // traverse adjacent nodes
        for(auto &neighbour : adjacencyList[node]) {
            // when node is not visited
            if(!visited[neighbour]) {
                if(detect(neighbour, visited, pathVisited, adjacencyList))
                    return true;
            // if the node has been visited on same path
            } else if(pathVisited[neighbour]) {
                return true;
            }
        }
        
        pathVisited[node] = false;
        return false;
    }
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<int> adjacencyList[V];
        
        // build adjacency list
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            
            adjacencyList[u].push_back(v);
        }
        
        vector<bool> visited(V, false);
        vector<bool> pathVisited(V, false);
        
        for(int node = 0; node < V; node++) {
            if(!visited[node]) {
                if(detect(node, visited, pathVisited, adjacencyList))
                    return true;
            }
        }
        
        return false;
    }
};
