class Solution {
public:
    bool canToposort(int node, vector<bool>& visited, 
        vector<bool>& visitedPath, vector<vector<int>>& adjacencyList) {
        
        visited[node] = true;
        visitedPath[node] = true;

        for(int neighbour : adjacencyList[node]) {
            if(!visited[neighbour]) {
                if(!canToposort(neighbour, visited, visitedPath, adjacencyList))
                    return false;
            } else if(visitedPath[neighbour]) {
                return false;
            }
        }

        visitedPath[node] = false;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        const int V = numCourses;

        // build adjacency list
        vector<vector<int>> adjacencyList(V);
        for(auto& it : prerequisites) {
            int u = it[1];
            int v = it[0];
            adjacencyList[u].push_back(v);
        }

        // using toposort to determine if we can linearly represent the dependencies
        vector<bool> visited(V, false);
        vector<bool> visitedPath(V, false);

        // handling disconnected components
        for(int node = 0; node < V; node++) {
            if(!visited[node]) {
                if(!canToposort(node, visited, visitedPath, adjacencyList))
                    return false;
            }
        }

        return true;
    }
};