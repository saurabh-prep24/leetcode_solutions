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
    TreeNode* build(vector<vector<int>>& arr) {
        // keep all mp[val] -> nodes
        unordered_map<int, TreeNode*> nodes;
        // store all mp[child] -> parent
        // later can be used for getting parent
        // mp[parent] == 0 then head
        unordered_map<int, int> childToParent;

        int n = arr.size();
        // loop all
        for (int i = 0; i < n; i++) {
            int p = arr[i][0];
            int c = arr[i][1];
            int isLeft = arr[i][2];

            // store child->parent
            childToParent[c] = p;

            // parent node
            TreeNode* parent;
            // create parent
            if (nodes.count(p) == 0) {
                parent = new TreeNode(p);
                nodes[p] = parent;
            } else {
                parent = nodes[p];
            }

            // child node
            TreeNode* child;
            // create child
            if (nodes.count(c) == 0) {
                child = new TreeNode(c);
                nodes[c] = child;
            } else {
                child = nodes[c];
            }

            // attach parent to child with left or right
            if (isLeft) {
                parent->left = child;
            } else {
                parent->right = child;
            }
        }

        TreeNode* head;
        // check all nodes
        // OPT: can use XOR also for parent
        // [XOR all nodes both parent and child -> unique will be head]
        for (auto i : nodes) {
            // find node with no Parent
            if (childToParent[i.first] == 0) {
                // store head for ans
                head = i.second;
            }
        }
        // return head
        return head;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        return build(descriptions);
    }
};