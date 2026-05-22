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
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> q;
        int d = 0;
        if (root == NULL) return d;
        q.push(root);
        while(q.size() != 0) {
            int qs = q.size();
            while(qs--) {
                TreeNode* next = q.front();
                q.pop();

                if (next->left) q.push(next->left);
                if (next->right) q.push(next->right);
            }
            
            d++;
        }

        return d;
    }
};
