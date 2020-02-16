/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    int last , res ;

    void dfs(TreeNode *root) {
        if (root->left != NULL) {
            dfs(root->left) ;
        }
        if (res == INT_MIN) {
            last = root->val ;
            res = INT_MAX ;
        } else {
            res = min(res , root->val - last) ;
            last = root->val ;
        }
        if (root->right != NULL) {
            dfs(root->right) ;
        }
        return ;
    }

    int minDiffInBST(TreeNode* root) {
        last = INT_MIN ; res = INT_MIN ;
        dfs(root) ;
        return res ;
    }
};