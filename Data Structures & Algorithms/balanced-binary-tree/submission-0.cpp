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
    int helper(TreeNode* root, bool& balance) {
        if (root == NULL) return 0;
        int lh = helper(root->left, balance);
        int rh = helper(root->right, balance);
        int hd = abs(lh-rh);
        balance &= hd <= 1;
        return max(lh, rh)+1;
    }

    bool isBalanced(TreeNode* root) {
        bool balance = true;
        helper(root, balance);
        return balance;
    }
};
