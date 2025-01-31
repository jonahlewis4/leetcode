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
    void dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == nullptr){
            return;
        } 
        int mid = p->val == root->val || q->val == root->val;

        int left = (root->val > p->val || root->val > q->val);
        int right = (root->val < p->val || root->val < q->val);

        if(mid + left + right == 2){
            ans = root;
        } else if (root->val > p->val && root->val > q->val){
            dfs(root->left, p, q);
        } else {
            dfs(root->right, p, q);
        }

    }
};