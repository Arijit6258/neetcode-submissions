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
    int solve(TreeNode* root, int& maxPathSum) {
        if (root == NULL) return 0;

        int lm = solve(root->left, maxPathSum);
        int rm = solve(root->right, maxPathSum);

        int cm = max (root->val, max(root->val+lm, root->val+rm));

        if (lm > 0 && rm > 0) maxPathSum = max(maxPathSum, root->val+lm+rm);
        else if (lm > 0) maxPathSum = max(maxPathSum, root->val+lm);
        else if (rm > 0) maxPathSum = max(maxPathSum, root->val+rm);
        else maxPathSum = max(maxPathSum, root->val);

        return cm;
    }

    int maxPathSum(TreeNode* root) {
        int maxPathSum = root->val;
        solve(root, maxPathSum);
        return maxPathSum;
    }
};
