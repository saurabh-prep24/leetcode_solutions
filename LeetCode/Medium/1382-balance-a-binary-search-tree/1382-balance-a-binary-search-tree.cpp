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
    void inOrder(TreeNode* root, vector<int>& v) {
        if (!root) {
            return;
        }
        inOrder(root->left, v);
        v.push_back(root->val);
        inOrder(root->right, v);
    }
    TreeNode* buildTree(vector<int>& v, int start, int end) {
        if (start > end)
            return NULL;

        int mid = start + (end - start) / 2;
        // cout << mid << v[mid] << endl;
        TreeNode* root = new TreeNode(v[mid]);
        root->left = buildTree(v, start, mid - 1);
        root->right = buildTree(v, mid + 1, end);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nodes;
        inOrder(root, nodes);
        // sort(nodes.begin(), nodes.end());
        TreeNode* newRoot = buildTree(nodes, 0, nodes.size() - 1);
        return newRoot;
    }
};