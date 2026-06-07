/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> children;

        // track root node
        TreeNode* rootNode = NULL;

        for(auto it : descriptions) {
            int parent = it[0];
            int child = it[1];
            int isLeft = it[2];

            // create parent and child nodes if not already created
            if(mp.find(parent) == mp.end()) {
                mp[parent] = new TreeNode(parent);
            }

            if(mp.find(child) == mp.end()) {
                mp[child] = new TreeNode(child);
            }

            // attach child node to parent
            if(isLeft) {
                mp[parent]->left = mp[child];
            } else {
                mp[parent]->right = mp[child];
            }

            // mark child as child in the set
            children.insert(child);
        }

        for(auto &[val, node] : mp) {
            if(children.find(val) == children.end()) {
                return node;
            }
        }

        return NULL;

        return rootNode;
    }
};