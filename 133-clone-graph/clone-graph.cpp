/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;

        unordered_map<Node*, Node*> mp;
        Node* clone_node = new Node(node->val);
        mp[node] = clone_node;

        queue<Node*> que;
        que.push(node);

        // bfs
        while(!que.empty()) {
            Node* curr = que.front();
            Node* curr_clone = mp[curr];
            que.pop();

            for(auto it : curr->neighbors) {
                if(mp.find(it) == mp.end()) {
                    Node* clone = new Node(it->val);
                    mp[it] = clone;
                    curr_clone->neighbors.push_back(clone);
                    que.push(it);
                } else {
                    curr_clone->neighbors.push_back(mp[it]);
                }
            }
        }

        return clone_node;
    }
};