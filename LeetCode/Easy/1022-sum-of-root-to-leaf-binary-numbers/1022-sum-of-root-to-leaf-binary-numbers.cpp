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
    // at each level we can store pair of node and curr sum till that node
    // for each leaf node add sum to ans
    // for adding at each node - left shift 1 place and add node val
    // push to queue for each level
    // time: O(n)
    // space: O(n)
    int levelOrderSolve(TreeNode* root) {
        int ans = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                // front node
                TreeNode* front = q.front().first;
                // curr sum till front node
                int currSum = q.front().second;

                // remove front
                q.pop();

                // cout<<front->val<<" "<<currSum<<endl;

                // if leaf node then add to ans
                if (front->left == NULL && front->right == NULL) {
                    ans += currSum;
                    continue;
                }

                if (front->left) {
                    // add currSum leftshift 1 place and add next node val
                    q.push({front->left, (currSum << 1) + front->left->val});
                }

                if (front->right) {
                    // add currSum leftshift 1 place and add next node val
                    q.push({front->right, (currSum << 1) + front->right->val});
                }
            }
        }
        return ans;
    }

    // can be solve with dfs as well
    // keep curr sum and add node val then call to left and right
    // return left + right to build ans recusively
    // time: O(N)
    // space: O(N)
    int dfsSolve(TreeNode* root, int currSum) {
        // return 0
        if (!root)
            return 0;

        // left shift curr sum and append root val at last dig
        // *** we can also do currSum = 2 * currSum + root->val
        // [left shift mulitply by 2
        // - similar to decimal places we mutiple by 10
        currSum = (currSum << 1) + root->val;

        // return ans for leaf node
        if (!root->left && !root->right) {
            return currSum;
        }

        // return ans
        return dfsSolve(root->left, currSum) + dfsSolve(root->right, currSum);
    }
    int sumRootToLeaf(TreeNode* root) {
        // return levelOrderSolve(root);
        return dfsSolve(root, 0);
    }
};