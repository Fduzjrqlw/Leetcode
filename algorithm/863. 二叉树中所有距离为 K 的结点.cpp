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

    vector<int> res ;
    unordered_map<int,vector<int>> G ;
    unordered_map<int,bool> vis ;

    void dfs1(TreeNode *root) {
        if (root == nullptr)
            return ;
        if (root->left != nullptr) {
            G[root->val].push_back(root->left->val) ;
            G[root->left->val].push_back(root->val) ;
            dfs1(root->left) ;
        }
        if (root->right != nullptr) {
            G[root->val].push_back(root->right->val) ;
            G[root->right->val].push_back(root->val) ;
            dfs1(root->right) ;
        }
    }

    void dfs2(int u , int K , int d) {
        vis[u] = true ;
        if (d == K) {
            res.push_back(u) ;
            return ;
        }
        for (int i = 0 ; i < G[u].size() ; ++i) {
            if (!vis[G[u][i]]) {
                dfs2(G[u][i] , K , d + 1) ;
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        dfs1(root) ;
        dfs2(target->val , K , 0) ;
        return res ;
    }
};