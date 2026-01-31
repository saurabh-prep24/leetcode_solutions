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
    void preOrder(TreeNode* root, vector<int>& v) {
        if (!root) {
            return;
        }

        preOrder(root->left, v);
        v.push_back(root->val);
        preOrder(root->right, v);
    }
    int kthSmallest(TreeNode* root, int k) {
        // pre-order of BST is sorted arr
        // Time: O(n)
        // Space: O(n)
        vector<int> v;
        preOrder(root, v);
        if(k>v.size()){
            return -1;
        }
        return v[k - 1];

        // Space can be opt with maxHeap for k elem
        // do any traversal and return heap top elem
        // Time: O(n)
        // Space: O(k)
    }
};