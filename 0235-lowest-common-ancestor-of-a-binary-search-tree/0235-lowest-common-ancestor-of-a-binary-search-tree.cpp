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
private:
    TreeNode* ans;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ans = nullptr;
        dfs(root, p, q);
        return ans;

    }
    int dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == nullptr){
            return 0;
        }
        
        int mid = 0;
        if(root->val == p->val || root->val == q->val){
            mid = 1;
        }
        int left = dfs(root->left, p, q);
        int right = dfs(root->right, p, q);
        if(mid + left + right == 2){
            ans = root;
        }
        if(mid + left + right == 1){
            return 1;
        }
        return 0;

    }
};