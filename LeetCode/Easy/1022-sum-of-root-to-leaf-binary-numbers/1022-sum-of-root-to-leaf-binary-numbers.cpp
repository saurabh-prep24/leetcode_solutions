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
    int levelOrderSolve(TreeNode* root) {
        int ans = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* front = q.front().first;
                int currSum = q.front().second;
                q.pop();
                // cout<<front->val<<" "<<currSum<<endl;
                if (front->left == NULL && front->right == NULL) {
                    ans += currSum;
                }

                if (front->left) {
                    // cout<<((front->val << 1) + front->left->val)<<" "<<((front->val << 1) | front->left->val)<<endl;
                    q.push({front->left, (currSum << 1) + front->left->val});
                }

                if (front->right) {
                    q.push(
                        {front->right, (currSum << 1) + front->right->val});
                }
            }
        }
        return ans;
    }
    int sumRootToLeaf(TreeNode* root) {
        return levelOrderSolve(root);
    }
};