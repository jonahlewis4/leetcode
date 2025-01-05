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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = nullptr;
        dfs(root, p->val, q->val, ans);
        return ans;
    }
    int dfs(TreeNode* cur, int p, int q, TreeNode* &ans){
        if(cur == nullptr){
            return 0;
        }

        int finds = 0;
        if(cur->val == p){
            finds++;
        }
        if(cur->val == q){
            finds++;
        }

        int left = dfs(cur->left, p, q, ans);
        int right = dfs(cur->right, p, q, ans);

        if(left + right + finds == 2){
            ans = cur;
            return 0;
        }
        

        return left + right + finds;
    }
};