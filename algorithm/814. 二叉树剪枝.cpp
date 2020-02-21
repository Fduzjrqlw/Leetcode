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
    TreeNode* pruneTree(TreeNode* root) {
        if (root == NULL) {
            return NULL ;
        }
        if (root->left != NULL) {
            root->left = pruneTree(root->left) ;
        }
        if (root->right != NULL) {
            root->right = pruneTree(root->right) ;
        }

        if (root->val == 1 || root->left != NULL || root->right != NULL)
            return root ;
        
        return NULL ;
    }
};