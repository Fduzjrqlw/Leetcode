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


    vector<int> ans1 , ans2 ;

    void dfs(TreeNode* root , vector<int>& ans) {
        if (root == nullptr)
            return ;
        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(root->val) ;
            return ;
        }
        if (root->left != nullptr)
            dfs(root->left , ans) ;
        if (root->right != nullptr)
            dfs(root->right , ans) ;
        return ;
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        dfs(root1 , ans1) ;
        dfs(root2 , ans2) ;
        if (ans1.size() != ans2.size())
            return false ;
        for (int i = 0 ; i < ans1.size() ; ++i) {
            if (ans1[i] != ans2[i]) {
                return false ;
            }
        }
        return true ;
    }
};