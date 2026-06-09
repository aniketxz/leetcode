class Solution {
  public:
    string findOrder(vector<string> &words) {
        int n = words.size();
        
        // Track unique characters present in the dictionary
        unordered_set<char> chars;
        for(auto& word : words) {
            for(char ch : word) {
                chars.insert(ch);
            }
        }
        
        // Graph structures: Adjacency list using sets to avoid duplicate edges
        vector<unordered_set<int>> adjacencyList(26);
        vector<int> indegree(26, 0);
        
        // Build the dependency graph by comparing adjacent words
        for(int i = 0; i < n-1; i++) {
            string s1 = words[i];
            string s2 = words[i+1];
            
            int len = min(s1.size(), s2.size());
            int j = 0;
            
            // Find the first mismatched character
            while(j < len && s1[j] == s2[j]) {
                j++;
            }
            
            // Edge Case: If s2 is a prefix of s1, the order is invalid (e.g., "abc" before "ab")
            if(j == len && s1.size() > s2.size()) {
                return "";
            }
            
            // Add a directed edge from s1[j] to s2[j] if it doesn't already exist
            if(j < len) {
                int u = s1[j] - 'a';
                int v = s2[j] - 'a';
                
                if(adjacencyList[u].find(v) == adjacencyList[u].end()) {
                    adjacencyList[u].insert(v);
                    indegree[v]++;
                }
            }
        }
        
        // Kahn's Algorithm: Push all nodes with 0 in-degree into the queue
        queue<int> q;
        for(char ch : chars) {
            int node = ch - 'a';
            if(indegree[node] == 0) {
                q.push(node);
            }
        }
        
        // Process nodes and build the topological order
        string order;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            order.push_back(node + 'a');
            
            // Decrease in-degree for neighbors; push to queue if it becomes 0
            for(int neighbour : adjacencyList[node]) {
                indegree[neighbour]--;
                if(indegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }
        
        // If the order size doesn't match the unique character count, a cycle exists
        if(order.size() != chars.size()) {
            return "";
        }
        
        return order;
    }
};
