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
    int depth(TreeNode* root, int& diameter) {
        int leftD = root->left == NULL ? -1 : depth(root->left, diameter);
        int rightD = root->right == NULL ? -1 : depth(root->right, diameter);
        diameter = max(diameter, leftD+rightD+2);
        return max(leftD, rightD) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        depth(root, diameter);
        return diameter;
    }
};
