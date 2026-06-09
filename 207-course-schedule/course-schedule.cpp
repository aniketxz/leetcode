// using kahn's algorithm
// If we can produce a topological ordering containing all vertices, then there is no cycle
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        const int V = numCourses;

        // build adjacency list
        vector<vector<int>> adjacencyList(V);
        vector<int> indegree(V, 0);

        for(auto& it : prerequisites) {
            int u = it[1];
            int v = it[0];

            adjacencyList[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        // keep track of processed instead of storing in a vector
        int processed = 0;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            processed++;

            for(int neighbour : adjacencyList[node]) {
                indegree[neighbour]--;
                if(indegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }

        return processed == V;
    }
};