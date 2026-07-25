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

    // Helper to map each node to its parent
    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
        if (root == nullptr) return;
        
        if (root->left) parent[root->left] = root;
        if (root->right) parent[root->right] = root;
        
        markParent(root->left, parent);
        markParent(root->right, parent);
    }

    // Helper to find the starting node
    TreeNode* find(TreeNode* root, int start) {
        if (root == nullptr) return nullptr;
        if (root->val == start) return root;

        TreeNode* leftSearch = find(root->left, start);
        if (leftSearch != nullptr) return leftSearch;

        return find(root->right, start);
    }

    int amountOfTime(TreeNode* root, int start) {
        
        TreeNode* first = find(root, start);
        unordered_map<TreeNode*, TreeNode*> parent;
        markParent(root, parent);  

        unordered_set<TreeNode*> s;
        s.insert(first);

        queue<pair<TreeNode*, int>> q;
        q.push({first, 0});

        int maxTime = 0;

        // BFS to spread the infection level by level
        while (!q.empty()) {
            pair<TreeNode*, int> p = q.front();
            q.pop();

            TreeNode* temp = p.first;
            int level = p.second;
            maxTime = max(maxTime, level);

            // 1. Visit Left Child
            if (temp->left) {
                if (s.find(temp->left) == s.end()) {
                    q.push({temp->left, level + 1});
                    s.insert(temp->left);
                }
            }

            // 2. Visit Right Child
            if (temp->right) {
                if (s.find(temp->right) == s.end()) {
                    q.push({temp->right, level + 1});
                    s.insert(temp->right);
                }
            }

            // 3. Visit Parent Node
            if (parent.find(temp) != parent.end()) {
                if (s.find(parent[temp]) == s.end()) {
                    q.push({parent[temp], level + 1});
                    s.insert(parent[temp]); // Fixed: insert parent[temp], not temp->right
                }
            }
        }

        return maxTime;
    }
};