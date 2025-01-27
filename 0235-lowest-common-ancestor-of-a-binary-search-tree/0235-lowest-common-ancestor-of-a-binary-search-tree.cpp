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
        
        //if p on left and q on right
        if(p->val <= root->val && q->val >= root->val){
            ans = root;
            return;
        }
        //if p on right and q on left
        if(p->val >= root->val && q->val <= root->val){
            ans = root;
            return;
        }


        if(p->val < root->val && q-> val < root->val){
            dfs(root->left, p, q);
        } else {
            dfs(root->right, p, q);
        }


    }
};