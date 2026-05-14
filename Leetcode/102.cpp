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
    void traverse(TreeNode* node, int depth, vector<vector<int>>& levels) {
        if (node == nullptr) {
            return;
        }

        if (levels.size() == depth) {
            levels.push_back({});
        }

        levels[depth].push_back(node->val);

        traverse(node->left, depth + 1, levels);
        traverse(node->right, depth + 1, levels);
    }

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        traverse(root, 0, result);
        return result;
    }
};