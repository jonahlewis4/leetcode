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
    bool isValidBST(TreeNode* root) {
        return dfs(root, (long long) INT_MIN - 1, (long long) INT_MAX + 1);
    }
    bool dfs(TreeNode* root, long long min, long long max){
        if(root == nullptr){
            return true;
        }
        if(root->val <= min || root->val >= max){
            return false;
        }
        return dfs(root->left, min, root->val) && dfs(root->right, root->val, max);
    }
};