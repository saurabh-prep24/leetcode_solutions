/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    pair<int, bool> height(TreeNode* root) {
        if (!root)
            return {0, 1};

        auto l = height(root->left);
        if (l.second == 0)
            return {l.first, 0};
        auto r = height(root->right);
        if (r.second == 0) {
            return {r.first, 0};
        }
        bool isBal = 0;
        if (abs(l.first - r.first) <= 1 && l.second && r.second) {
            isBal = 1;
        }
        return {1 + max(l.first, r.first), isBal};
    }

    bool isBalanced(TreeNode* root) {
        return height(root).second;
    }
};