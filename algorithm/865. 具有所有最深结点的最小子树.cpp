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

    int maxdep , cnt ;
    TreeNode *res ;

    void dfs1(TreeNode* root , int dep) {
        if (root == nullptr)
            return ;
        if (dep > maxdep) {
            maxdep = dep ; 
            cnt = 1 ;
        } else if (dep == maxdep) {
            cnt++ ;
        }
        if (root->left != nullptr)
            dfs1(root->left , dep + 1) ;
        if (root->right != nullptr)
            dfs1(root->right ,dep + 1) ;
        return ;
    }

    int dfs2(TreeNode* root , int dep) {
        if (root == nullptr)
            return 0 ;
        int c = 0 ;
        if (dep == maxdep) {
            ++c ;
        }
        if (root->left != nullptr)
            c += dfs2(root->left , dep + 1) ;
        if (root->right != nullptr)
            c += dfs2(root->right , dep + 1) ;
        if (c == cnt && res == nullptr) {
            res = root ;
        }
        return c ;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        maxdep = 0 ; cnt = 0 ;
        dfs1(root , 1) ;
        dfs2(root , 1) ;
        return res ;
    }
};